#!/usr/bin/env python3
"""Finds the source files that break the ROM, from ONE build, and can drop them.

    python tools/find_culprits.py              # build, then list the culprit files and why
    python tools/find_culprits.py --fix        # drop the culprits that are not committed yet, rebuild, repeat
    python tools/find_culprits.py --fix --any  # may also drop committed files (careful)

A file can match in objdiff and still break the ROM: objdiff masks literal-pool words (a pool in another order),
a `static` function becomes a local symbol, a file can shift everything after it... Instead of bisecting (one full
build per step), this tool compares every rebuilt module (ARM9 main, ITCM, DTCM, overlays) with the original byte by
byte and maps each difference to the `complete` file of delinks.txt that covers it. It also reads the errors of the
build (compile errors, `check symbols`). Dropped files are moved to build/culprits/<date>/ (nothing is deleted).
"""
import argparse
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402

ROOT = project.ROOT
OUT = project.BUILD / "build"
BLOCK_RE = re.compile(r"^(\S+):\n((?:[ \t]+.*\n?)*)", re.M)
SECTION_RE = re.compile(r"\.(\w+)\s+start:0x([0-9a-f]+) end:0x([0-9a-f]+)")


def run(cmd, **kw):
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, encoding="utf-8", errors="replace", **kw)


def base_address(yaml_file: Path, overlay_id: int | None = None) -> int | None:
    if not yaml_file.exists():
        return None
    text = yaml_file.read_text(encoding="utf-8", errors="replace")
    if overlay_id is None:
        m = re.search(r"^base_address:\s*(\d+)", text, re.M)
        return int(m.group(1)) if m else None
    for m in re.finditer(r"-\s*id:\s*(\d+)\s*\n(?:\s+\w+:.*\n)*?\s+base_address:\s*(\d+)", text):
        if int(m.group(1)) == overlay_id:
            return int(m.group(2))
    return None


def modules() -> list[dict]:
    """(name, rebuilt file, original file, base address, delinks.txt) of every module."""
    ex = project.EXTRACT / "arm9"
    mods = [{"name": "ARM9 main", "built": OUT / "arm9.bin", "orig": ex / "arm9.bin",
             "base": base_address(ex / "arm9.yaml"), "delinks": project.ARM9 / "delinks.txt"}]
    for tcm in ("itcm", "dtcm"):
        mods.append({"name": tcm.upper(), "built": OUT / f"{tcm}.bin", "orig": ex / f"{tcm}.bin",
                     "base": base_address(ex / f"{tcm}.yaml"), "delinks": project.ARM9 / tcm / "delinks.txt"})
    ov_dir = project.EXTRACT / "arm9_overlays"
    ov_yaml = next(iter(sorted(ov_dir.glob("*.yaml"))), None) if ov_dir.exists() else None
    for built in sorted(OUT.glob("arm9_ov*.bin")):
        n = int(re.search(r"ov(\d+)", built.name).group(1))
        mods.append({"name": f"overlay {n}", "built": built, "orig": ov_dir / f"ov{n:03d}.bin",
                     "base": base_address(ov_yaml, n) if ov_yaml else None,
                     "delinks": project.ARM9 / "overlays" / f"ov{n:03d}" / "delinks.txt"})
    return [m for m in mods if m["built"].exists() and m["orig"].exists() and m["base"] is not None]


def complete_files(delinks: Path) -> list[tuple[str, int, int]]:
    """[(source file, start, end)] of every section of every `complete` file."""
    if not delinks.exists():
        return []
    out = []
    for m in BLOCK_RE.finditer(delinks.read_text(encoding="utf-8", errors="replace")):
        if "complete" not in m.group(2).split():
            continue
        for _, s, e in SECTION_RE.findall(m.group(2)):
            out.append((m.group(1), int(s, 16), int(e, 16)))
    return out


def diff_ranges(a: bytes, b: bytes) -> tuple[list[tuple[int, int]], bool]:
    """Differing byte runs (offset, length). When the sizes differ only the first difference is meaningful."""
    n = min(len(a), len(b))
    runs = []
    i = 0
    step = 4096
    while i < n:  # skip identical pages fast
        j = min(i + step, n)
        if a[i:j] == b[i:j]:
            i = j
            continue
        for k in range(i, j):
            if a[k] != b[k]:
                if runs and k - (runs[-1][0] + runs[-1][1]) <= 8:
                    runs[-1] = (runs[-1][0], k - runs[-1][0] + 1)
                else:
                    runs.append((k, 1))
        i = j
    shifted = len(a) != len(b)
    if shifted:
        runs = runs[:1] or [(n, 1)]
    return runs, shifted


