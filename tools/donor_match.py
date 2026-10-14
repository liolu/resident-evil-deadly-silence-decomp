#!/usr/bin/env python3
"""Reuse functions already decompiled in other public DS decompilations ("donors").

    python tools/donor_match.py              # find, verify and add every function a donor has
    python tools/donor_match.py --dry-run    # only report

The donors (NitroSDK, NitroSystem, NitroWiFi, NitroDWC, pret's Pokemon games, ...) are cloned and indexed by
`decomp ds/tools/donors.py` into `decomp ds/donors.sqlite` (set DONORS_DB to use another one). For every ARM function
of the main module that is not in a source file yet:
  1. its fingerprint (donorlib.py) is looked up in the donor database: same instructions, same registers, only the
     called functions and the loaded addresses may differ;
  2. the donor's file is preprocessed and reduced to that one function; the functions and data it uses are renamed
     to this game's symbols (read from the branches and literal pool of the game's own code);
  3. it is compiled with the donor's compiler profile and compared with the ROM (when the code has the right shape
     but differs, other service packs / optimization modes are tried); only exact matches are kept, and only when
     the object holds nothing but that function (no string, no extra code, no COMMON symbol), checked again with
     the exact flags of the build (build_check);
  4. matches go to src/donor/<name>.c (with the donor's name and file in a comment), are declared `complete` in
     delinks.txt, and `tools/match.py verify` must pass, else the files that break the ROM are dropped: those the
     build names, then those find_culprits finds (byte differences, linker map), then by bisection (--bisect N
     builds at most, ninja only: seconds each), then one full `match.py verify`. Everything is rolled back only if
     nothing verifies.
Functions are tried in parallel (-j).
"""
import argparse
import ast
import json
import os
import re
import sqlite3
import struct
import subprocess
import sys
import tempfile
import threading
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402
import donorlib  # noqa: E402
import auto_match as am  # noqa: E402
import probe_compiler as pc  # noqa: E402
from pipeline_lock import journal_begin, journal_created, journal_end  # noqa: E402

DS_ROOT = Path(os.environ.get("DS_ROOT", ROOT.parent.parent))  # decomp ds/ (projects live in decomp ds/projets/)
DB = Path(os.environ.get("DONORS_DB", DS_ROOT / "donors.sqlite"))
sys.path.insert(0, str(DS_ROOT / "tools"))
DONOR_SRC = ROOT / "src" / "donor"
WORK = ROOT / "build" / "donor"
SYM_RE = re.compile(r"^(\S+) kind:(function|data|bss)\S* addr:0x([0-9a-f]+)")
BRANCH_RELOCS = {donorlib.R_ARM_PC24, donorlib.R_ARM_CALL, donorlib.R_ARM_JUMP24}
# Other compiler profiles tried when the donor's own profile gives the right shape but not the exact code
# ("near"/"size"): same source, another service pack or optimization mode. Patch levels with a compiler folder only.
_ALT_FLAGS_20 = ["-O4,p -lang c99 -ipa file -inline on,noauto", "-O4,p -lang c99 -inline on,noauto",
                 "-O4,s -lang c99 -ipa file -inline on,noauto"]
_ALT_FLAGS_12 = ["-O4,p -lang c99 -inline on,noauto", "-O4,s -lang c99 -inline on,noauto"]
_ALT_VERSIONS = {"2.0": ["sp1p5", "sp1p2", "sp1p6", "sp1p7", "sp2", "sp2p3", "sp1", "base"],
                 "1.2": ["sp2p3", "sp2", "sp3", "sp4", "base"]}
ALT_BUDGET = 16  # compiles at most per donor function on top of its own profile
_pp_locks: dict[Path, threading.Lock] = {}
_pp_guard = threading.Lock()


def _pp_lock(path: Path) -> threading.Lock:
    """One lock per preprocessed file: two threads must not run the preprocessor on the same donor file."""
    with _pp_guard:
        return _pp_locks.setdefault(path, threading.Lock())


def alt_profiles(version: str, flags: str, style: str) -> list[tuple[str, str]]:
    """(version, flags) to try after (version, flags), the compiler family of the game's code first."""
    families = {"v20": ["2.0"], "v12": ["1.2"]}.get(style, ["2.0", "1.2"])
    out = []
    for fam in families:
        for sp in _ALT_VERSIONS[fam]:
            v = f"{fam}/{sp}"
            if not (am.MWCC_ROOT / v / "mwccarm.exe").exists():
                continue
            for fl in _ALT_FLAGS_20 if fam == "2.0" else _ALT_FLAGS_12:
                if (v, fl) != (version, flags) and (v, fl) not in out:
                    out.append((v, fl))
    return out[:ALT_BUDGET]


