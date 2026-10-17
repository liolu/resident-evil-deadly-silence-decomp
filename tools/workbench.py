#!/usr/bin/env python3
"""Workbench: one function (or one piece of data) at a time, for agents (the studio's MCP server) and the studio's
C editor. Every command prints one JSON object.

    python tools/workbench.py info NAME                  # address, size, assembly, draft, calls, data, callers
    python tools/workbench.py judge NAME FILE.c [--profile "1.2/sp2p3"]   # compile + compare, the diff
    python tools/workbench.py submit NAME FILE.c [--who W]  # judge, then into src/auto + ROM rebuilt (kept if OK)
    python tools/workbench.py commit [--push]            # match.py verify once for every submitted match, commit
    python tools/workbench.py pending                    # submitted matches waiting for `commit`
    python tools/workbench.py data NAME|0xADDR           # bytes of a data symbol, decoded, + a C declaration
    python tools/workbench.py datacheck FILE.c           # compile, compare every data symbol it defines with the ROM
    python tools/workbench.py header include/engine.h NEW.h   # replace a shared header, kept only if the ROM matches
    python tools/workbench.py splits                     # functions dsd probably merged (called in their middle)
    python tools/workbench.py split NAME 0xADDR          # cut NAME at ADDR in symbols.txt, kept only if the ROM matches

Matches are judged like auto_match does (bl targets and literal pool words masked), with the fake-match gate
(fakematch.py): asm, preprocessor tricks and sections are refused unless the target is assembly-only code.
`submit` is quick (one ninja build: the ROM must stay byte-identical); the full `match.py verify` (objdiff on every
file, minutes on a big game) runs once for all submitted matches in `commit`, which drops the files it rejects.
Only ARM functions of the main module are handled, like auto_match.
"""
import argparse
import bisect
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402
import probe_compiler as pc  # noqa: E402
import auto_match as am  # noqa: E402
from fakematch import fake_match  # noqa: E402
from pipeline_lock import journal_begin, journal_created, journal_end, pipeline_lock  # noqa: E402

WORK = ROOT / "build" / "workbench"
PENDING = WORK / "pending.json"
RELOCS = project.ARM9 / "relocs.txt" if hasattr(project, "ARM9") else project.SYMBOLS.parent / "relocs.txt"

# ---------------------------------------------------------------- overlays: every command works on the module (main or
# overlay) that holds the function; select_module() rebinds the per-module paths of project/auto_match/probe_compiler
OVL_DIR = project.ARM9 / "overlays"
_OVL_INDEX = None
MODULE = "main"


def overlay_index() -> dict[str, int]:
    """{symbol name: overlay id} for every overlay (names are unique: func_ovNNN_..., data_ovNNN_...)."""
    global _OVL_INDEX
    if _OVL_INDEX is None:
        _OVL_INDEX = {}
        for d in sorted(OVL_DIR.glob("ov*")) if OVL_DIR.exists() else []:
            f = d / "symbols.txt"
            if f.exists():
                for m in re.finditer(r"^(\S+) kind:", f.read_text(encoding="utf-8", errors="replace"), re.M):
                    _OVL_INDEX.setdefault(m.group(1), int(d.name[2:]))
        f = project.ARM9 / "itcm" / "symbols.txt"  # the ITCM module is handled like an overlay (id -1)
        if f.exists():
            for m in re.finditer(r"^(\S+) kind:", f.read_text(encoding="utf-8", errors="replace"), re.M):
                _OVL_INDEX.setdefault(m.group(1), -1)
    return _OVL_INDEX


def select_module(target: str) -> str:
    """Points the tools at the module of `target` (a symbol name or 0xADDR of an overlay function)."""
    global RELOCS, _SYMS, _RELOCS, MODULE
    ov = overlay_index().get(target) if not target.startswith("0x") else None
    if ov is None:
        return "main"
    d = project.ARM9 / "itcm" if ov < 0 else OVL_DIR / f"ov{ov:03d}"
    head = (d / "delinks.txt").read_text(encoding="utf-8").split("\n\n", 1)[0]
    m = re.search(r"\.text\s+start:0x([0-9a-f]+) end:0x([0-9a-f]+)", head)
    first = re.search(r"start:0x([0-9a-f]+)", head)
    text = (int(m.group(1), 16), int(m.group(2), 16))
    project.SYMBOLS, project.DELINKS = d / "symbols.txt", d / "delinks.txt"
    am.SYMBOLS, am.DELINKS, pc.SYMBOLS = project.SYMBOLS, project.DELINKS, project.SYMBOLS
    am.MAIN_TEXT = text
    pc.ARM9_BIN = (project.EXTRACT / "arm9" / "itcm.bin" if ov < 0
                   else project.EXTRACT / "arm9_overlays" / f"ov{ov:03d}.bin")
    pc.ARM9_BASE = int(first.group(1), 16)
    RELOCS = d / "relocs.txt"
    _SYMS = _RELOCS = None
    MODULE = "itcm" if ov < 0 else f"ov{ov:03d}"
    return MODULE


def _profile_rec(name):
    """(start, end) of the `.data` name record of a -profile function (see tools/profnames.py), else None."""
    global _PROFREC
    if _PROFREC is None:
        f = ROOT / "build" / "profnames.json"
        _PROFREC = json.loads(f.read_text(encoding="utf-8")) if f.exists() else {}
    v = _PROFREC.get(name)
    return tuple(v["rec"]) if v else None


_PROFREC = None
am.PROFILE_REC = _profile_rec


def all_delinks() -> list[Path]:
    return [project.ARM9 / "delinks.txt", project.ARM9 / "itcm" / "delinks.txt"] + sorted(OVL_DIR.glob("ov*/delinks.txt"))


STD_HEAD = '#include "m2c.h"\n#include "engine.h"\n#include "m2c_protos.h"\n'


def out(obj) -> None:
    sys.stdout.write(json.dumps(obj, ensure_ascii=True) + "\n")


def run(cmd, timeout=None):
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, encoding="utf-8", errors="replace",
                          timeout=timeout)


# ---------------------------------------------------------------- symbols, sections, relocations of the main module