def build() -> str:
    run([sys.executable, "tools/configure.py", project.VERSION])
    r = run(["ninja"])
    return (r.stdout or "") + (r.stderr or "")


def find(build_output: str) -> list[dict]:
    """Culprits of the current build: [{file, reason}]"""
    found = {}

    def add(f, reason):
        f = f.replace("\\", "/")
        found.setdefault(f, []).append(reason)

    for m in re.finditer(r"^(src[\\/]\S+?\.(?:c|cpp|s)):(\d+):.*error", build_output, re.M | re.I):
        add(m.group(1), f"compile error line {m.group(2)}")
    all_files = [(f, s, e) for mod in modules() for f, s, e in complete_files(mod["delinks"])]
    for m in re.finditer(r"Symbol '(\S+)' at 0x([0-9a-f]+) in (.+?) (is .*)", build_output):
        addr = int(m.group(2), 16)
        for f, s, e in all_files:
            if s <= addr < e:
                add(f, f"symbol {m.group(1)} {m.group(4).strip()}")
    # A module older than the last change of the config was not relinked (the build stopped before): skip it.
    # (When nothing changed, ninja does not rewrite the modules: they are still up to date.)
    newest_config = max((p.stat().st_mtime for p in project.CONFIG.rglob("*.txt")), default=0)
    for f, reason in map_overflows(newest_config):
        add(f, reason)
    for mod, addr, sym in shifted_symbols(build_output):
        add("(no complete file)", f"{mod} shifted from 0x{addr:08x} ({sym}): something placed before it grew")
    for mod in modules():
        if mod["built"].stat().st_mtime < newest_config:
            add("(build)", f"{mod['name']} not relinked since the last config change: fix the build errors first")
            continue
        runs, shifted = diff_ranges(mod["orig"].read_bytes(), mod["built"].read_bytes())
        if not runs:
            continue
        files = complete_files(mod["delinks"])
        for off, ln in runs:
            addr = mod["base"] + off
            owners = [f for f, s, e in files if s <= addr < e or (s < addr + ln and addr < e)]
            if not owners and shifted:  # a shift starts at the end of the file that grew: blame the one before
                before = [x for x in files if x[2] <= addr]
                owners = [max(before, key=lambda x: x[2])[0]] if before else []
            what = "size changed from here" if shifted else f"{ln} byte(s) differ"
            for f in owners:
                add(f, f"{mod['name']} 0x{addr:08x}: {what}")
            if not owners:
                add("(no complete file)", f"{mod['name']} 0x{addr:08x}: {what}")
    return [{"file": f, "reasons": r} for f, r in found.items()]


MAP_LINE = re.compile(r"^\s+[0-9A-Fa-f]{8} ([0-9A-Fa-f]{8}) (\.\w+)\s+\S+\t\((\S+?)\.o\)", re.M)


def map_overflows(newest_config: float) -> list[tuple[str, str]]:
    """[(file, reason)] for the `complete` files whose object brings more than delinks.txt declares, read from the
    linker map: a section it does not declare (a `.bss` from a tentative definition, strings), or a section bigger
    than its range. Such a file moves everything after it, so the byte comparison only sees the shift, not where it
    starts (in this game the first difference is in Entry.c, which holds the module sizes)."""
    xmap = project.BUILD / "arm9.o.xMAP"
    if not xmap.exists() or xmap.stat().st_mtime < newest_config:
        return []
    declared = {}  # object stem -> (file, {section: size})
    for mod in modules():
        delinks = mod["delinks"]
        if not delinks.exists():
            continue
        for m in BLOCK_RE.finditer(delinks.read_text(encoding="utf-8", errors="replace")):
            if "complete" in m.group(2).split():
                secs = {"." + n: int(e, 16) - int(s, 16) for n, s, e in SECTION_RE.findall(m.group(2))}
                declared[Path(m.group(1)).stem] = (m.group(1), secs)
    placed = {}  # object stem -> {section: bytes}
    for size, sec, obj in MAP_LINE.findall(xmap.read_text(encoding="latin-1")):
        if obj in declared and int(size, 16) and not sec.startswith((".debug", ".comment")):
            placed.setdefault(obj, {}).setdefault(sec, 0)
            placed[obj][sec] += int(size, 16)
    out = []
    for obj, secs in placed.items():
        f, want = declared[obj]
        for sec, n in secs.items():
            if sec not in want:
                out.append((f, f"brings 0x{n:x} bytes of {sec} that delinks.txt does not declare"))
            elif n > want[sec]:
                out.append((f, f"{sec} is 0x{n:x} bytes for a 0x{want[sec]:x} range"))
    return out