def _build_cc_flags() -> str:
    """CC_FLAGS of tools/configure.py, read from its source (importing it would run the configuration)."""
    m = re.search(r'^CC_FLAGS = " "\.join\((\[.*?\])\)', (ROOT / "tools" / "configure.py").read_text(), re.M | re.S)
    return " ".join(ast.literal_eval(m.group(1))) if m else ""


BUILD_CC_FLAGS = _build_cc_flags()


def build_check(source: str, name: str, size: int, addr: int, version: str, flags: str) -> str:
    """Compiles the candidate exactly as ninja will (CC_FLAGS of configure.py + the compilers.txt flags) and checks
    what the link will get: the same code, nothing else, and a .text of exactly the function's size (an object
    bigger than its slot shifts everything after it in the module). Returns "" or why it fails."""
    with tempfile.TemporaryDirectory() as tmp:
        t = Path(tmp)
        (t / "f.c").write_text(source)
        cmd = (f'"{am.MWCC_ROOT / version / "mwccarm.exe"}" {BUILD_CC_FLAGS} -lang=c {flags} '
               f'-i "{ROOT / "include"}" -d {project.VERSION} -c f.c -o f.o')
        r = am.run_limited(cmd, cwd=t, shell=True)
        if r.returncode != 0 or not (t / "f.o").exists():
            return "does not compile with the build flags"
        cand = pc.compiled_function(t / "f.o", name)
        if cand is None or pc.compare(pc.target_bytes(addr, size), cand)[0]:
            return "different code with the build flags"
        obj = donorlib.Obj(t / "f.o")
        extra = [s for s in obj.nonempty_sections() if not s.startswith(".text")]
        if extra:
            return f"extra section {extra[0]} with the build flags"
        # A tentative definition (`int x;`) is a COMMON symbol, in no section: the linker adds it to the .bss,
        # which moves everything placed after the module (overlays, TCM)
        common = [s[0] for s in obj.syms if s[4] == 0xFFF2]
        if common:
            return f"common symbol {common[0]} (grows the .bss)"
        text = sum(s[5] for i, s in enumerate(obj.secs) if s[2] & 2 and obj.sec_names[i].startswith(".text"))
        if text != size:
            return f".text is 0x{text:x} bytes for a 0x{size:x} slot"
        align = max((s[8] for i, s in enumerate(obj.secs) if obj.sec_names[i].startswith(".text")), default=4)
        if align > 4 and addr % align:
            return f".text aligned on {align} bytes, the function is not"
    return ""


def compile_profiles(pre: str, dname: str, rename: dict, name: str, size: int, addr: int,
                     profiles: list[tuple[str, str]]) -> tuple[str, str, str, str]:
    """Tries the candidate source with each profile (the first is the donor's own; the others only while the code
    has the right shape). Returns (status, source, version, flags) of the best attempt."""
    best = ("source not rebuilt", "", "", "")
    for n, (version, flags) in enumerate(profiles):
        if n and best[0] not in ("near", "size"):
            break  # does not compile, or no source: another compiler will not fix that
        status = "source not rebuilt"
        source = ""
        for minimal in (True, False):
            source = donorlib.candidate_source(pre, dname, rename, minimal) if pre else None
            if source is None:
                break
            with tempfile.TemporaryDirectory() as tmp:
                t = Path(tmp)
                status = am.compile_and_compare(t, source, name, size, addr, am.MWCC_ROOT / version / "mwccarm.exe",
                                                flags)
                if status == "match" and not only_function(t / "f.o", name):
                    status = "extra code or data"
            if status == "match":
                head = f"{am.MARKER}{version} {flags} */\n"
                why = build_check(head + source, name, size, addr, version, flags)
                if why:
                    status = f"no match in the build ({why})"
                break
        if n == 0 or status == "match":
            best = (status, source or "", version, flags)  # else keep the donor profile's result for the log
        if status == "match":
            break
    return best


def game_symbols() -> dict[int, str]:
    out = {}
    for line in project.SYMBOLS.read_text().splitlines():
        m = SYM_RE.match(line)
        if m:
            addr = int(m.group(3), 16)
            if m.group(2) == "function" or addr not in out:
                out[addr] = m.group(1)
    return out


def inner_entries() -> dict[int, int]:
    """{address: calling address} of the places of the main module reached from elsewhere other than a function
    start: calls and jumps (relocs.txt of every module) and labels (symbols.txt). A function holding one cannot come
    from a donor: its source has no label there (e.g. `_u32_div_f`, entered at `_u32_div_not_0_f` by `_s32_div_f`),
    so the link moves the code around it."""
    starts = set(game_symbols())
    out = {}
    for line in project.SYMBOLS.read_text().splitlines():
        m = re.match(r"^\S+ kind:label\S* addr:0x([0-9a-f]+)", line)
        if m:
            out[int(m.group(1), 16)] = 0
    for path in project.CONFIG.rglob("relocs.txt"):
        for frm, to in re.findall(r"from:0x([0-9a-f]+) kind:\S+ to:0x([0-9a-f]+) module:main",
                                  path.read_text(encoding="utf-8", errors="replace")):
            to = int(to, 16) & ~1
            if to not in starts:
                out.setdefault(to, int(frm, 16))
    return out