SYM = re.compile(r"^(\S+) kind:(function|data|bss|label)(?:\(([^)]*)\))? addr:0x([0-9a-f]+)")
SECTION = re.compile(r"^\s+(\.\w+)\s+start:0x([0-9a-f]+) end:0x([0-9a-f]+) kind:(\w+)")
_SYMS = None


def symbols() -> list[dict]:
    """Every symbol of the main module, sorted by address: {name, kind, addr, size (functions), mode}."""
    global _SYMS
    if _SYMS is None:
        _SYMS = []
        for line in project.SYMBOLS.read_text(encoding="utf-8", errors="replace").splitlines():
            m = SYM.match(line)
            if not m:
                continue
            name, kind, extra, addr = m.group(1), m.group(2), m.group(3) or "", int(m.group(4), 16)
            size = re.search(r"size=0x([0-9a-f]+)", extra)
            _SYMS.append({"name": name, "kind": kind, "addr": addr, "size": int(size.group(1), 16) if size else None,
                          "mode": "thumb" if "thumb" in extra else "arm"})
        _SYMS.sort(key=lambda s: s["addr"])
    return _SYMS


def sections() -> list[dict]:
    """The main module's sections (the header of delinks.txt)."""
    head = project.DELINKS.read_text(encoding="utf-8").split("\n\n", 1)[0]
    return [{"name": m.group(1), "start": int(m.group(2), 16), "end": int(m.group(3), 16), "kind": m.group(4)}
            for m in map(SECTION.match, head.splitlines()) if m]


def section_of(addr: int) -> dict | None:
    return next((s for s in sections() if s["start"] <= addr < s["end"]), None)


def find(name_or_addr: str) -> dict | None:
    if re.fullmatch(r"0x[0-9a-fA-F]+", name_or_addr):
        a = int(name_or_addr, 16)
        return next((s for s in symbols() if s["addr"] == a), None)
    return next((s for s in symbols() if s["name"] == name_or_addr), None)


def size_of(sym: dict) -> int:
    """Functions: their size. Data: up to the next symbol (or the end of the section)."""
    if sym["size"]:
        return sym["size"]
    sec = section_of(sym["addr"])
    end = sec["end"] if sec else sym["addr"] + 4
    later = [s["addr"] for s in symbols() if sym["addr"] < s["addr"] < end and s["kind"] != "label"]
    return (min(later) if later else end) - sym["addr"]


def containing(addr: int) -> tuple[dict, int] | None:
    """(symbol, offset) of the symbol that holds `addr` (functions by size, data up to the next symbol)."""
    syms = [s for s in symbols() if s["kind"] != "label"]
    keys = [s["addr"] for s in syms]
    i = bisect.bisect_right(keys, addr) - 1
    if i < 0:
        return None
    s = syms[i]
    return (s, addr - s["addr"]) if addr < s["addr"] + size_of(s) else None


_RELOCS = None


def relocs() -> list[tuple[int, str, int, str]]:
    """(from, kind, to, module) of the main module."""
    global _RELOCS
    if _RELOCS is None:
        _RELOCS = []
        if RELOCS.exists():
            for m in re.finditer(r"^from:0x([0-9a-f]+) kind:(\w+) to:0x([0-9a-f]+) module:(\S+)",
                                 RELOCS.read_text(encoding="utf-8"), re.M):
                _RELOCS.append((int(m.group(1), 16), m.group(2), int(m.group(3), 16), m.group(4)))
        _RELOCS.sort()
    return _RELOCS


def relocs_in(start: int, end: int) -> list[tuple[int, str, int, str]]:
    r = relocs()
    i = bisect.bisect_left(r, (start,))
    j = bisect.bisect_left(r, (end,))
    return r[i:j]


_OTHER = {}


def other_module_symbol(addr: int, module: str) -> str | None:
    """Name of the symbol at `addr` in another module (main, overlay(N), overlays(N,M)...), if it has one."""
    if module == "main":
        f = project.ARM9 / "symbols.txt"
    else:
        m = re.match(r"overlays?\((\d+)", module)
        if not m:
            return None
        f = OVL_DIR / f"ov{int(m.group(1)):03d}" / "symbols.txt"
    if f not in _OTHER:
        d = {}
        for line in f.read_text(encoding="utf-8", errors="replace").splitlines():
            mm = SYM.match(line)
            if mm and mm.group(2) != "label":
                d[int(mm.group(4), 16)] = mm.group(1)
        _OTHER[f] = d
    return _OTHER[f].get(addr)


def name_at(addr: int, module: str = "main") -> str:
    own = MODULE if MODULE in ("main", "itcm") else f"overlay({int(MODULE[2:])})"
    if module != own:
        return other_module_symbol(addr, module) or f"0x{addr:08x} ({module})"
    c = containing(addr)
    if not c:
        return f"0x{addr:08x}"
    s, off = c
    return s["name"] if off == 0 else f"{s['name']}+0x{off:x}"


def covered(addr: int) -> str | None:
    """The source file that holds `addr` in delinks.txt, if any."""
    text = project.DELINKS.read_text(encoding="utf-8")
    for m in re.finditer(r"^(\S+):\n((?:[ \t]+.*\n?)+)", text, re.M):
        for s in re.finditer(r"start:0x([0-9a-f]+) end:0x([0-9a-f]+)", m.group(2)):
            if int(s.group(1), 16) <= addr < int(s.group(2), 16):
                return m.group(1)
    return None


def function(name: str) -> dict:
    s = find(name)
    if s is None or s["kind"] != "function":
        raise SystemExit(json.dumps({"error": f"{name}: no such function in the main module"}))
    return s


# ---------------------------------------------------------------- one function

