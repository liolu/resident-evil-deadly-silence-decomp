#!/usr/bin/env python3
"""Merges the one-function source files (src/auto/, src/donor/) into real source files, named after the file the
code comes from: src/auto/OS_CreateThread.c + src/auto/OS_ExitThread.c + ... -> src/nitro/os/os_thread.c.

    python tools/regroup.py              # merge, check that the ROM still rebuilds
    python tools/regroup.py --dry-run    # only write the plan to build/regroup/plan.txt

Run tools/names.py first: the original file of a function is found from its real name in the donor database
(`decomp ds/donors.sqlite`; NitroSDK/NitroSystem names first). Then:
  1. the `complete` files of delinks.txt are walked in address order; neighbours (no gap between them) whose
     functions all come from the same original file and are built with the same compiler become one file;
  2. their texts are merged: the declarations are written once, the function definitions follow in address order,
     the attribution comments of reused files stay above their function. Two files that declare the same name
     differently (m2c's guessed prototypes, a function defined in the group but declared otherwise) are not merged:
     the group is cut there. Files with a #pragma are left alone;
  3. delinks.txt gets one block for the merged range, compilers.txt follows;
  4. the ROM is rebuilt (configure + ninja); merges whose file breaks it are undone, until it matches.
Nothing is committed.
"""
import argparse
import os
import re
import sqlite3
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402
import donorlib  # noqa: E402
import find_culprits as fc  # noqa: E402
from pipeline_lock import journal_begin, journal_created, journal_end  # noqa: E402

DS_ROOT = Path(os.environ.get("DS_ROOT", ROOT.parent.parent))
DB = Path(os.environ.get("DONORS_DB", DS_ROOT / "donors.sqlite"))
WORK = ROOT / "build" / "regroup"
BLOCK_RE = re.compile(r"^(\S+):\n((?:[ \t]+.*\n?)*)", re.M)
FUNC_RE = re.compile(r"^(\S+) kind:function\((?:arm|thumb),size=0x([0-9a-f]+)\) addr:0x([0-9a-f]+)", re.M)
LEAD_COMMENTS = re.compile(r"\A(?:\s*/\*.*?\*/[ \t]*\n?)+", re.S)
COMMENT = re.compile(r"/\*.*?\*/|//[^\n]*", re.S)
MERGEABLE = ("src/auto/", "src/donor/")
# m2c's notes after a declaration ("/* extern */"): the item splitter puts them in front of the NEXT item
M2C_NOTES = re.compile(r"^(?:\s*/\* (?:extern|inferred|irregular|compiler-managed|unused|static)[^*]*\*/)+\s*")
SDK_DIRS = {"ntrtwl_NitroSDK": "nitro", "ntrtwl_NitroSystem": "nnsys", "ntrtwl_NitroWiFi": "wifi",
            "ntrtwl_NitroDWC": "dwc", "ntrtwl_libvct": "vct"}
LIB_HINT = re.compile(r"(^|/)(libs?|libraries|sdk|msl|MSL\w*|runtime|ansi|nitro|nns|nnsys)(/|$)", re.I)
C_LIB = re.compile(r"(^|/)(MSL\w*|msl|c|ansi|math|Runtime|runtime)(/|$)")


_NAMES: dict = {}


def _names_index(con) -> dict[str, list[tuple[str, str]]]:
    """{donor function name: [(repo, file)]}, read once (the database has no index on names)."""
    if not _NAMES:
        _NAMES[""] = []
        for name, repo, f in con.execute("SELECT DISTINCT name, repo, file FROM fn"):
            _NAMES.setdefault(name, []).append((repo, f))
    return _NAMES