_INNER = None


def outside_pool_load(code: bytes, addr: int) -> int | None:
    """The address of a word loaded pc-relative (`ldr rX, [pc, #imm]`) outside the function, or None. Hand-written
    code can read a constant pool placed before it (DGTi_Hash2ProcessBlock): the ROM still matches, but `dsd dis`
    then panics on the complete file, which stops auto_match."""
    end = addr + len(code)
    for i in range(len(code) // 4):
        w, = struct.unpack_from("<I", code, i * 4)
        if (w & 0x0F7F0000) == 0x051F0000 and w >> 28 != 0xF:
            off = w & 0xFFF
            t = addr + i * 4 + 8 + (off if w & 0x00800000 else -off)
            if not addr <= t < end:
                return t
    return None


def inner_entry(addr: int, size: int) -> int | None:
    """An address strictly inside [addr, addr + size) reached from outside the function, or None."""
    global _INNER
    if _INNER is None:
        _INNER = inner_entries()
    for a, frm in _INNER.items():
        if addr < a < addr + size and not addr <= frm < addr + size:
            return a
    return None


def donor_licenses() -> dict[str, str]:
    """{repo folder: license} of the donors allowed in this project (decomps-externes/sources.tsv, column use=yes).
    GPL donors are excluded: the game repositories are CC0."""
    out = {}
    path = DS_ROOT / "decomps-externes" / "sources.tsv"
    for line in path.read_text(encoding="utf-8").splitlines() if path.exists() else []:
        parts = line.split("\t")
        if len(parts) >= 3 and not line.startswith("#") and parts[2].strip() == "yes":
            out[parts[0].replace("/", "_", 1)] = parts[1]
    return out


def donor_tools():
    import donors  # decomp ds/tools/donors.py: profiles, flags, object cache
    return donors


def preprocessed(dn, repo: str, rel: str, profile: str, incs: str) -> str | None:
    """The donor file after the preprocessor (cached next to its object)."""
    out = dn.BUILD / "pp" / profile / repo / (rel[:-2] + ".i.c")
    with _pp_lock(out):
        return _preprocess(dn, repo, rel, profile, incs, out)


def _preprocess(dn, repo: str, rel: str, profile: str, incs: str, out: Path) -> str | None:
    if not out.exists():
        version, flags = dn.PROFILES[profile]
        out.parent.mkdir(parents=True, exist_ok=True)
        cmd = (f'"{dn.MWCC_ROOT / version / "mwccarm.exe"}" -E {flags} {dn.COMMON} {dn.DEFINES} {incs} '
               f'"{dn.EXT / repo / rel}" -o "{out}"')
        subprocess.run(cmd, shell=True, cwd=dn.EXT / repo, capture_output=True, timeout=60)
    return out.read_text(encoding="latin-1") if out.exists() else None


def rename_map(dn, row, addr: int, target: bytes, syms: dict[int, str], our_name: str) -> tuple[dict, str]:
    """{donor symbol: game symbol} from the donor's relocations and the game's own code, or ({}, reason)."""
    repo, rel, profile, dname, size, relocs = row
    out = {dname: our_name}
    for off, rtype, sym, addend in json.loads(relocs):
        if not sym or sym.startswith(("@", ".", "$")):
            return {}, "anonymous symbol (string or static data)"
        word, = struct.unpack_from("<I", target, off)
        if rtype in BRANCH_RELOCS:
            simm = word & 0xFFFFFF
            simm = simm - (1 << 24) if simm & 0x800000 else simm
            dest = addr + off + 8 + simm * 4
        elif rtype == donorlib.R_ARM_ABS32:
            dest = (word - addend) & 0xFFFFFFFF
        else:
            return {}, f"relocation type {rtype}"
        name = syms.get(dest) or syms.get(dest & ~1)
        if name is None:
            return {}, f"no game symbol at 0x{dest:08x} for {sym}"
        if out.get(sym, name) != name:
            return {}, f"{sym} maps to two game symbols"
        out[sym] = name
    return out, ""


def only_function(obj_file: Path, name: str) -> bool:
    """The candidate object holds that function and nothing else that would be linked."""
    obj = donorlib.Obj(obj_file)
    # .exceptix: exception tables, only because the test compile lacks -Cpp_exceptions off (the build has it)
    if [s for s in obj.nonempty_sections() if not s.startswith((".text", ".exceptix"))]:
        return False
    return [f[0] for f in obj.functions()] == [name]


# ---------------------------------------------------------------- our other projects as donors

def _project_symbols(sym_file: Path) -> dict[int, str]:
    out = {}
    for line in sym_file.read_text(encoding="utf-8", errors="replace").splitlines():
        m = SYM_RE.match(line)
        if m:
            a = int(m.group(3), 16)
            if m.group(2) == "function" or a not in out:
                out[a] = m.group(1)
    return out


def _project_index(game_dir: Path) -> dict | None:
    """Matched single-function source files of another project of this workspace, by fingerprint (cached in
    decomp ds/donors_internal/<game>.json until its delinks.txt changes)."""
    try:
        dl = next(game_dir.glob("config/*/arm9/delinks.txt"))
    except StopIteration:
        return None
    ver = dl.parent.parent.name
    binp, yml = game_dir / "extract" / ver / "arm9" / "arm9.bin", game_dir / "extract" / ver / "arm9" / "arm9.yaml"
    if not (binp.exists() and yml.exists()):
        return None
    cache = DS_ROOT / "donors_internal" / f"{game_dir.name}.json"
    stamp = f"{dl.stat().st_mtime_ns}:{(dl.parent / 'symbols.txt').stat().st_mtime_ns}"
    if cache.exists():
        try:
            d = json.loads(cache.read_text(encoding="utf-8"))
            if d.get("stamp") == stamp:
                return d
        except Exception:
            pass
    base = int(re.search(r"base_address:\s*(\d+)", yml.read_text()).group(1))
    data = binp.read_bytes()
    funcs = {}
    for line in (dl.parent / "symbols.txt").read_text(encoding="utf-8", errors="replace").splitlines():
        m = re.match(r"(\S+) kind:function\(arm,size=0x([0-9a-f]+)\) addr:0x([0-9a-f]+)", line)
        if m:
            funcs[int(m.group(3), 16)] = (m.group(1), int(m.group(2), 16))
    comp = {}
    ct = dl.parent.parent / "compilers.txt"
    for line in ct.read_text().splitlines() if ct.exists() else []:
        line = line.split("#", 1)[0].strip()
        if line:
            path, ver_, *flags = line.split()
            comp[path] = [ver_, " ".join(flags)]
    m = re.search(r'^MWCC_VERSION\s*=\s*"([^"]+)"', (game_dir / "tools" / "configure.py").read_text(), re.M) \
        if (game_dir / "tools" / "configure.py").exists() else None
    default = [m.group(1) if m else "2.0/sp1p5", ""]
    entries = {}
    for path, a, b in re.findall(r"^(src/\S+):\n\s+complete\n\s+\.text\s+start:0x([0-9a-f]+) end:0x([0-9a-f]+)",
                                 dl.read_text(), re.M):
        a, b = int(a, 16), int(b, 16)
        fn = funcs.get(a)
        if not fn or a + fn[1] != b or not path.endswith(".c"):
            continue  # only files holding exactly one function
        fp = donorlib.fingerprint(data[a - base: b - base])
        if fp:
            entries.setdefault(fp, []).append([path, fn[0], a, fn[1]] + comp.get(path, default))
    d = {"stamp": stamp, "version": ver, "base": base, "entries": entries}
    cache.parent.mkdir(parents=True, exist_ok=True)
    cache.write_text(json.dumps(d), encoding="utf-8")
    return d


_INTERNAL = None


def internal_donors() -> list[tuple[Path, dict]]:
    """[(project folder, index)] of the other projects of decomp ds/projets/."""
    global _INTERNAL
    if _INTERNAL is None:
        _INTERNAL = []
        for g in sorted((DS_ROOT / "projets").iterdir()) if (DS_ROOT / "projets").exists() else []:
            if g.is_dir() and not g.name.startswith(("_", ".")) and g.resolve() != ROOT.resolve():
                try:
                    idx = _project_index(g)
                except Exception:
                    idx = None
                if idx and idx["entries"]:
                    _INTERNAL.append((g, idx))
    return _INTERNAL


def internal_rename(g: Path, idx: dict, d_addr: int, d_name: str, addr: int, size: int, target: bytes,
                    syms: dict[int, str], our_name: str) -> tuple[dict, str]:
    """{donor project symbol: our symbol}, read from the two ROMs: same instructions, so the literal pool words
    and the calls are at the same places; the addresses they hold name the symbols on each side."""
    data = (g / "extract" / idx["version"] / "arm9" / "arm9.bin").read_bytes()
    donor = data[d_addr - idx["base"]: d_addr - idx["base"] + size]
    dsyms = _project_symbols(g / "config" / idx["version"] / "arm9" / "symbols.txt")
    n = size // 4
    dw, tw = struct.unpack(f"<{n}I", donor), struct.unpack(f"<{n}I", target)
    out = {d_name: our_name}
    pool = donorlib.pool_words(dw)
    for i in range(n):
        if i in pool:
            dv, tv = dw[i], tw[i]
        elif (dw[i] & 0x0E000000) == 0x0A000000:
            def dest(w, base):
                s = w & 0xFFFFFF
                return base + i * 4 + 8 + (s - (1 << 24) if s & 0x800000 else s) * 4
            dv, tv = dest(dw[i], d_addr), dest(tw[i], addr)
            if d_addr <= dv < d_addr + size:
                continue  # branch inside the function
        else:
            continue
        dn_, tn = dsyms.get(dv) or dsyms.get(dv & ~1), syms.get(tv) or syms.get(tv & ~1)
        if dn_ is None:
            if dv == tv:
                continue  # a constant, not an address
            return {}, f"no symbol at 0x{dv:08x} in {g.name}"
        if tn is None:
            return {}, f"no game symbol at 0x{tv:08x} (for {dn_})"
        if out.get(dn_, tn) != tn:
            return {}, f"{dn_} maps to two game symbols"
        out[dn_] = tn
    return out, ""


def internal_preprocessed(g: Path, path: str, version: str, flags: str) -> str | None:
    out = WORK / "pp_internal" / g.name / (path[:-2] + ".i.c")
    with _pp_lock(out):
        return _preprocess_internal(g, path, version, flags, out)


def _preprocess_internal(g: Path, path: str, version: str, flags: str, out: Path) -> str | None:
    if not out.exists():
        out.parent.mkdir(parents=True, exist_ok=True)
        mwcc = am.MWCC_ROOT / version / "mwccarm.exe"
        cmd = f'"{mwcc}" -E {pc.BASE_FLAGS} {flags} -i "{g / "include"}" "{g / path}" -o "{out}"'
        subprocess.run(cmd, shell=True, cwd=g, capture_output=True, timeout=60)
    return out.read_text(encoding="latin-1") if out.exists() else None


def try_internal(f, target, fp, syms, log, style) -> tuple[str, str] | None:
    name, size, addr = f
    tried = 0
    for g, idx in internal_donors():
        for path, d_name, d_addr, d_size, version, flags in idx["entries"].get(fp, []):
            if d_size != size or tried >= 4:
                continue
            tried += 1
            rename, why = internal_rename(g, idx, d_addr, d_name, addr, size, target, syms, name)
            if not rename:
                log(f"  {name}: {g.name}:{d_name} skipped ({why})")
                continue
            pre = internal_preprocessed(g, path, version, flags)
            profiles = [(version, flags)] + alt_profiles(version, flags, style)
            status, source, version, flags = compile_profiles(pre, d_name, rename, name, size, addr, profiles)
            log(f"  {name}: projets/{g.name}:{path}:{d_name} [{version} {flags}] -> {status}")
            if status == "match":
                head = (f"{am.MARKER}{version} {flags} */\n"
                        f"/* {d_name} from projets/{g.name}/{path} (same code in another game of this workspace),"
                        f" reused by tools/donor_match.py */\n")
                return name, head + source
    return None


def try_one(dn, con, f, syms, log, licenses) -> tuple[str, str] | None:
    name, size, addr = f
    target = pc.target_bytes(addr, size)
    fp = donorlib.fingerprint(target)
    if fp is None:
        return None
    inner = inner_entry(addr, size)
    if inner is not None:
        log(f"  {name}: skipped (entry point 0x{inner:08x} inside the function, used elsewhere)")
        return None
    pool = outside_pool_load(target, addr)
    if pool is not None:
        log(f"  {name}: skipped (loads 0x{pool:08x}, a constant pool outside the function: dsd dis cannot split it)")
        return None
    style = am.code_style(addr, size)
    # Our own projects first: their sources already match with our toolchain
    r = try_internal(f, target, fp, syms, log, style)
    if r:
        return r
    rows = [r for r in con.execute("SELECT repo, file, profile, name, size, relocs FROM fn WHERE fp=? AND size=?",
                                   (fp, size)) if r[0] in licenses]
    if not rows:
        return None
    rows.sort(key=lambda r: (not r[2].startswith({"v12": "12", "v20": "20"}.get(style, "")), r[0], r[1]))
    tried = set()
    for row in rows:
        repo, rel, profile, dname = row[:4]
        key = (repo, rel, profile, dname)
        if key in tried or len(tried) >= 6:
            continue
        tried.add(key)
        rename, why = rename_map(dn, row, addr, target, syms, name)
        if not rename:
            log(f"  {name}: {repo}:{dname} skipped ({why})")
            continue
        incs = con.execute("SELECT incs FROM repo WHERE repo=?", (repo,)).fetchone()[0]
        pre = preprocessed(dn, repo, rel, profile, incs)
        # Calls the compiler adds by itself (`_u32_div_f`, `_ddiv`...) are not in the source, so they cannot be
        # renamed to the game's symbol: the link would fail
        implicit = [s for s in rename if pre and not re.search(rf"\b{re.escape(s)}\b", pre)]
        if implicit:
            log(f"  {name}: {repo}:{dname} skipped (implicit runtime call {implicit[0]})")
            continue
        version, flags = dn.PROFILES[profile]
        # The donor's profile first, then the other compilers while the code has the right shape
        profiles = [(version, flags)] + alt_profiles(version, flags, style)
        status, source, version, flags = compile_profiles(pre, dname, rename, name, size, addr, profiles)
        log(f"  {name}: {repo}:{rel}:{dname} [{version} {flags}] -> {status}")
        if status == "match":
            head = (f"{am.MARKER}{version} {flags} */\n"
                    f"/* {dname} from https://github.com/{repo.replace('_', '/', 1)} {rel}"
                    f" (license: {licenses[repo]}), reused by tools/donor_match.py */\n")
            return name, head + source
    return None


def integrate(found: list[tuple[str, int, int, str]]) -> dict[str, tuple[str, str]]:
    """Writes the sources to src/donor/; returns {file: (delinks.txt entry, compilers.txt line)}, in address order.
    Nothing is declared yet: see declare()."""
    DONOR_SRC.mkdir(parents=True, exist_ok=True)
    entries = {}
    for name, size, addr, source in sorted(found, key=lambda x: x[2]):
        path = DONOR_SRC / f"{name}.c"
        path.write_text(source, encoding="utf-8", newline="\n")
        rel = path.relative_to(ROOT).as_posix()
        entries[rel] = (f"\n{rel}:\n    complete\n    .text       start:0x{addr:08x} end:0x{addr + size:08x}\n",
                        f"{rel} {source.split(chr(10), 1)[0][len(am.MARKER):].split('*/')[0].strip()}\n")
    return entries


def declare(entries: dict[str, tuple[str, str]], keep: list[str], sources: dict[str, str], delinks_backup: bytes,
            compilers_backup: bytes) -> None:
    """delinks.txt and compilers.txt = the backups + the entries of `keep`; only the files of `keep` stay in
    src/donor/ (the build compiles every source file, declared or not)."""
    project.DELINKS.write_bytes(delinks_backup)
    project.COMPILERS_TXT.write_bytes(compilers_backup)
    with project.DELINKS.open("a", newline="\n") as f:
        f.writelines(entries[k][0] for k in keep)
    with project.COMPILERS_TXT.open("a", newline="\n") as f:
        f.writelines(entries[k][1] for k in keep)
    for rel, text in sources.items():
        if rel in keep:
            (ROOT / rel).write_text(text, encoding="utf-8", newline="\n")
        else:
            (ROOT / rel).unlink(missing_ok=True)


def run_verify() -> subprocess.CompletedProcess:
    subprocess.run([sys.executable, "tools/configure.py", project.VERSION], cwd=ROOT, check=True, capture_output=True)
    return subprocess.run([sys.executable, "tools/match.py", "verify"], cwd=ROOT, capture_output=True, text=True)


def _note(file: str, rels) -> None:
    WORK.mkdir(parents=True, exist_ok=True)
    with (WORK / file).open("a", encoding="utf-8") as f:
        f.writelines(Path(r).stem + "\n" for r in rels)


def rom_build() -> tuple[bool, str]:
    """configure + ninja: is the ROM byte-identical? Seconds once the objects are built, against minutes for
    `match.py verify` (which also runs objdiff on every file): used for every step but the last."""
    import find_culprits
    out = find_culprits.build()
    return find_culprits.rom_ok(out), out


def verify(entries: dict[str, tuple[str, str]], delinks_backup: bytes, compilers_backup: bytes,
           bisect_builds: int = 40) -> list[str]:
    """Declares the new files and keeps those the ROM accepts:
      1. ninja builds only: the files the build names (link errors, find_culprits: byte differences, linker map)
         are dropped, then the remaining culprits are found by bisection (`bisect_builds` builds at most);
      2. one `match.py verify` once the ROM matches; files objdiff still rejects are dropped.
    Returns the kept files (everything is rolled back if nothing passes)."""
    import find_culprits
    sources = {rel: (ROOT / rel).read_text(encoding="utf-8") for rel in entries}
    keep = list(entries)

    def drop(bad, why):
        nonlocal keep
        print(f"Dropping {len(bad)} file(s) ({why}): " + ", ".join(sorted(bad)[:5]), flush=True)
        _note("culprits.txt", bad)
        keep = [k for k in keep if k not in bad]
        declare(entries, keep, sources, delinks_backup, compilers_backup)

    declare(entries, keep, sources, delinks_backup, compilers_backup)
    ok, out = rom_build()
    for _ in range(4):
        if ok:
            break
        bad = {f"src/donor/{n}.c" for n in re.findall(r'Referenced from "\S+" in (func_\w+?)\.o', out)}
        culprits = find_culprits.find(out)
        for c in culprits:
            print(f"  {c['file']}: {'; '.join(c['reasons'][:2])}", flush=True)
        bad = (bad | {c["file"] for c in culprits}) & set(keep)
        if not bad:
            break
        drop(bad, "the ROM differs")
        ok, out = rom_build()
    if not ok and keep:
        # Before blaming the new files one by one: the ROM must build without them, else every one of them would
        # "fail" alone and be listed as a culprit for nothing
        declare(entries, [], sources, delinks_backup, compilers_backup)
        base_ok, base_out = rom_build()
        if not base_ok:
            print("The ROM does not build even without the new files: fix that first (nothing is blamed).",
                  flush=True)
            for c in find_culprits.find(base_out):
                print(f"  {c['file']}: {'; '.join(c['reasons'][:2])}", flush=True)
            failed = re.findall(r"^FAILED: .*$", base_out, re.M)
            if failed:
                print("  ninja: " + failed[0][:200], flush=True)
            keep = []
    if not ok and keep:
        keep = bisect(entries, keep, sources, delinks_backup, compilers_backup, bisect_builds)
        declare(entries, keep, sources, delinks_backup, compilers_backup)
        ok, out = rom_build() if keep else (False, out)
    v = None
    if ok and keep:
        print(f"ROM OK with {len(keep)} new file(s): full verification (objdiff on every file)...", flush=True)
        for _ in range(4):
            v = run_verify()
            if v.returncode == 0:
                break
            bad = set(re.findall(r"FAIL: (src/donor/\S+?\.c) is marked complete", v.stdout + v.stderr)) & set(keep)
            if not bad:
                break
            drop(bad, "objdiff finds them different once linked")
            if not keep:
                break
    if v is not None:
        print(v.stdout.strip().splitlines()[-1] if v.stdout.strip() else "")
    if v is None or v.returncode != 0 or not keep:
        WORK.mkdir(parents=True, exist_ok=True)
        (WORK / "verify_fail.log").write_text(out if v is None else v.stdout + "\n" + v.stderr, encoding="utf-8")
        print("Verification failed: rolling back (build/donor/verify_fail.log).")
        declare(entries, [], sources, delinks_backup, compilers_backup)
        subprocess.run([sys.executable, "tools/configure.py", project.VERSION], cwd=ROOT, capture_output=True)
        return []
    return keep


def bisect(entries, files: list[str], sources, delinks_backup: bytes, compilers_backup: bytes,
           budget: int) -> list[str]:
    """The largest set of `files` found to keep the ROM byte-identical (ninja builds): a half that passes is kept
    whole, a half that does not is split again, down to single files (the culprits). Files left when the build
    budget is spent are neither kept nor blamed: the next run finds them again."""
    accepted, rejected, untested = [], [], []
    left = [budget]

    def add(group: list[str]):
        if not group:
            return
        if left[0] <= 0:
            untested.extend(group)
            return
        left[0] -= 1
        declare(entries, accepted + group, sources, delinks_backup, compilers_backup)
        print(f"  bisect: {len(accepted)} kept + {len(group)} tested ({left[0]} build(s) left)...", flush=True)
        if rom_build()[0]:
            accepted.extend(group)
        elif len(group) == 1:
            print(f"  bisect: culprit {group[0]}", flush=True)
            rejected.extend(group)
        else:
            add(group[:len(group) // 2])
            add(group[len(group) // 2:])

    print(f"Bisecting {len(files)} file(s) (at most {budget} builds)...", flush=True)
    add(files[:len(files) // 2])  # the whole set is known to fail
    add(files[len(files) // 2:])
    _note("culprits.txt", rejected)
    if untested:
        _note("untested.txt", untested)
        print(f"  {len(untested)} file(s) not tested (build budget spent): they will be found again next run")
    if not accepted and not untested:
        print("  no file passes, even alone: the ROM may already differ without them (run tools/match.py verify)")
    return accepted


def list_hits(con, todo, licenses):
    """build/donor/hits.json: {function: [donor repo, donor function, donor file]} for unmatched functions with a
    donor twin (fingerprint only: not compiled, so not all of them will match)."""
    hits = {}
    for name, size, addr in todo:
        fp = donorlib.fingerprint(pc.target_bytes(addr, size))
        if fp is None:
            continue
        own = [(g, e) for g, idx in internal_donors() for e in idx["entries"].get(fp, []) if e[3] == size]
        if own:
            g, e = own[0]
            hits[name] = ["projets/" + g.name, e[1], e[0]]
            continue
        for repo, rel, dname in con.execute("SELECT repo, file, name FROM fn WHERE fp=? AND size=?", (fp, size)):
            if repo in licenses:
                hits[name] = [repo.replace("_", "/", 1), dname, rel]
                break
    (WORK / "hits.json").write_text(json.dumps(hits, indent=0), encoding="utf-8")
    print(f"{len(hits)} of {len(todo)} unmatched functions have a donor twin (build/donor/hits.json)")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dry-run", action="store_true", help="Only report, change nothing")
    ap.add_argument("-v", action="store_true", help="Print every attempt")
    ap.add_argument("--names", default="", help="Only these functions (comma separated), e.g. the functions of a block")
    ap.add_argument("--max", type=int, default=0, help="Stop after N matches (0 = all): work in small batches")
    ap.add_argument("-j", "--jobs", type=int, default=max(1, (os.cpu_count() or 2) - 2),
                    help="Functions tried in parallel (default: CPU count - 2)")
    ap.add_argument("--bisect", type=int, default=40,
                    help="ninja builds at most to find the files that break the ROM by bisection (0 = roll back instead)")
    ap.add_argument("--list", action="store_true",
                    help="Only list the unmatched functions that have a donor twin (build/donor/hits.json), fast")
    args = ap.parse_args()
    if not DB.exists():
        raise SystemExit(f"No donor database at {DB}: run `python tools/donors.py index` in decomp ds/ first.")
    dn = donor_tools()
    con = sqlite3.connect(DB, timeout=120)
    syms = game_symbols()
    licenses = donor_licenses()
    bad = set((WORK / "culprits.txt").read_text(encoding="utf-8").split()) if (WORK / "culprits.txt").exists() else set()
    todo = [f for f in am.candidates() if f[0] not in bad]
    if args.names:
        wanted = set(args.names.replace(",", " ").split())
        todo = [f for f in todo if f[0] in wanted]
    WORK.mkdir(parents=True, exist_ok=True)
    if args.list:
        list_hits(con, todo, licenses)
        return
    internal_donors()  # indexed once, before the threads
    inner_entry(0, 0)
    local = threading.local()

    def work(f):
        """Runs in a thread: its own database connection, its own log (written in function order at the end)."""
        if not hasattr(local, "con"):
            local.con = sqlite3.connect(DB, timeout=120, check_same_thread=False)
        lines = []
        r = try_one(dn, local.con, f, syms, lines.append, licenses)
        return r, lines

    found, logs = [], {}
    print(f"Looking for donors of {len(todo)} unmatched functions ({args.jobs} in parallel)...", flush=True)
    with ThreadPoolExecutor(max_workers=args.jobs) as ex:
        futures = {ex.submit(work, f): i for i, f in enumerate(todo)}
        for done, fut in enumerate(as_completed(futures), 1):
            f = todo[futures[fut]]
            r, lines = fut.result()
            logs[futures[fut]] = lines
            if args.v:
                print("\n".join(lines), flush=True)
            if r and not (args.max and len(found) >= args.max):
                found.append((f[0], f[1], f[2], r[1]))
                src = r[1].split("\n", 2)[1] if r[1].count("\n") > 1 else ""
                m = re.search(r"from (\S+)", src)
                print(f"  match {len(found)}: {f[0]} <- {m.group(1) if m else '?'}", flush=True)
                if args.max and len(found) >= args.max:
                    print(f"Reached --max {args.max}: the rest is left for the next batch", flush=True)
                    for other in futures:
                        other.cancel()
            if done % 50 == 0:
                print(f"[{done}/{len(todo)}] {len(found)} matches", flush=True)
    log_lines = [l for i in sorted(logs) for l in logs[i]]
    (WORK / "attempts.log").write_text("\n".join(log_lines) + "\n", encoding="utf-8")
    tried = sum(1 for l in log_lines if " -> " in l or "skipped" in l)
    print(f"{len(todo)} unmatched functions, donor attempts logged in build/donor/attempts.log ({tried} lines), "
          f"{len(found)} exact matches")
    if args.dry_run or not found:
        return
    delinks_backup = project.DELINKS.read_bytes()
    compilers_backup = project.COMPILERS_TXT.read_bytes() if project.COMPILERS_TXT.exists() else b""
    # Killed before the end (job cancelled): the next run puts these files back and deletes the new sources
    journal_begin([project.DELINKS, project.COMPILERS_TXT])
    entries = integrate(found)
    journal_created([ROOT / rel for rel in entries])
    # The game repos check clang-format in CI: format now, the verification below covers the formatted files
    try:
        subprocess.run(["pre-commit", "run", "clang-format", "--files", *entries], cwd=ROOT, capture_output=True)
    except OSError:
        print("pre-commit not found: files left unformatted")
    print(f"Added {len(entries)} functions to src/donor/, verifying...", flush=True)
    kept = verify(entries, delinks_backup, compilers_backup, args.bisect)
    journal_end()
    print(f"OK: {len(kept)} functions reused from other decompilations." if kept else "Nothing added.")


if __name__ == "__main__":
    from pipeline_lock import pipeline_lock

    with pipeline_lock("donor_match"):
        main()