def starting_draft(name: str) -> tuple[str | None, str]:
    """(C file, where it comes from): the matched file, Qwen's best try, a near miss, an m2c draft (made if
    needed)."""
    mem = ROOT / "build" / "qwen_auto" / "memory" / f"{name}.json"
    if mem.exists():
        try:
            best = json.loads(mem.read_text(encoding="utf-8")).get("best")
            if best:
                return best, "build/qwen_auto/memory (best try so far)"
        except ValueError:
            pass
    for p in (ROOT / "build" / "auto" / "near" / f"{name}.c", ROOT / "build" / "drafts" / f"{name}.c",
              ROOT / "build" / "ghidra" / f"{name}.c"):
        if p.exists():
            text = p.read_text(encoding="utf-8", errors="replace")
            if "m2c failed" not in text[:300]:
                return text, p.relative_to(ROOT).as_posix()
    asm = am.function_asm(name)
    if asm is None:
        return None, "no assembly (run `ninja dis`)"
    with tempfile.TemporaryDirectory() as tmp:
        (Path(tmp) / "f.s").write_text(asm + "\n", encoding="utf-8")
        r = am.run_limited([sys.executable, str(am.M2C), "-t", "arm-mwcc-c", "--valid-syntax", str(Path(tmp) / "f.s")])
    if r.returncode != 0 or not r.stdout.strip():
        return None, "m2c failed: " + (r.stderr or "").strip()[-300:]
    src = '#include "m2c.h"\n\n' + r.stdout
    d = ROOT / "build" / "drafts"
    d.mkdir(parents=True, exist_ok=True)
    (d / f"{name}.c").write_text(src, encoding="utf-8", newline="\n")
    return src, "m2c (new draft)"


def prototypes(names: list[str]) -> list[str]:
    text = "\n".join(p.read_text(encoding="utf-8", errors="replace")
                     for p in (ROOT / "include" / "engine.h", ROOT / "include" / "m2c_protos.h") if p.exists())
    found = []
    for n in names:
        m = re.search(rf"^[^#/\n][^\n;]*\b{re.escape(n)}\s*\([^;]*\);", text, re.M)
        if m:
            found.append(m.group(0).strip())
    return found


def cmd_info(a) -> None:
    f = function(a.name)
    size = f["size"]
    calls, data = [], []
    for frm, kind, to, mod in relocs_in(f["addr"], f["addr"] + size):
        target = name_at(to, mod)
        if kind.startswith("arm_call") or kind == "arm_branch":
            if target not in calls:
                calls.append(target)
        elif kind == "load" and target not in data and not (f["addr"] <= to < f["addr"] + size):
            data.append(target)
    callers = []
    for frm, kind, to, _mod in relocs():
        if to == f["addr"] and kind.startswith(("arm_call", "arm_branch")):
            c = containing(frm)
            n = c[0]["name"] if c else f"0x{frm:08x}"
            if n not in callers:
                callers.append(n)
    src_file = covered(f["addr"])
    if src_file:
        draft, origin = (ROOT / src_file).read_text(encoding="utf-8", errors="replace"), src_file + " (matched)"
    else:
        draft, origin = starting_draft(a.name)
    out({"name": f["name"], "addr": f"0x{f['addr']:08x}", "size": size, "mode": f["mode"],
         "matched": bool(src_file), "file": src_file, "auto_tools": f["mode"] == "arm",
         "profiles": ([f"{v} {e} -thumb".replace("  ", " ") for v, e in am.COMPILERS] if f["mode"] == "thumb" else [f"{v} {e}".strip() for v, e in am.profiles_for(f["name"], size, f["addr"])]),
         "asm_only": bool(am.ASM_ONLY.search(am.function_asm(f["name"]) or "")),
         "asm": am.function_asm(f["name"]) or "", "draft": draft or "", "draft_from": origin,
         "lines": pc.disasm(pc.target_bytes(f["addr"], size), f["addr"]),  # objdump text: look-alike search
         "ghidra": gh.read_text(encoding="utf-8", errors="replace") if (gh := ROOT / "build" / "ghidra" /
                                                                         f"{a.name}.c").exists() else "",
         "calls": calls, "data": data, "callers": callers[:30], "prototypes": prototypes(calls)})


def compact_diff(target: list[str], cand: list[str], context: int = 4, limit: int = 90) -> str:
    n = max(len(target), len(cand))
    rows = [(target[i] if i < len(target) else "", cand[i] if i < len(cand) else "") for i in range(n)]
    norm = lambda s: re.sub(r"0x[0-9a-f]{6,}", "X", s.strip())  # noqa: E731
    bad = [i for i, (x, y) in enumerate(rows) if norm(x) != norm(y)]
    if not bad:
        return "(identical)"
    keep = sorted({j for i in bad for j in range(max(0, i - context), min(n, i + context + 1))})
    lines, last = [f"     {'TARGET':38} | CANDIDATE"], -1
    for j in keep:
        if j != last + 1:
            lines.append("     ...")
        lines.append(f"{j:3} {'*' if j in bad else ' '} {rows[j][0]:38} | {rows[j][1]}")
        last = j
    if last < n - 1:
        lines.append("     ...")
    if len(lines) > limit:
        lines = lines[:limit] + [f"     ... ({len(bad)} differing lines in all)"]
    return "\n".join(lines)


def compile_one(source: str, profile: str) -> tuple[bytes | None, str, Path | None, tempfile.TemporaryDirectory]:
    """(object bytes of the whole .o, compiler messages, object path, temp dir to keep alive)."""
    version, _, extra = profile.partition(" ")
    mwcc = am.MWCC_ROOT / version / "mwccarm.exe"
    tmp = tempfile.TemporaryDirectory()
    t = Path(tmp.name)
    (t / "f.c").write_text(source, encoding="utf-8", newline="\n")
    r = am.run_limited(f'"{mwcc}" -O4,p {pc.BASE_FLAGS} {extra} -i "{ROOT / "include"}" -c f.c -o f.o', cwd=t,
                       shell=True)
    msg = ((r.stdout or "") + (r.stderr or "")).strip()
    obj = t / "f.o"
    return (obj.read_bytes() if obj.exists() and r.returncode == 0 else None), msg, (obj if obj.exists() else None), tmp