def original_file(con, name: str) -> str | None:
    """Where a function is defined in the SDK / libraries, as a path of this game: src/nitro/os/os_thread.c."""
    rows = _names_index(con).get(name, ())
    for repo, f in rows:
        if repo in SDK_DIRS:
            m = re.match(r"(?:libraries|build/libraries)/(\w+)/(?:\w+/)*?src/(.+\.c)$", f)
            if m:
                return f"src/{SDK_DIRS[repo]}/{m.group(1)}/{m.group(2)}"
            return f"src/{SDK_DIRS[repo]}/{Path(f).name}"
    libs = [f for repo, f in rows if LIB_HINT.search(f) and "asm_stubs" not in f]
    if not libs:
        return None
    f = sorted(libs)[0]
    return f"src/{'msl' if C_LIB.search(f) else 'lib'}/{Path(f).name}"


def norm(item: str) -> str:
    return re.sub(r"\s+", " ", COMMENT.sub(" ", item)).strip()


def signature(decl: str) -> str:
    """A function declaration without parameter names, storage class and m2c's type aliases."""
    s = norm(decl).rstrip(";").strip()
    s = re.sub(r"\b(extern|static|inline)\s+", "", s)
    s = re.sub(r"\bM2C_UNK\b", "s32", s).replace("(void)", "()")
    # parameter names: the last word of a parameter, after its type
    s = re.sub(r"(?<=[\w*\s])\b(?!(?:void|const|s32|u32|s16|u16|s8|u8|int|char|long|short)\b)\w+\s*(?=[,)])", "", s)
    return s.replace(" ", "")


def compile_check(text: str, part, compiler: str) -> str:
    """Compiles the merged file like ninja and compares every function with the ROM, at its offset. "" if OK."""
    import tempfile
    import auto_match as am
    import probe_compiler as pc
    import donor_match as dm
    version, *flags = (compiler or default_compiler()).split(None, 1) + [""]
    with tempfile.TemporaryDirectory() as tmp:
        t = Path(tmp)
        (t / "f.c").write_text(text, encoding="utf-8", errors="surrogateescape")
        cmd = (f'"{am.MWCC_ROOT / version / "mwccarm.exe"}" {dm.BUILD_CC_FLAGS} -lang=c {flags[0]} '
               f'-i "{ROOT / "include"}" -d {project.VERSION} -c f.c -o f.o')
        r = am.run_limited(cmd, cwd=t, shell=True, timeout=60)
        if r.returncode != 0 or not (t / "f.o").exists():
            return "does not compile: " + " ".join(((r.stdout or "") + (r.stderr or "")).split())[:300]
        obj = donorlib.Obj(t / "f.o")
        start = part[0].start
        text_size = sum(s[5] for i, s in enumerate(obj.secs) if obj.sec_names[i].startswith(".text"))
        if text_size != part[-1].end - start:
            return f".text is 0x{text_size:x} bytes for 0x{part[-1].end - start:x}"
        extra = [s for s in obj.nonempty_sections() if not s.startswith(".text")]
        if extra:
            return f"extra section {extra[0]}"
        # mwccarm writes one .text section per function; the linker lays them out in the object's order
        place, pos = {}, 0
        for i, s in enumerate(obj.secs):
            if obj.sec_names[i].startswith(".text") and s[5]:
                align = max(s[8], 1)
                pos = (pos + align - 1) // align * align
                place[i] = pos
                pos += s[5]
        syms = {s[0]: s for s in obj.syms}
        for u in part:
            for name in u.funcs:
                a, size = FUNCS[name]
                if name not in syms or syms[name][4] not in place or \
                        place[syms[name][4]] + syms[name][1] != a - start:
                    return f"{name} is not at its place"
                cand = pc.compiled_function(t / "f.o", name)
                if cand is None or pc.compare(pc.target_bytes(a, size), cand)[0]:
                    return f"{name} differs"
    return ""


def default_compiler() -> str:
    m = re.search(r'^MWCC_VERSION\s*=\s*"([^"]+)"', (ROOT / "tools" / "configure.py").read_text(), re.M)
    return m.group(1) if m else "2.0/sp1p5"


FUNCS: dict[str, tuple[int, int]] = {}


