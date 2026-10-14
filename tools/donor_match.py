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
  3. it is compiled with the donor's compiler profile and compared with the ROM; only exact matches are kept,
     and only when the object holds nothing but that function (no string, no extra code);
  4. matches go to src/donor/<name>.c (with the donor's name and file in a comment), are declared `complete` in
     delinks.txt, and `tools/match.py verify` must pass, else the files that break the ROM are dropped
     (find_culprits) or everything is rolled back.
"""
import argparse
import json
import os
import re
import sqlite3
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402
import donorlib  # noqa: E402
import auto_match as am  # noqa: E402
import probe_compiler as pc  # noqa: E402

DS_ROOT = Path(os.environ.get("DS_ROOT", ROOT.parent.parent))  # decomp ds/ (projects live in decomp ds/projets/)
DB = Path(os.environ.get("DONORS_DB", DS_ROOT / "donors.sqlite"))
sys.path.insert(0, str(DS_ROOT / "tools"))
DONOR_SRC = ROOT / "src" / "donor"
WORK = ROOT / "build" / "donor"
SYM_RE = re.compile(r"^(\S+) kind:(function|data|bss)\S* addr:0x([0-9a-f]+)")
BRANCH_RELOCS = {donorlib.R_ARM_PC24, donorlib.R_ARM_CALL, donorlib.R_ARM_JUMP24}


def game_symbols() -> dict[int, str]:
    out = {}
    for line in project.SYMBOLS.read_text().splitlines():
        m = SYM_RE.match(line)
        if m:
            addr = int(m.group(3), 16)
            if m.group(2) == "function" or addr not in out:
                out[addr] = m.group(1)
    return out


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
    if not out.exists():
        out.parent.mkdir(parents=True, exist_ok=True)
        mwcc = am.MWCC_ROOT / version / "mwccarm.exe"
        cmd = f'"{mwcc}" -E {pc.BASE_FLAGS} {flags} -i "{g / "include"}" "{g / path}" -o "{out}"'
        subprocess.run(cmd, shell=True, cwd=g, capture_output=True, timeout=60)
    return out.read_text(encoding="latin-1") if out.exists() else None


def try_internal(f, target, fp, syms, log) -> tuple[str, str] | None:
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
            status = "source not rebuilt"
            for minimal in (True, False):
                source = donorlib.candidate_source(pre, d_name, rename, minimal) if pre else None
                if source is None:
                    break
                with tempfile.TemporaryDirectory() as tmp:
                    t = Path(tmp)
                    status = am.compile_and_compare(t, source, name, size, addr, am.MWCC_ROOT / version / "mwccarm.exe",
                                                    flags)
                    if status == "match" and not only_function(t / "f.o", name):
                        status = "extra code or data"
                if status == "match":
                    break
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
    # Our own projects first: their sources already match with our toolchain
    r = try_internal(f, target, fp, syms, log)
    if r:
        return r
    rows = [r for r in con.execute("SELECT repo, file, profile, name, size, relocs FROM fn WHERE fp=? AND size=?",
                                   (fp, size)) if r[0] in licenses]
    if not rows:
        return None
    style = am.code_style(addr, size)
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
        status = "source not rebuilt"
        # Only the declarations the function needs first (readable file), else the whole file's declarations
        for minimal in (True, False):
            source = donorlib.candidate_source(pre, dname, rename, minimal) if pre else None
            if source is None:
                break
            with tempfile.TemporaryDirectory() as tmp:
                t = Path(tmp)
                status = am.compile_and_compare(t, source, name, size, addr, dn.MWCC_ROOT / version / "mwccarm.exe",
                                                flags)
                if status == "match" and not only_function(t / "f.o", name):
                    status = "extra code or data"
            if status == "match":
                break
        log(f"  {name}: {repo}:{rel}:{dname} [{profile}] -> {status}")
        if status == "match":
            head = (f"{am.MARKER}{version} {flags} */\n"
                    f"/* {dname} from https://github.com/{repo.replace('_', '/', 1)} {rel}"
                    f" (license: {licenses[repo]}), reused by tools/donor_match.py */\n")
            return name, head + source
    return None


def integrate(found: list[tuple[str, int, int, str]]) -> list[Path]:
    DONOR_SRC.mkdir(parents=True, exist_ok=True)
    created, entries, overrides = [], [], []
    for name, size, addr, source in sorted(found, key=lambda x: x[2]):
        path = DONOR_SRC / f"{name}.c"
        path.write_text(source, encoding="utf-8", newline="\n")
        created.append(path)
        rel = path.relative_to(ROOT).as_posix()
        entries.append(f"\n{rel}:\n    complete\n    .text       start:0x{addr:08x} end:0x{addr + size:08x}\n")
        overrides.append(f"{rel} {source.split(chr(10), 1)[0][len(am.MARKER):].split('*/')[0].strip()}\n")
    with project.DELINKS.open("a", newline="\n") as f:
        f.writelines(entries)
    with project.COMPILERS_TXT.open("a", newline="\n") as f:
        f.writelines(overrides)
    return created


def verify(created: list[Path], delinks_backup: bytes, compilers_backup: bytes) -> list[Path]:
    """configure + verify; drops the files that break the ROM, or rolls everything back. Returns the kept files."""
    def run_verify():
        subprocess.run([sys.executable, "tools/configure.py", project.VERSION], cwd=ROOT, check=True, capture_output=True)
        return subprocess.run([sys.executable, "tools/match.py", "verify"], cwd=ROOT, capture_output=True, text=True)

    v = run_verify()
    for _ in range(8):
        # Files that do not link, or that objdiff finds different once linked (a relocation to another symbol):
        # drop them and verify again, the others stay
        out = v.stdout + v.stderr
        bad = set(re.findall(r"FAIL: (src/donor/\S+?\.c) is marked complete", out))
        bad |= {f"src/donor/{n}.c" for n in re.findall(r'Referenced from "\S+" in (func_\w+?)\.o', out)}
        bad &= {c.relative_to(ROOT).as_posix() for c in created}
        if v.returncode == 0 or not bad:
            break
        print(f"Dropping {len(bad)} file(s) that do not match once linked: " + ", ".join(sorted(bad)[:5]), flush=True)
        text = project.DELINKS.read_text()
        for rel in bad:
            text = re.sub(r"\n" + re.escape(rel) + r":\n    complete\n    \.text[^\n]*\n", "\n", text)
            (ROOT / rel).unlink(missing_ok=True)
        project.DELINKS.write_text(text, newline="\n")
        keep = [l for l in project.COMPILERS_TXT.read_text().splitlines(True) if l.split(" ")[0] not in bad]
        project.COMPILERS_TXT.write_text("".join(keep), newline="\n")
        WORK.mkdir(parents=True, exist_ok=True)
        with (WORK / "culprits.txt").open("a", encoding="utf-8") as f:
            f.writelines(Path(b).stem + "\n" for b in bad)
        created = [c for c in created if c.relative_to(ROOT).as_posix() not in bad]
        v = run_verify()
    if v.returncode != 0:
        import find_culprits
        print("Verification failed: looking for the files that break the ROM...", flush=True)
        new = {c.relative_to(ROOT).as_posix() for c in created}
        ok, dropped = find_culprits.repair(allowed=new, log=lambda m: print(m, flush=True))
        created = [c for c in created if c.relative_to(ROOT).as_posix() not in dropped]
        if dropped:
            WORK.mkdir(parents=True, exist_ok=True)
            with (WORK / "culprits.txt").open("a", encoding="utf-8") as f:
                f.writelines(Path(d).stem + "\n" for d in dropped)
        if ok:
            v = run_verify()
    print(v.stdout.strip().splitlines()[-1] if v.stdout.strip() else "")
    if v.returncode != 0:
        WORK.mkdir(parents=True, exist_ok=True)
        (WORK / "verify_fail.log").write_text(v.stdout + "\n" + v.stderr, encoding="utf-8")
        print("Verification failed: rolling back.")
        project.DELINKS.write_bytes(delinks_backup)
        project.COMPILERS_TXT.write_bytes(compilers_backup)
        for p in created:
            p.unlink(missing_ok=True)
        subprocess.run([sys.executable, "tools/configure.py", project.VERSION], cwd=ROOT, capture_output=True)
        return []
    return created


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
    log_lines = []

    def log(m):
        log_lines.append(m)
        if args.v:
            print(m, flush=True)

    found = []
    print(f"Looking for donors of {len(todo)} unmatched functions...", flush=True)
    for i, f in enumerate(todo):
        r = try_one(dn, con, f, syms, log, licenses)
        if r:
            found.append((f[0], f[1], f[2], r[1]))
            src = r[1].split("\n", 2)[1] if r[1].count("\n") > 1 else ""
            m = re.search(r"from (\S+)", src)
            print(f"  match {len(found)}: {f[0]} <- {m.group(1) if m else '?'}", flush=True)
            if args.max and len(found) >= args.max:
                print(f"Reached --max {args.max}: the rest is left for the next batch", flush=True)
                break
        if i % 50 == 49:
            print(f"[{i + 1}/{len(todo)}] {len(found)} matches", flush=True)
    (WORK / "attempts.log").write_text("\n".join(log_lines) + "\n", encoding="utf-8")
    tried = sum(1 for l in log_lines if " -> " in l or "skipped" in l)
    print(f"{len(todo)} unmatched functions, donor attempts logged in build/donor/attempts.log ({tried} lines), "
          f"{len(found)} exact matches")
    if args.dry_run or not found:
        return
    delinks_backup = project.DELINKS.read_bytes()
    compilers_backup = project.COMPILERS_TXT.read_bytes() if project.COMPILERS_TXT.exists() else b""
    created = integrate(found)
    # The game repos check clang-format in CI: format now, the verification below covers the formatted files
    try:
        subprocess.run(["pre-commit", "run", "clang-format", "--files", *[str(c.relative_to(ROOT)) for c in created]],
                       cwd=ROOT, capture_output=True)
    except OSError:
        print("pre-commit not found: files left unformatted")
    print(f"Added {len(created)} functions to src/donor/, verifying...", flush=True)
    kept = verify(created, delinks_backup, compilers_backup)
    print(f"OK: {len(kept)} functions reused from other decompilations." if kept else "Nothing added.")


if __name__ == "__main__":
    from pipeline_lock import pipeline_lock

    with pipeline_lock("donor_match"):
        main()