def judge(name: str, source: str, profile: str | None = None) -> dict:
    f = function(name)
    size, addr = f["size"], f["addr"]
    asm = am.function_asm(name) or ""
    if not am.ASM_ONLY.search(asm):
        # what the starting files already had is allowed: the near miss, the matched file (an asm function a donor
        # brought, e.g. a stm loop)
        base = ""
        for p in (ROOT / "build" / "auto" / "near" / f"{name}.c", ROOT / (covered(addr) or "-")):
            if p.is_file():
                base += p.read_text(encoding="utf-8", errors="replace") + "\n"
        why = fake_match(source, base + "\n" + STD_HEAD + f"#define M2C_SELF_{name}\n")
        if why:
            return {"status": "refused", "match": False, "why": f"fake match: {why}. Write plain C only."}
    thumb = f["mode"] == "thumb"
    if thumb:
        profiles = [profile] if profile else [f"{v} {e} -thumb".replace("  ", " ") for v, e in am.COMPILERS]
    else:
        profiles = [profile] if profile else [f"{v} {e}".strip() for v, e in am.profiles_for(name, size, addr)]
    target = pc.target_bytes(addr, size)
    best = None
    for prof in profiles:
        objbytes, msg, obj, tmp = compile_one(source, prof)
        try:
            if objbytes is None:
                r = {"status": "compile", "match": False, "profile": prof, "errors": msg[-3000:]}
            else:
                cand = pc.compiled_function(obj, name)
                if cand is None:
                    r = {"status": "compile", "match": False, "profile": prof,
                         "errors": f"{name} is not in the object (renamed? static?)"}
                else:
                    bad, n = pc.compare_thumb(target, cand, addr) if thumb else pc.compare(target, cand)
                    st = "match" if bad == 0 else ("near" if len(cand) == size else "size")
                    r = {"status": st, "match": bad == 0, "profile": prof, "diffs": bad, "total": n,
                         "size": len(cand), "target_size": size}
                    if bad:
                        r["diff"] = compact_diff(pc.disasm(target, addr, thumb), pc.disasm(cand, addr, thumb))
                        if os.environ.get("WB_FULL"):  # both listings, for tools/mdiff.py (structural diff)
                            r["full"] = {"t": pc.disasm(target, addr, thumb), "c": pc.disasm(cand, addr, thumb)}
        finally:
            tmp.cleanup()
        rank = lambda x: ({"match": 0, "near": 1, "size": 2, "compile": 3}[x["status"]], x.get("diffs", 0))  # noqa
        if best is None or rank(r) < rank(best):
            best = r
        if best["match"]:
            break
    return best


def cmd_judge(a) -> None:
    out(judge(a.name, Path(a.file).read_text(encoding="utf-8", errors="replace"), a.profile))