class Unit:
    """A `complete` file of delinks.txt."""

    def __init__(self, path: str, body: str):
        self.path, self.body = path, body
        self.secs = {n: (int(s, 16), int(e, 16)) for n, s, e in fc.SECTION_RE.findall(body)}
        self.start, self.end = self.secs.get("text", (0, 0))
        self.funcs: list[str] = []
        self.compiler = ""
        self.key = None


def units(text: str) -> list[Unit]:
    out = []
    for m in BLOCK_RE.finditer(text):
        if m.group(1).startswith("src/") and "complete" in m.group(2).split():
            out.append(Unit(m.group(1), m.group(2)))
    return out


def split_file(text: str) -> tuple[str, list[str]]:
    """(leading comments, top-level items) of a source file."""
    m = LEAD_COMMENTS.match(text)
    lead = m.group(0).strip() if m else ""
    rest = text[m.end():] if m else text
    return lead, donorlib.top_level_items(rest)


def merge(paths: list[str]) -> tuple[str | None, int]:
    """Merged text of the files, or (None, index of the first file that cannot join the ones before it)."""
    decls, seen, defs, by_name = [], set(), [], {}
    compiler_line = None
    for k, p in enumerate(paths):
        text = (ROOT / p).read_text(encoding="utf-8", errors="surrogateescape")
        if "#pragma" in text:
            return None, k
        lead, items = split_file(text)
        notes = []
        for c in re.findall(r"/\*.*?\*/", lead, re.S):
            if c.startswith("/* compiler:"):
                compiler_line = compiler_line or c
            else:
                notes.append(c)
        new_decls, new_defs = [], []
        items = [M2C_NOTES.sub("", it) for it in items]
        for it in items:
            fname = donorlib.function_name(it)
            if fname:
                new_defs.append((fname, it))
                continue
            n = norm(it)
            if n in seen:
                continue
            new_decls.append((n, it))
        # every name gets one declaration text in the whole merged file
        local = {}
        for n, it in new_decls:
            if it.startswith("#"):
                continue
            for name in donorlib.declared_names(it):
                if by_name.get(name, n) != n or local.get(name, n) != n:
                    return None, k
                local[name] = n
        for fname, it in new_defs:  # a function of the group declared otherwise elsewhere in the group
            proto = signature(it[:it.index("{")])
            for d in (by_name.get(fname), local.get(fname)):
                if d and signature(d) != proto:
                    return None, k
        if any(f in {d[0] for d in defs} for f, _ in new_defs):
            return None, k
        by_name.update(local)
        for n, it in new_decls:
            seen.add(n)
            decls.append(it)
        for i, (fname, it) in enumerate(new_defs):
            defs.append((fname, ("\n".join(notes) + "\n" if notes and i == 0 else "") + it))
    head = [compiler_line] if compiler_line else []
    includes = [d for d in decls if d.startswith("#")]
    others = [d for d in decls if not d.startswith("#")]
    out = "\n".join(head + includes) + ("\n\n" if head or includes else "")
    out += "\n".join(others) + ("\n\n" if others else "")
    out += "\n\n".join(it for _, it in defs) + "\n"
    return out, len(paths)


def plan(con) -> list[tuple[str, list[Unit]]]:
    """[(new path, units)] of the merges / moves to do in the main module."""
    text = project.DELINKS.read_text(encoding="utf-8")
    us = sorted((u for u in units(text) if set(u.secs) == {"text"}), key=lambda u: u.start)
    funcs = sorted((int(a, 16), int(s, 16), n) for n, s, a in FUNC_RE.findall(project.SYMBOLS.read_text()))
    FUNCS.update({n: (a, s) for a, s, n in funcs})
    comp = {}
    if project.COMPILERS_TXT.exists():
        for line in project.COMPILERS_TXT.read_text(encoding="utf-8").splitlines():
            line = line.split("#", 1)[0].strip()
            if line:
                p, rest = line.split(None, 1)
                comp[p] = rest.strip()
    for u in us:
        u.funcs = [n for a, s, n in funcs if u.start <= a < u.end]
        u.compiler = comp.get(u.path, "")
        if u.path.startswith(MERGEABLE) and u.funcs:
            keys = {original_file(con, n) for n in u.funcs}
            u.key = keys.pop() if len(keys) == 1 else None
    runs, cur = [], []
    for u in us:
        if cur and (u.key is None or u.key != cur[-1].key or u.start != cur[-1].end):
            runs.append(cur)
            cur = []
        if u.key:
            cur.append(u)
    if cur:
        runs.append(cur)
    out = []
    for run in runs:
        while run:
            merged, n = merge([u.path for u in run])
            part, run = run[:max(n, 1)], run[max(n, 1):]
            # n: how many files merge together from the start of the run; 0 = the first one cannot even be
            # read as a group of one (#pragma): it stays where it is
            if n:
                out.append(part)
    return out


