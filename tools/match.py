#!/usr/bin/env python3
"""Decompilation helper: progress, worklist, single-function checks and a strict verifier.

    python tools/match.py status              # overall progress and per-file progress
    python tools/match.py worklist [-n 20]    # unmatched functions in delinked files, smallest first
    python tools/match.py check FUNCTION      # rebuild, print the function's match % (and diff with --diff)
    python tools/match.py verify              # strict gate: ROM OK, complete files at 100%, ASCII sources
    python tools/match.py progress            # rewrite the progress table in README.md

`verify` exits with a non-zero code on any failure. Automated sessions must not commit unless it passes.
"""

import argparse
import json
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402  (this game's version, ROM name, paths: tools/project.py)
REPORT = project.REPORT
SYMBOLS = project.SYMBOLS
README = ROOT / "README.md"
SOURCE_DIRS = ["src", "include", "tools/probes"]

# Source files named by assertion strings in the game binary
KNOWN_FILES = ["3dData.c", "Brain.c", "CollSet.c", "Culling.c", "Dynam.c", "HieMtStk.c", "Inters.c", "MSSound.c",
               "MSWay.c", "MS_Micro.c", "MSlight.c", "PlayAnim.c", "SectInfo.c", "Sndldbin.c", "StdGame.c", "U_vpt.c",
               "cineinfo.c"]


def run(cmd: list[str], quiet: bool = True) -> subprocess.CompletedProcess:
    return subprocess.run(cmd, cwd=ROOT, capture_output=quiet, text=True)


def build_report() -> dict:
    r = run(["ninja", "report"])
    if r.returncode != 0:
        print(r.stdout[-3000:], r.stderr[-3000:], sep="\n")
        raise SystemExit("ninja report failed (compile error?)")
    return json.loads(REPORT.read_text())


def load_report(rebuild: bool) -> dict:
    if rebuild or not REPORT.exists():
        return build_report()
    return json.loads(REPORT.read_text())


def source_units(report: dict) -> list[dict]:
    return [u for u in report["units"] if not u.get("metadata", {}).get("auto_generated")]


def pct(m: dict, key: str) -> float:
    return float(m.get(key, 0) or 0)


def cmd_status(args):
    report = load_report(args.rebuild)
    m = report["measures"]
    print(f"Code      : {pct(m, 'matched_code_percent'):6.2f}%  ({m.get('matched_code', 0)}/{m['total_code']} bytes)")
    print(f"Data      : {pct(m, 'matched_data_percent'):6.2f}%  ({m.get('matched_data', 0)}/{m['total_data']} bytes)")
    print(f"Functions : {m.get('matched_functions', 0)}/{m['total_functions']}")
    print(f"Files     : {m.get('complete_units', 0)} complete\n")
    for u in source_units(report):
        um = u["measures"]
        state = "complete" if u["metadata"].get("complete") else "in progress"
        print(f"  {u['metadata'].get('source_path', u['name']):32} {pct(um, 'matched_code_percent'):6.2f}% code  "
              f"{um.get('matched_functions', 0)}/{um.get('total_functions', 0)} functions  [{state}]")


def cmd_worklist(args):
    report = load_report(args.rebuild)
    todo = []
    for u in source_units(report):
        for f in u.get("functions", []):
            if float(f.get("fuzzy_match_percent", 0)) < 100.0:
                todo.append((int(f["size"]), f["name"], u["metadata"].get("source_path", u["name"]),
                             float(f.get("fuzzy_match_percent", 0))))
    todo.sort()
    if todo:
        print("Unmatched functions in delinked files (smallest first):")
        for size, name, path, p in todo[:args.n]:
            print(f"  {name:40} {size:6} bytes  {p:6.2f}%  {path}")
    else:
        print("Every function in delinked files matches.")
    delinked = {Path(u["metadata"].get("source_path", "")).name for u in source_units(report)}
    remaining = [f for f in KNOWN_FILES if f not in delinked]
    if remaining:
        print("\nKnown source files not delinked yet (see docs/decompiling.md):")
        print("  " + ", ".join(remaining))


def find_function(report: dict, name: str):
    for u in source_units(report):
        for f in u.get("functions", []):
            if f["name"] == name:
                return u, f
    return None, None


def symbol_address(name: str) -> int | None:
    for line in SYMBOLS.read_text().splitlines():
        if line.split(" ", 1)[0] == name:
            mm = re.search(r"addr:0x([0-9a-fA-F]+)", line)
            return int(mm.group(1), 16) if mm else None
    return None


def cmd_check(args):
    report = build_report()
    unit, func = find_function(report, args.function)
    if func is None:
        raise SystemExit(f"{args.function} is not in a delinked source file (check delinks.txt and symbols.txt)")
    p = float(func.get("fuzzy_match_percent", 0))
    src = unit["metadata"].get("source_path")
    print(f"{args.function}: {'MATCH' if p == 100.0 else f'{p:.2f}%'}  ({func['size']} bytes, {src})")
    if args.diff and p < 100.0:
        addr = symbol_address(args.function)
        if addr is None:
            raise SystemExit("address not found in symbols.txt")
        run([sys.executable, "tools/probe_compiler.py", src, args.function, hex(addr), "--only", "2.0/sp1p5",
             "--flags=-O4,p", "--show"], quiet=False)
    sys.exit(0 if p == 100.0 else 1)


def non_ascii_files() -> list[str]:
    bad = []
    for d in SOURCE_DIRS:
        for f in (ROOT / d).rglob("*"):
            if f.suffix in (".c", ".h") and any(b > 0x7F for b in f.read_bytes()):
                bad.append(str(f.relative_to(ROOT)))
    return bad


def cmd_verify(args):
    ok = True
    r = run(["ninja"])
    out = (r.stdout or "") + (r.stderr or "")
    if r.returncode != 0 or f"{project.ROM_NAME}: OK" not in out:
        print(out[-4000:])
        print("FAIL: ninja did not produce a matching ROM")
        ok = False
    else:
        print(f"OK  : ROM is byte-identical ({project.ROM_NAME}: OK)")
    report = build_report()
    for u in source_units(report):
        if u["metadata"].get("complete"):
            for s in u.get("sections", []):
                if float(s.get("fuzzy_match_percent", 0)) < 100.0:
                    print(f"FAIL: {u['metadata'].get('source_path')} is marked complete but {s['name']} is "
                          f"{float(s.get('fuzzy_match_percent', 0)):.2f}%")
                    ok = False
    bad = non_ascii_files()
    if bad:
        print("FAIL: non-ASCII characters in " + ", ".join(bad))
        ok = False
    m = report["measures"]
    print(f"INFO: {m.get('matched_functions', 0)}/{m['total_functions']} functions, "
          f"{pct(m, 'matched_code_percent'):.2f}% code")
    print("VERIFY PASSED" if ok else "VERIFY FAILED")
    sys.exit(0 if ok else 1)


PARTS = [  # (path prefix, label) of the progress table, first match wins
    ("src/nitro/", "NitroSDK (Nintendo's system library)"),
    ("src/nnsys/", "NitroSystem (Nintendo's middleware)"),
    ("src/wifi/", "NitroWiFi"),
    ("src/dwc/", "NitroDWC (Wi-Fi Connection)"),
    ("src/vct/", "libvct"),
    ("src/msl/", "MSL (C standard library)"),
    ("src/lib/", "Other libraries"),
    ("src/donor/", "Reused from other decompilations, not merged into files yet"),
    ("src/auto/", "Auto-matched (raw m2c output, to clean up)"),
]
STUDIO_URL = "https://github.com/liolu/ds-decomp-studio"


def bar(percent: float, width: int = 20) -> str:
    full = round(percent / 100 * width)
    return "`" + "█" * full + "░" * (width - full) + "`"


def part_of(path: str) -> str:
    for prefix, label in PARTS:
        if path.startswith(prefix):
            return label
    parts = path.split("/")
    return f"Game code: `{'/'.join(parts[:2])}/`" if len(parts) > 2 else "Game code"


def cmd_progress(args):
    """Writes the progress section of README.md (created after the introduction when missing)."""
    import datetime
    report = load_report(args.rebuild)
    m = report["measures"]
    code, data = pct(m, "matched_code_percent"), pct(m, "matched_data_percent")
    parts = {}
    for u in source_units(report):
        path = u["metadata"].get("source_path", u["name"])
        um = u["measures"]
        row = parts.setdefault(part_of(path), [0, 0, 0, 0])
        row[0] += 1
        row[1] += int(um.get("matched_functions", 0))
        row[2] += int(um.get("total_functions", 0))
        row[3] += int(um.get("matched_code", 0) or 0)
    total_code = int(m.get("total_code", 0) or 0)
    lines = ["<!-- progress:start -->",
             f"{bar(code)} **{code:.2f}%** of the code matched · data {data:.2f}% · "
             f"{m.get('matched_functions', 0)}/{m['total_functions']} functions",
             "",
             "| Part of the code | Files | Functions | Share of all code |",
             "|---|---|---|---|"]
    for label, (files, done, total, matched) in sorted(parts.items(), key=lambda kv: -kv[1][3]):
        share = 100 * matched / total_code if total_code else 0
        lines.append(f"| {label} | {files} | {done}/{total} | {share:.2f}% |")
    lines += ["",
              f"*Updated {datetime.date.today().isoformat()} by `python tools/match.py progress` "
              f"([DS Decomp Studio]({STUDIO_URL})). A function counts only when it compiles to the exact same bytes "
              f"and the ROM still rebuilds byte for byte.*",
              "<!-- progress:end -->"]
    block = "\n".join(lines)
    text = README.read_text(encoding="utf-8")
    if "<!-- progress:start -->" in text:
        new = re.sub(r"<!-- progress:start -->.*?<!-- progress:end -->", lambda _m: block, text, flags=re.S)
    else:
        # after the introduction: before the first code block or second-level title
        mm = re.search(r"^(```|## )", text, re.M)
        at = mm.start() if mm else len(text)
        new = text[:at].rstrip("\n") + "\n\n## Progress\n\n" + block + "\n\n" + text[at:]
    README.write_text(new, encoding="utf-8", newline="\n")
    print(f"README.md progress updated: {code:.2f}% code, {m.get('matched_functions', 0)}/{m['total_functions']} functions")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    for name, fn in [("status", cmd_status), ("worklist", cmd_worklist), ("progress", cmd_progress)]:
        p = sub.add_parser(name)
        p.add_argument("--rebuild", action="store_true", help="Run ninja report first")
        p.set_defaults(fn=fn)
    sub.choices["worklist"].add_argument("-n", type=int, default=20)
    p = sub.add_parser("check")
    p.add_argument("function")
    p.add_argument("--diff", action="store_true", help="Show target/candidate disassembly when not matching")
    p.set_defaults(fn=cmd_check)
    p = sub.add_parser("verify")
    p.set_defaults(fn=cmd_verify)
    args = ap.parse_args()
    if args.cmd == "verify":
        # A run of auto_match / donor_match killed while integrating left unverified files: undo that first
        # (nothing happens while a pipeline is running: it is the one calling verify)
        from pipeline_lock import recover
        recover()
    args.fn(args)


if __name__ == "__main__":
    main()