def load_pending() -> list[dict]:
    try:
        return json.loads(PENDING.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return []


def save_pending(p: list[dict]) -> None:
    WORK.mkdir(parents=True, exist_ok=True)
    PENDING.write_text(json.dumps(p, indent=1), encoding="utf-8")


def clang_format(paths: list[Path]) -> None:
    pcm = shutil.which("pre-commit")
    if pcm and paths:
        run([pcm, "run", "clang-format", "--files", *[p.relative_to(ROOT).as_posix() for p in paths]])


def cmd_submit(a) -> None:
    f = function(a.name)
    if covered(f["addr"]):
        return out({"ok": False, "error": f"{a.name} is already in {covered(f['addr'])}"})
    source = Path(a.file).read_text(encoding="utf-8", errors="replace")
    r = judge(a.name, source, a.profile)
    if not r["match"]:
        return out({"ok": False, "error": "not a match", "judge": r})
    if r["profile"] != f"{am.COMPILERS[0][0]} {am.COMPILERS[0][1]}".strip() and not source.startswith(am.MARKER):
        source = f"{am.MARKER}{r['profile']} */\n" + source
    import find_culprits
    with pipeline_lock("workbench"):
        files = [project.DELINKS, am.COMPILERS_TXT, project.SYMBOLS]
        saved = {p: p.read_bytes() if p.exists() else None for p in files}
        journal_begin(files)
        created = am.integrate([(f["name"], f["size"], f["addr"], source)])
        journal_created(created)
        clang_format(created)
        t0 = time.time()
        build = find_culprits.build()
        if not find_culprits.rom_ok(build):
            for p, b in saved.items():
                if b is None:
                    p.unlink(missing_ok=True)
                else:
                    p.write_bytes(b)
            for p in created:
                p.unlink(missing_ok=True)
            run([sys.executable, "tools/configure.py", project.VERSION])
            journal_end()
            return out({"ok": False, "error": "the ROM is no longer byte-identical with this file (undone)",
                        "build": build[-60000:]})
        journal_end()
    pend = load_pending()
    pend.append({"name": f["name"], "file": created[0].relative_to(ROOT).as_posix(), "who": a.who,
                 "time": time.strftime("%Y-%m-%d %H:%M")})
    save_pending(pend)
    out({"ok": True, "file": created[0].relative_to(ROOT).as_posix(), "profile": r["profile"],
         "build_seconds": round(time.time() - t0, 1), "pending": len(pend),
         "next": "ROM byte-identical. `commit` runs the full verify once for all pending matches."})


def cmd_submit_many(a) -> None:
    """Submits every exact match of a batch_try results.json at once: one build for all (fallback: one by one)."""
    d = Path(a.dir)
    res = json.loads((d / "results.json").read_text(encoding="utf-8"))
    todo = [n for n, r in res.items() if r.get("match") and not r.get("submit")][: a.limit or None]
    items = []
    for n in todo:
        select_module(n)
        f = function(n)
        if covered(f["addr"]):
            continue
        if not am.MAIN_TEXT[0] <= f["addr"] < am.MAIN_TEXT[1]:  # .init / other code sections: not a .text file
            res[n]["submit"] = "not in .text"
            continue
        src = (d / f"{n}.c").read_text(encoding="utf-8", errors="replace")
        r = judge(n, src, res[n]["profile"])
        if r["match"]:
            if r["profile"] != f"{am.COMPILERS[0][0]} {am.COMPILERS[0][1]}".strip() and not src.startswith(am.MARKER):
                src = f"{am.MARKER}{r['profile']} */\n" + src
            items.append((MODULE, f, src))
    import find_culprits
    done = []
    state = {"build": ""}
    files = [project.ARM9 / "delinks.txt", project.ARM9 / "itcm" / "delinks.txt", *sorted(OVL_DIR.glob("ov*/delinks.txt")), am.COMPILERS_TXT]

    def attempt(group):
        """Integrates `group` and builds once: kept if the ROM is byte-identical, undone otherwise."""
        saved = {p: p.read_bytes() if p.exists() else None for p in files}
        journal_begin(files)
        created = []
        for mod, f, src in group:
            select_module(f["name"])
            created += am.integrate([(f["name"], f["size"], f["addr"], src)])
        journal_created(created)
        clang_format(created)
        build = find_culprits.build()
        if find_culprits.rom_ok(build):
            journal_end()
            return created
        state["build"] = build
        for p, b in saved.items():
            if b is None:
                p.unlink(missing_ok=True)
            else:
                p.write_bytes(b)
        for p in created:
            p.unlink(missing_ok=True)
        run([sys.executable, "tools/configure.py", project.VERSION])
        journal_end()
        return None

    def solve(group):
        """[(item, created path)] for the items that can be kept: failing overlays are split and retried."""
        if not group:
            return []
        created = attempt(group)
        if created is not None:
            return list(zip(group, created))
        bad_ov = set(re.findall(r"Check overlay (\d+): checksum failed", state["build"]))
        if len(group) == 1:
            return []
        if bad_ov:
            bad = [g for g in group if g[0] in {f"ov{int(n):03d}" for n in bad_ov}]
            rest = [g for g in group if g not in bad]
            if rest and bad:
                return solve(rest) + solve(bad)
        half = len(group) // 2
        return solve(group[:half]) + solve(group[half:])

    with pipeline_lock("workbench"):
        kept = solve(items)
        pend = load_pending()
        for (mod, f, src), path in kept:
            pend.append({"name": f["name"], "file": path.relative_to(ROOT).as_posix(), "who": a.who,
                         "time": time.strftime("%Y-%m-%d %H:%M")})
            res[f["name"]]["submit"] = True
            done.append(f["name"])
        for mod, f, src in items:
            if f["name"] not in done:
                res[f["name"]]["submit"] = "ROM differs"
        save_pending(pend)
    (d / "results.json").write_text(json.dumps(res, indent=1), encoding="utf-8")
    out({"ok": True, "submitted": len(done), "failed": len(items) - len(done), "pending": len(pend)})


def drop_files(rels: list[str]) -> None:
    """Takes files out of delinks.txt (main and overlays) / compilers.txt and deletes them (matches the verify
    rejected)."""
    for dl in all_delinks():
        text = dl.read_text(encoding="utf-8")
        new = text
        for rel in rels:
            new = re.sub(rf"\n*^{re.escape(rel)}:\n(?:[ \t]+.*\n?)+", "\n", new, flags=re.M)
        if new != text:
            dl.write_text(new.rstrip("\n") + "\n", encoding="utf-8", newline="\n")
    for rel in rels:
        (ROOT / rel).unlink(missing_ok=True)
    if am.COMPILERS_TXT.exists():
        lines = am.COMPILERS_TXT.read_text(encoding="utf-8").splitlines(keepends=True)
        am.COMPILERS_TXT.write_text("".join(l for l in lines if l.split(" ", 1)[0] not in rels), encoding="utf-8",
                                    newline="\n")


def cmd_pending(_a) -> None:
    out({"pending": load_pending()})


def cmd_commit(a) -> None:
    pend = [p for p in load_pending() if (ROOT / p["file"]).exists()]
    if not pend:
        return out({"ok": True, "committed": [], "note": "nothing pending"})
    dropped = []
    with pipeline_lock("workbench"):
        for attempt in range(2):
            run([sys.executable, "tools/configure.py", project.VERSION])
            v = run([sys.executable, "tools/match.py", "verify"])
            if "VERIFY PASSED" in v.stdout:
                break
            failing = set(re.findall(r"^FAIL: (\S+) is marked complete", v.stdout, re.M))
            bad = [p for p in pend if p["file"] in failing]
            if not bad or attempt:
                return out({"ok": False, "error": "verify failed (not because of the pending files: run the "
                                                  "'culprits' job)" if not bad else "verify still fails",
                            "verify": v.stdout[-3000:]})
            drop_files([p["file"] for p in bad])
            dropped += [p["name"] for p in bad]
            pend = [p for p in pend if p not in bad]
        paths = [p["file"] for p in pend] + [f"config/{project.VERSION}"]
        names = [p["name"] for p in pend]
        if names:
            who = ", ".join(sorted({p.get("who") or "workbench" for p in pend}))
            for i in range(0, len(paths), 100):  # the command line is limited (Windows): add in chunks
                run(["git", "add", "--", *paths[i:i + 100]])
            msg = f"Match {len(names)} function(s) ({who})\n\n" + "\n".join(names) + "\n"
            WORK.mkdir(parents=True, exist_ok=True)
            (WORK / "commit_msg.txt").write_text(msg, encoding="utf-8", newline="\n")
            c = run(["git", "commit", "-q", "-F", str(WORK / "commit_msg.txt")])
            if c.returncode:
                return out({"ok": False, "error": "git commit failed", "git": (c.stdout + c.stderr)[-1500:]})
    save_pending([])
    pushed = None
    if a.push and names and run(["git", "remote"]).stdout.strip():
        pushed = run(["git", "push", "-q", "origin", "HEAD"]).returncode == 0
    out({"ok": True, "committed": names, "dropped": dropped, "pushed": pushed})


# ---------------------------------------------------------------- data

def decode_words(raw: bytes, base: int, ptrs: dict[int, str]) -> list[str]:
    lines = []
    for o in range(0, len(raw) - len(raw) % 4, 4):
        w, = struct.unpack_from("<I", raw, o)
        note = ptrs.get(base + o)
        if note is None:
            f, = struct.unpack_from("<f", raw, o)
            s = w - (1 << 32) if w & 0x80000000 else w
            note = f"{s}" + (f"  ({f:g}f)" if 1e-4 < abs(f) < 1e7 else "")
        else:
            note = "&" + note
        lines.append(f"+0x{o:04x}  {w:08x}  {note}")
    if len(raw) % 4:
        lines.append(f"+0x{len(raw) - len(raw) % 4:04x}  " + raw[len(raw) - len(raw) % 4:].hex())
    return lines


def as_string(raw: bytes) -> str | None:
    if b"\0" not in raw:
        return None
    s = raw[:raw.index(b"\0")]
    if len(s) < 2 or any(c < 0x20 and c not in (9, 10, 13) or c > 0x7E for c in s):
        return None
    if any(raw[raw.index(b"\0"):]):
        return None  # something after the string: not one string
    return s.decode("ascii")


def c_declaration(sym: dict, sec: dict, raw: bytes | None, size: int, ptrs: dict[int, str]) -> str:
    name, const = sym["name"], "const " if sec and sec["name"] == ".rodata" else ""
    if raw is None:  # .bss
        return f"u32 {name}[{size // 4}];" if size % 4 == 0 else f"u8 {name}[{size}];"
    s = as_string(raw)
    if s is not None:
        esc = s.replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n").replace("\t", "\\t").replace("\r", "\\r")
        return f'{const}char {name}[{size}] = "{esc}";'
    if size % 4 == 0 and sym["addr"] % 4 == 0:
        words = []
        for o in range(0, size, 4):
            w, = struct.unpack_from("<I", raw, o)
            p = ptrs.get(sym["addr"] + o)
            words.append(f"(u32)&{p}" if p and "+" not in p and not p.startswith("0x") else f"0x{w:08X}")
        externs = sorted({p for p in ptrs.values() if "+" not in p and not p.startswith("0x")})
        decl = "".join(f"extern u8 {p}[];\n" for p in externs)
        body = ",\n".join("    " + ", ".join(words[i:i + 4]) for i in range(0, len(words), 4))
        return f"{decl}{const}u32 {name}[{size // 4}] = {{\n{body}\n}};"
    body = ", ".join(f"0x{b:02X}" for b in raw)
    return f"{const}u8 {name}[{size}] = {{{body}}};"


def cmd_data(a) -> None:
    sym = find(a.target)
    if sym is None:
        c = containing(int(a.target, 16)) if a.target.startswith("0x") else None
        if not c:
            return out({"error": f"{a.target}: no such symbol"})
        sym = c[0]
    size = size_of(sym)
    sec = section_of(sym["addr"])
    raw = None if sec and sec["kind"] == "bss" else pc.target_bytes(sym["addr"], size)
    ptrs = {frm: name_at(to, mod) for frm, kind, to, mod in relocs_in(sym["addr"], sym["addr"] + size)
            if kind == "load"}
    users = []
    for frm, kind, to, _m in relocs():
        if sym["addr"] <= to < sym["addr"] + size:
            c = containing(frm)
            n = c[0]["name"] if c else f"0x{frm:08x}"
            if n not in users:
                users.append(n)
    out({"name": sym["name"], "addr": f"0x{sym['addr']:08x}", "size": size, "section": sec["name"] if sec else None,
         "kind": sym["kind"], "file": covered(sym["addr"]), "string": as_string(raw) if raw else None,
         "words": decode_words(raw, sym["addr"], ptrs)[:256] if raw else [], "pointers": list(ptrs.values()),
         "used_by": users[:40], "c": c_declaration(sym, sec, raw, size, ptrs)[:20000]})


def elf_sections(d: bytes) -> list[dict]:
    shoff, = struct.unpack_from("<I", d, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 0x2E)
    secs = []
    for i in range(shnum):
        name, typ, flags, addr, off, size, link, info, align, entsize = struct.unpack_from("<10I", d, shoff + i * shentsize)
        secs.append({"name_off": name, "type": typ, "off": off, "size": size, "link": link, "info": info,
                     "entsize": entsize})
    strtab = secs[shstrndx]
    for s in secs:
        end = d.index(b"\0", strtab["off"] + s["name_off"])
        s["name"] = d[strtab["off"] + s["name_off"]:end].decode("ascii", "replace")
    return secs


def elf_symbols(d: bytes, secs: list[dict]) -> list[dict]:
    out_ = []
    for s in secs:
        if s["type"] != 2:
            continue
        strtab = secs[s["link"]]
        for i in range(s["size"] // 16):
            st_name, value, size, info, _o, shndx = struct.unpack_from("<IIIBBH", d, s["off"] + i * 16)
            end = d.index(b"\0", strtab["off"] + st_name)
            out_.append({"index": i, "name": d[strtab["off"] + st_name:end].decode("ascii", "replace"),
                         "value": value, "size": size, "type": info & 0xF, "bind": info >> 4, "shndx": shndx})
    return out_


def elf_relocs(d: bytes, secs: list[dict], syms: list[dict]) -> dict[int, dict[int, str]]:
    """{section index: {offset: target name(+addend)}} from REL and RELA sections."""
    out_: dict[int, dict[int, str]] = {}
    for s in secs:
        if s["type"] not in (4, 9):  # RELA, REL
            continue
        step = 12 if s["type"] == 4 else 8
        for i in range(s["size"] // step):
            if step == 12:
                off, info, addend = struct.unpack_from("<IIi", d, s["off"] + i * step)
            else:
                (off, info), addend = struct.unpack_from("<II", d, s["off"] + i * step), 0
            sym = syms[info >> 8] if (info >> 8) < len(syms) else None
            if sym is None:
                continue
            nm = sym["name"] or (secs[sym["shndx"]]["name"] if sym["shndx"] < len(secs) else "?")
            out_.setdefault(s["info"], {})[off] = nm + (f"+0x{addend:x}" if addend else "")
    return out_


def cmd_datacheck(a) -> None:
    source = Path(a.file).read_text(encoding="utf-8", errors="replace")
    prof = source.split("*/")[0][len(am.MARKER):].strip() if source.startswith(am.MARKER) else \
        f"{am.COMPILERS[0][0]} {am.COMPILERS[0][1]}".strip()
    objbytes, msg, _obj, tmp = compile_one(source, prof)
    tmp.cleanup()
    if objbytes is None:
        return out({"ok": False, "error": "does not compile", "errors": msg[-3000:]})
    d = objbytes
    secs = elf_sections(d)
    syms = elf_symbols(d, secs)
    rel = elf_relocs(d, secs, syms)
    ours = {s["name"]: s for s in symbols() if s["kind"] in ("data", "bss")}
    report, all_ok = [], True
    for s in syms:
        if s["shndx"] in (0, 0xFFF1, 0xFFF2) or s["shndx"] >= len(secs) or s["type"] != 1:  # objects only
            continue
        sec = secs[s["shndx"]]
        if s["name"] not in ours:
            report.append({"name": s["name"], "status": "unknown", "note": "no data symbol of this name in symbols.txt"})
            continue
        g = ours[s["name"]]
        rom_size = size_of(g)
        entry = {"name": s["name"], "addr": f"0x{g['addr']:08x}", "section": sec["name"], "size": s["size"],
                 "rom_size": rom_size}
        rsec = section_of(g["addr"])
        if rsec and rsec["name"] != sec["name"] and not (rsec["name"] == ".bss" and sec["name"] in (".bss", ".sbss")):
            entry["note"] = f"in {sec['name']} here, in {rsec['name']} in the game"
            entry["status"] = "section"
        if sec["type"] == 8:  # NOBITS (.bss)
            entry.setdefault("status", "ok" if s["size"] == rom_size else "size")
        else:
            mine = d[sec["off"] + s["value"]: sec["off"] + s["value"] + s["size"]]
            rom = pc.target_bytes(g["addr"], min(rom_size, s["size"]) or s["size"])
            rom_ptrs = {frm - g["addr"]: name_at(to, mod)
                        for frm, kind, to, mod in relocs_in(g["addr"], g["addr"] + rom_size) if kind == "load"}
            my_ptrs = {o - s["value"]: n for o, n in rel.get(s["shndx"], {}).items()
                       if s["value"] <= o < s["value"] + s["size"]}
            diffs = []
            for o in range(0, min(len(mine), len(rom)) - 3, 4):
                if o in rom_ptrs or o in my_ptrs:
                    if rom_ptrs.get(o) != my_ptrs.get(o):
                        diffs.append(f"+0x{o:04x}: points to {my_ptrs.get(o, 'a number')} here, "
                                     f"{rom_ptrs.get(o, 'a number')} in the game")
                    continue
                if mine[o:o + 4] != rom[o:o + 4]:
                    w1, w2 = struct.unpack_from("<I", mine, o)[0], struct.unpack_from("<I", rom, o)[0]
                    diffs.append(f"+0x{o:04x}: {w1:08x} here, {w2:08x} in the game")
            tail = len(mine) - len(mine) % 4
            if mine[tail:] != rom[tail:len(mine)]:
                diffs.append(f"+0x{tail:04x}: last bytes {mine[tail:].hex()} here, {rom[tail:len(mine)].hex()} in the game")
            if s["size"] != rom_size:
                diffs.insert(0, f"size 0x{s['size']:x} here, 0x{rom_size:x} in the game (up to the next symbol)")
            entry.setdefault("status", "ok" if not diffs else "differs")
            entry["diffs"] = diffs[:40]
        all_ok &= entry["status"] == "ok"
        report.append(entry)
    # Order inside each section: the linker keeps the object's order, the game has its own
    order = []
    by_sec: dict[int, list[tuple[int, int, str]]] = {}
    for s in syms:
        if s["type"] == 1 and s["name"] in ours and 0 < s["shndx"] < len(secs):
            by_sec.setdefault(s["shndx"], []).append((s["value"], ours[s["name"]]["addr"], s["name"]))
    for shndx, items in by_sec.items():
        items.sort()
        for (_v1, a1, n1), (_v2, a2, n2) in zip(items, items[1:]):
            if a2 < a1:
                order.append(f"{secs[shndx]['name']}: {n1} comes before {n2} in the object, after it in the game "
                             "(the linker keeps the object's order: change the order of the definitions, or what "
                             "initializes them, until it follows the game)")
    all_ok &= not order
    out({"ok": all_ok, "profile": prof, "symbols": report, "order": order,
         "note": "pointers are compared by what they point at; data that is not in symbols.txt cannot be checked"})


# ---------------------------------------------------------------- shared header

def rom_check() -> tuple[bool, str]:
    import find_culprits
    b = find_culprits.build()
    return find_culprits.rom_ok(b), b


def cmd_header(a) -> None:
    header = (ROOT / a.header).resolve()
    if ROOT / "include" not in header.parents or header.suffix != ".h":
        return out({"ok": False, "error": "only headers under include/ can be changed"})
    new = Path(a.new).read_text(encoding="utf-8", errors="replace")
    if any(ord(c) > 127 for c in new):
        return out({"ok": False, "error": "ASCII only"})
    why = fake_match(new, header.read_text(encoding="utf-8", errors="replace") if header.exists() else "")
    if why and "preprocessor line" not in why:  # new #define / prototypes lines are what a header is for
        return out({"ok": False, "error": f"refused: {why}"})
    with pipeline_lock("workbench"):
        old = header.read_bytes() if header.exists() else None
        journal_begin([header, project.SYMBOLS])
        header.write_text(new, encoding="utf-8", newline="\n")
        t0 = time.time()
        ok, build = rom_check()
        if not ok:
            if old is None:
                header.unlink(missing_ok=True)
            else:
                header.write_bytes(old)
            journal_end()
            rom_check()
            return out({"ok": False, "error": "with this header the game no longer builds byte-identical: undone "
                                              "(every matched file that includes it was recompiled)",
                        "build": build[-3000:]})
        journal_end()
    out({"ok": True, "seconds": round(time.time() - t0, 1),
         "note": "every matched file still compiles to the same bytes: kept (not committed)"})


# ---------------------------------------------------------------- merged functions

RETURN = (lambda w: w == 0xE12FFF1E or (w & 0xFFFF8000) == 0xE8BD8000 or (w & 0xFF000000) == 0xEA000000)


def split_candidates() -> list[dict]:
    """Calls that land in the middle of a function. When the instruction (or pool) right before is the end of a
    function (return, unconditional branch, literal pool), dsd most likely merged two functions."""
    funcs = {s["addr"]: s for s in symbols() if s["kind"] == "function"}
    hits: dict[tuple[str, int], list[str]] = {}
    for frm, kind, to, mod in relocs():
        if mod != "main" or not kind.startswith(("arm_call", "arm_branch")) or to in funcs:
            continue
        c = containing(to)
        if not c or c[0]["kind"] != "function" or c[0]["mode"] != "arm" or c[1] % 4:
            continue
        caller = containing(frm)
        hits.setdefault((c[0]["name"], to), [])
        n = caller[0]["name"] if caller else f"0x{frm:08x}"
        if n != c[0]["name"] and n not in hits[(c[0]["name"], to)]:
            hits[(c[0]["name"], to)].append(n)
    out_ = []
    for (name, at), callers in sorted(hits.items(), key=lambda x: x[0][1]):
        if not callers:
            continue  # only jumps from inside the function itself
        f = find(name)
        words = pc.target_bytes(f["addr"], f["size"])
        pool = set()
        for i in range(len(words) // 4):
            w, = struct.unpack_from("<I", words, i * 4)
            if (w & 0x0F7F0000) == 0x051F0000:
                off = w & 0xFFF
                pool.add(f["addr"] + (i + 2) * 4 + (off if w & 0x00800000 else -off))
        prev = at - 4
        while prev in pool and prev > f["addr"]:
            prev -= 4
        w, = struct.unpack_from("<I", words, prev - f["addr"])
        # The first part jumping into the second one: one body with two entry points (the compiler's shared tail,
        # or hand-written code), not two functions dsd merged
        shared = False
        for i in range((at - f["addr"]) // 4):
            ins, = struct.unpack_from("<I", words, i * 4)
            if f["addr"] + i * 4 in pool or (ins & 0x0F000000) != 0x0A000000:  # b<cond> (not bl)
                continue
            off = ins & 0xFFFFFF
            target = f["addr"] + i * 4 + 8 + ((off - (1 << 24) if off & 0x800000 else off) << 2)
            if at < target < f["addr"] + f["size"]:
                shared = True
                break
        out_.append({"function": name, "at": f"0x{at:08x}", "callers": callers[:8],
                     "likely_merged": bool(RETURN(w)) and not shared, "shared_body": shared,
                     "matched": bool(covered(f["addr"]))})
    return out_


def cmd_splits(_a) -> None:
    c = split_candidates()
    out({"candidates": c, "likely": sum(1 for x in c if x["likely_merged"] and not x["matched"])})


def cmd_split(a) -> None:
    f = function(a.name)
    at = int(a.addr, 16)
    if not f["addr"] < at < f["addr"] + f["size"] or at % 4:
        return out({"ok": False, "error": "the address must be inside the function, on an ARM instruction"})
    if covered(f["addr"]):
        return out({"ok": False, "error": f"{a.name} is already matched in {covered(f['addr'])}"})
    new_name = a.new_name or f"func_{at:08x}"
    if find(new_name):
        return out({"ok": False, "error": f"{new_name} already exists"})
    text = project.SYMBOLS.read_text(encoding="utf-8")
    line = re.search(rf"^{re.escape(a.name)} kind:function\(arm,size=0x[0-9a-f]+\)(.*)$", text, re.M)
    if not line:
        return out({"ok": False, "error": "symbol line not found"})
    first = f"{a.name} kind:function(arm,size=0x{at - f['addr']:x}){line.group(1)}"
    rest = f"\n{new_name} kind:function(arm,size=0x{f['addr'] + f['size'] - at:x}) addr:0x{at:08x}"
    with pipeline_lock("workbench"):
        old = project.SYMBOLS.read_bytes()
        journal_begin([project.SYMBOLS, project.DELINKS])
        project.SYMBOLS.write_text(text[:line.start()] + first + rest + text[line.end():], encoding="utf-8",
                                   newline="\n")
        ok, build = rom_check()
        if not ok:
            project.SYMBOLS.write_bytes(old)
            journal_end()
            rom_check()
            return out({"ok": False, "error": "the ROM no longer builds byte-identical: undone", "build": build[-60000:]})
        asm = project.ASM_DIR
        shutil.rmtree(asm, ignore_errors=True)
        run(["ninja", "dis"])
        text = "\n".join(p.read_text(encoding="utf-8", errors="replace") for p in asm.glob("*.s"))
        if not all(f"arm_func_end {n}\n" in text + "\n" for n in (a.name, new_name)):
            # dsd could not disassemble the two halves (e.g. the first one jumps into the second): undone
            project.SYMBOLS.write_bytes(old)
            journal_end()
            rom_check()
            shutil.rmtree(asm, ignore_errors=True)
            run(["ninja", "dis"])
            return out({"ok": False, "error": "the ROM builds, but dsd cannot disassemble the two halves (one body "
                                              "with two entry points?): undone"})
        journal_end()
    out({"ok": True, "functions": [a.name, new_name],
         "note": "symbols.txt changed, ROM byte-identical, disassembly regenerated (not committed)"})


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("info"); p.add_argument("name"); p.set_defaults(fn=cmd_info)  # noqa: E702
    for c, fn in (("judge", cmd_judge), ("submit", cmd_submit)):
        p = sub.add_parser(c)
        p.add_argument("name")
        p.add_argument("file")
        p.add_argument("--profile")
        p.add_argument("--who", default="")
        p.set_defaults(fn=fn)
    p = sub.add_parser("commit"); p.add_argument("--push", action="store_true"); p.set_defaults(fn=cmd_commit)  # noqa
    sub.add_parser("pending").set_defaults(fn=cmd_pending)
    p = sub.add_parser("submit-many"); p.add_argument("dir"); p.add_argument("--who", default="")  # noqa: E702
    p.add_argument("--limit", type=int, default=0); p.set_defaults(fn=cmd_submit_many)  # noqa: E702
    p = sub.add_parser("data"); p.add_argument("target"); p.set_defaults(fn=cmd_data)  # noqa: E702
    p = sub.add_parser("datacheck"); p.add_argument("file"); p.set_defaults(fn=cmd_datacheck)  # noqa: E702
    p = sub.add_parser("header"); p.add_argument("header"); p.add_argument("new"); p.set_defaults(fn=cmd_header)  # noqa
    sub.add_parser("splits").set_defaults(fn=cmd_splits)
    p = sub.add_parser("split")
    p.add_argument("name")
    p.add_argument("addr")
    p.add_argument("--new-name")
    p.set_defaults(fn=cmd_split)
    a = ap.parse_args()
    key = getattr(a, "name", None) or getattr(a, "target", None)
    if key and a.cmd in ("info", "judge", "submit", "data", "split"):
        select_module(key)
    for stream in (sys.stdout, sys.stderr):
        try:
            stream.reconfigure(errors="replace")
        except (AttributeError, ValueError):
            pass
    a.fn(a)


if __name__ == "__main__":
    main()