def settle(part: list[Unit]) -> list[tuple[list[Unit], str, str]]:
    """[(units, merged text, compiler)] that compile to the ROM's bytes: the whole run with one of its members'
    compilers if possible, else its two halves, recursively. A single file is kept as it is (only moved)."""
    text, _n = merge([u.path for u in part])
    if len(part) == 1:
        return [(part, text, part[0].compiler)]
    for comp in dict.fromkeys(u.compiler for u in part):
        if not compile_check(text, part, comp):
            return [(part, text, comp)]
    half = len(part) // 2
    return settle(part[:half]) + settle(part[half:])


def name_groups(settled, taken: set[str]) -> list[tuple[str, list[Unit], str, str]]:
    """Paths of the new files: the original file's path, then _2, _3... for its other pieces (the linker knows an
    object by its file name only, without folder or case: stems are unique in the whole game)."""
    out = []
    for part, text, comp in settled:
        base = new = part[0].key
        k = 2
        while Path(new).stem.lower() in taken and not (len(part) == 1 and part[0].path.lower() == new.lower()):
            new = f"{base[:-2]}_{k}.c"
            k += 1
        taken.add(Path(new).stem.lower())
        out.append((new, part, text, comp))
    return out


def apply(groups, log=print) -> tuple[dict[Path, bytes], list[Path]]:
    saved, created = {}, []
    delinks = project.DELINKS.read_text(encoding="utf-8")
    saved[project.DELINKS] = delinks.encode()
    comp = project.COMPILERS_TXT.read_text(encoding="utf-8") if project.COMPILERS_TXT.exists() else ""
    if project.COMPILERS_TXT.exists():
        saved[project.COMPILERS_TXT] = comp.encode()
    for new, part, text, compiler in groups:
        for u in part:
            p = ROOT / u.path
            saved[p] = p.read_bytes()
        for u in part:
            (ROOT / u.path).unlink()
        dest = ROOT / new
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_text(text, encoding="utf-8", errors="surrogateescape", newline="\n")
        created.append(dest)
        block = f"{new}:\n    complete\n    .text       start:0x{part[0].start:08x} end:0x{part[-1].end:08x}\n"
        first = True
        for u in part:
            rx = re.compile(r"^" + re.escape(u.path) + r":\n(?:[ \t]+.*\n?)*", re.M)
            delinks = rx.sub(lambda m: block if first else "", delinks, count=1)
            first = False
        lines = [l for l in comp.splitlines() if l.split(" ")[0] not in {u.path for u in part}]
        if compiler:
            lines.append(f"{new} {compiler}")
        comp = "\n".join(lines) + "\n" if lines else ""
    project.DELINKS.write_text(re.sub(r"\n{3,}", "\n\n", delinks), encoding="utf-8", newline="\n")
    if project.COMPILERS_TXT.exists():
        project.COMPILERS_TXT.write_text(comp, encoding="utf-8", newline="\n")
    return saved, created