def shifted_symbols(build_output: str) -> list[tuple[str, int, str]]:
    """[(module, first address, symbol)] of the modules where `dsd check symbols` finds a symbol at another address
    (the whole module moved): helps to tell a file that grew in the module from something placed before it."""
    first = {}
    for m in re.finditer(r"Symbol '(\S+)' in (.+?) at 0x([0-9a-f]+) not found by address", build_output):
        addr = int(m.group(3), 16)
        if m.group(2) not in first or addr < first[m.group(2)][0]:
            first[m.group(2)] = (addr, m.group(1))
    return [(mod, a, s) for mod, (a, s) in sorted(first.items())]


def committed_files() -> set[str]:
    out = set()
    for p in project.CONFIG.rglob("delinks.txt"):
        rel = p.relative_to(ROOT).as_posix()
        r = run(["git", "show", f"HEAD:{rel}"])
        if r.returncode == 0:
            out |= {m.group(1) for m in BLOCK_RE.finditer(r.stdout)}
    return out


def drop(files: list[str], dest: Path) -> None:
    """Removes the files from every delinks.txt and compilers.txt, moves the sources to `dest`."""
    dest.mkdir(parents=True, exist_ok=True)
    for p in project.CONFIG.rglob("delinks.txt"):
        text = p.read_text(encoding="utf-8")
        new = text
        for f in files:
            new = re.sub(r"\n?^" + re.escape(f) + r":\n(?:[ \t]+.*\n?)*", "\n", new, flags=re.M)
        if new != text:
            p.write_text(re.sub(r"\n{3,}", "\n\n", new), encoding="utf-8", newline="\n")
    if project.COMPILERS_TXT.exists():
        keep = [l for l in project.COMPILERS_TXT.read_text(encoding="utf-8").splitlines(True) if l.split(" ")[0] not in files]
        project.COMPILERS_TXT.write_text("".join(keep), encoding="utf-8", newline="\n")
    for f in files:
        src = ROOT / f
        if src.exists():
            target = dest / f
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.move(str(src), str(target))


def rom_ok(build_output: str) -> bool:
    return f"{project.ROM_NAME}: OK" in build_output


def repair(allowed: set[str] | None = None, rounds: int = 10, log=print) -> tuple[bool, list[str]]:
    """Build, drop the culprits (only those in `allowed`, if given), repeat. Returns (ROM OK, dropped files)."""
    dest = project.BUILD.parent / "culprits" / time.strftime("%Y%m%d-%H%M%S")
    dropped = []
    for i in range(rounds):
        t0 = time.time()
        out = build()
        if rom_ok(out):
            return True, dropped
        culprits = find(out)
        files = [c["file"] for c in culprits if c["file"].startswith("src/")]
        for c in culprits:
            log(f"  {c['file']}: {'; '.join(c['reasons'][:3])}")
        blocked = [f for f in files if allowed is not None and f not in allowed]
        files = [f for f in files if f not in blocked]
        if blocked:
            log(f"  not dropped (already committed, use --any): {', '.join(blocked)}")
        if not files:
            log("  no droppable culprit found: stopping")
            return False, dropped
        log(f"round {i + 1}: dropping {len(files)} file(s) -> {dest.relative_to(ROOT).as_posix()}")
        drop(files, dest)
        dropped += files
    return rom_ok(build()), dropped


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--fix", action="store_true", help="drop the culprits and rebuild until the ROM matches")
    ap.add_argument("--any", action="store_true", help="also drop files that are already committed")
    ap.add_argument("--rounds", type=int, default=10)
    a = ap.parse_args()
    if not a.fix:
        t0 = time.time()
        out = build()
        if rom_ok(out):
            print(f"ROM OK ({project.ROM_NAME}): nothing to find.")
            return
        culprits = find(out)
        if not culprits:
            print("The ROM does not match but no difference could be attributed (see `ninja` output).")
            sys.exit(1)
        for c in culprits:
            print(f"{c['file']}: {'; '.join(c['reasons'][:5])}")
        sys.exit(1)
    ok, dropped = repair(None if a.any else {f for f in all_new_files()}, a.rounds)
    print(f"dropped {len(dropped)} file(s): {', '.join(dropped) or '-'}")
    print("ROM OK: run `python tools/match.py verify` before committing." if ok else "ROM still differs.")
    sys.exit(0 if ok else 1)


def all_new_files() -> set[str]:
    """Files declared in delinks.txt now but not in the last commit."""
    now = set()
    for p in project.CONFIG.rglob("delinks.txt"):
        now |= {m.group(1) for m in BLOCK_RE.finditer(p.read_text(encoding="utf-8"))}
    return now - committed_files()


if __name__ == "__main__":
    from pipeline_lock import pipeline_lock

    with pipeline_lock("find_culprits"):
        main()