def clang_format(paths) -> None:
    """The game repos check clang-format in CI: a longer name or a merge changes the layout of the file."""
    import subprocess
    rels = sorted({Path(p).resolve().relative_to(ROOT).as_posix() for p in paths
                   if Path(p).exists() and Path(p).suffix in (".c", ".h", ".cpp", ".hpp")})
    try:
        for k in range(0, len(rels), 200):
            subprocess.run(["pre-commit", "run", "clang-format", "--files", *rels[k:k + 200]], cwd=ROOT,
                           capture_output=True)
    except OSError:
        print("pre-commit not found: files left unformatted")


def undo(saved, created):
    for p in created:
        p.unlink(missing_ok=True)
    for p, b in saved.items():
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_bytes(b)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dry-run", action="store_true", help="Only write build/regroup/plan.txt")
    ap.add_argument("--rounds", type=int, default=8, help="Rebuilds at most to undo the merges that break the ROM")
    args = ap.parse_args()
    if not DB.exists():
        raise SystemExit(f"No donor database at {DB}: run `python tools/donors.py index` in decomp ds/ first.")
    WORK.mkdir(parents=True, exist_ok=True)
    rejected_file = WORK / "rejected.txt"
    rejected = set(rejected_file.read_text(encoding="utf-8").split()) if rejected_file.exists() else set()
    con = sqlite3.connect(DB, timeout=120)
    runs = plan(con)
    # every merged file is compiled like ninja would and compared with the ROM before anything is written; a run
    # that does not match is cut in two until its pieces do
    from concurrent.futures import ThreadPoolExecutor
    with ThreadPoolExecutor(max_workers=max(1, (os.cpu_count() or 2) - 2)) as ex:
        settled = [g for r in ex.map(settle, runs) for g in r]
    taken = {Path(u.path).stem.lower() for u in units(project.DELINKS.read_text(encoding="utf-8"))}
    groups = [g for g in name_groups(settled, taken)
              if g[0] not in rejected and not (len(g[1]) == 1 and g[1][0].path == g[0])]
    print(f"{len(runs)} runs of neighbour files from the same original file, {len(settled)} files after the "
          f"compile check")
    with open(WORK / "plan.txt", "w", encoding="utf-8", newline="\n") as f:
        for new, part, _t, _c in groups:
            f.write(f"{new}  <- {len(part)} files, {sum(len(u.funcs) for u in part)} functions, "
                    f"0x{part[0].start:08x}-0x{part[-1].end:08x}\n")
            for u in part:
                f.write(f"    {u.path}: {', '.join(u.funcs)}\n")
    n_files = sum(len(g[1]) for g in groups)
    print(f"{len(groups)} files to write from {n_files} files (build/regroup/plan.txt)")
    if args.dry_run or not groups:
        return
    journal_begin([project.DELINKS, project.COMPILERS_TXT] + [ROOT / u.path for g in groups for u in g[1]])
    try:
        for rnd in range(args.rounds + 1):
            saved, created = apply(groups)
            journal_created(created)
            clang_format(created)
            print(f"Wrote {len(created)} files, rebuilding the ROM...", flush=True)
            out = fc.build()
            if fc.rom_ok(out):
                break
            culprits = {c["file"] for c in fc.find(out) if c["file"].startswith("src/")}
            for c in sorted(culprits):
                print(f"  breaks the ROM: {c}")
            undo(saved, created)
            bad = {g[0] for g in groups if g[0] in culprits}
            if not bad or rnd == args.rounds:
                print("The ROM does not rebuild and no merge can be blamed: everything was put back.")
                print("\n".join(out.splitlines()[-30:]))
                journal_end()
                sys.exit(1)
            rejected |= bad
            groups = [g for g in groups if g[0] not in bad]
            if not groups:
                print("No merge left.")
                break
    finally:
        rejected_file.write_text("\n".join(sorted(rejected)) + ("\n" if rejected else ""), encoding="utf-8")
    journal_end()
    print(f"OK: {len(groups)} real files, ROM identical. Run `python tools/match.py verify` before committing.")


if __name__ == "__main__":
    from pipeline_lock import pipeline_lock

    if "--dry-run" in sys.argv:
        main()
    else:
        with pipeline_lock("regroup"):
            main()
