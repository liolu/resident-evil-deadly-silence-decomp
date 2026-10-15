#!/usr/bin/env python3
"""Gives real names to the functions and data of the game: NitroSDK, NitroSystem, MSL... names taken from the other
public DS decompilations ("donors", `decomp ds/donors.sqlite`), matched or not.

    python tools/names.py              # find the names, rename, check that the ROM still rebuilds
    python tools/names.py --dry-run    # only write the table build/names/names.tsv

How a name is found, for every function of the ARM9 main module, ITCM and DTCM that still has a generated name
(func_02001234, data_020b5f40):
  1. its fingerprint (donorlib.py: same instructions, only called functions and loaded addresses may differ) is
     looked up in the donor database. Each donor function with that fingerprint is a vote for its name, weighted by
     where it comes from (ntrtwl's SDK decompilations > library folders of other games > game code of other games);
  2. the donor objects also say WHAT each call and each pool word points to (their relocations, e.g. "the bl at +8
     calls NNSi_FndFinalizeHeap"). Read at the same offsets in the game, they name the callees and the data too, and
     they decide between donors that share a fingerprint (a small wrapper looks the same whatever it calls: the right
     name is the one whose callees agree with the names already found). This is repeated until nothing changes;
  3. a name is kept only if it wins clearly (twice the votes of the next one), is a C identifier, not generated
     (func_/FUN_/sub_/ov012_...), and not used anywhere else in the game. Tiny functions need a confirmation by
     their callees, or a library donor.

Renaming = symbols.txt, every source and header (whole words), the file names (src/auto/func_02001234.c ->
src/auto/OS_DisableIrq.c, in delinks.txt and compilers.txt too) and the Studio blocks (.studio/blocks.json). The
names do not change the code, but a new name can clash inside a source file (e.g. `memset` against a header):
the ROM is rebuilt (configure + ninja, like find_culprits.py) and the names used by the files that break it are
given up, until it matches. Names that were given up are kept in build/names/rejected.txt and never tried again.
Nothing is committed.
"""
import argparse
import collections
import json
import os
import re
import sqlite3
import struct
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
WORK = ROOT / "build" / "names"
SYM_LINE = re.compile(r"^(\S+) kind:(function|data|bss)(?:\((\w+)(?:,size=0x([0-9a-f]+))?[^)]*\))? addr:0x([0-9a-f]+)")
GENERATED = re.compile(r"^(func|data|bss|FUN|DAT|sub|fn|thunk|LAB|unk|UNK|lbl|jumptable)_|^[Oo]v(l)?\d+_"
                       r"|_(0x)?[0-9a-fA-F]{7,8}$|^[A-Za-z]{0,4}[0-9a-fA-F]{8}$")
IDENT = re.compile(r"^[A-Za-z_][A-Za-z0-9_]*$")
C_WORDS = set("""auto break case char const continue default do double else enum extern float for goto if inline int
long register restrict return short signed sizeof static struct switch typedef union unsigned void volatile while asm
main NULL TRUE FALSE BOOL""".split())
LIB_PATH = re.compile(r"(^|/)(libs?|libraries|sdk|nitro|nns|nnsys|msl|MSL\w*|runtime|NitroSDK|NitroSystem|"
                      r"NitroWiFi|NitroDWC|dwc|wifi|libvct|crt0|ansi)(/|$)", re.I)
BRANCHES = {donorlib.R_ARM_PC24, donorlib.R_ARM_CALL, donorlib.R_ARM_JUMP24}
MIN_SIZE_ALONE = 0x20  # smaller twins need their callees to agree


GAME_PATH = re.compile(r"(^|/)(ov|overlay)_?\d+(/|_|$)|(^|/)(game|poke_net|pokemon|pm_\w+)(/|$)", re.I)


def weight(repo: str, path: str, name: str) -> int:
    """How much a donor's name is trusted. 0: the code of another game (its names describe that game)."""
    if repo.startswith("ntrtwl_"):
        return 6  # the SDK itself, with Nintendo's names
    if GAME_PATH.search(path):
        return 0
    if LIB_PATH.search(path) or name.startswith("_") or "asm_stubs" in path:
        return 3  # library folders; `_name` identifiers are reserved to the compiler and the C library
    return 0


def usable(name: str) -> bool:
    return bool(IDENT.match(name)) and not GENERATED.search(name) and name not in C_WORDS and len(name) <= 80


# ---------------------------------------------------------------- the game

class Module:
    def __init__(self, name: str, symbols: Path, binary: Path, base: int):
        self.name, self.symbols, self.base = name, symbols, base
        self.data = binary.read_bytes()
        self.syms = {}  # address -> [name, kind, mode, size]
        for line in symbols.read_text(encoding="utf-8", errors="replace").splitlines():
            m = SYM_LINE.match(line)
            if m:
                a = int(m.group(5), 16)
                if a not in self.syms or m.group(2) == "function":
                    self.syms[a] = [m.group(1), m.group(2), m.group(3) or "", int(m.group(4) or "0", 16)]

    def contains(self, addr: int) -> bool:
        return self.base <= addr < self.base + len(self.data)

    def code(self, addr: int, size: int) -> bytes:
        return self.data[addr - self.base: addr - self.base + size]


def game_modules() -> list[Module]:
    """Main module, ITCM and DTCM: they are loaded together, so their addresses never overlap (overlays do)."""
    ex = project.EXTRACT / "arm9"
    out = []
    for name, sym, binp, yml in (("main", project.ARM9 / "symbols.txt", ex / "arm9.bin", ex / "arm9.yaml"),
                                 ("itcm", project.ARM9 / "itcm" / "symbols.txt", ex / "itcm.bin", ex / "itcm.yaml"),
                                 ("dtcm", project.ARM9 / "dtcm" / "symbols.txt", ex / "dtcm.bin", ex / "dtcm.yaml")):
        base = fc.base_address(yml)
        if sym.exists() and binp.exists() and base is not None:
            out.append(Module(name, sym, binp, base))
    return out


def all_symbol_names() -> set[str]:
    names = set()
    for p in project.CONFIG.rglob("symbols.txt"):
        names |= {l.split(" ", 1)[0] for l in p.read_text(encoding="utf-8", errors="replace").splitlines() if l}
    return names


def reloc_target(mod: Module, faddr: int, off: int, rtype: int, addend: int) -> int | None:
    """What the game's code at function+off points to, for a donor relocation of that type at that offset."""
    w = mod.code(faddr + off, 4)
    if len(w) < 4:
        return None
    w, = struct.unpack("<I", w)
    if rtype == donorlib.R_ARM_ABS32:
        return (w - addend) & 0xFFFFFFFF
    if rtype in BRANCHES and (w & 0x0E000000) == 0x0A000000:
        simm = w & 0xFFFFFF
        if simm & 0x800000:
            simm -= 1 << 24
        t = faddr + off + 8 + simm * 4
        if (w >> 28) == 0xF:  # blx to Thumb
            t += ((w >> 24) & 1) * 2
        return t
    return None


# ---------------------------------------------------------------- finding the names

def find_names(mods: list[Module], con, log=print, rounds: int = 6) -> dict[int, tuple[str, str, float]]:
    """{address: (name, origin, score)} of the generated-name symbols that get a donor name."""
    owner = {}  # address -> module
    for m in mods:
        for a in m.syms:
            owner[a] = m
    known = {a: m.syms[a][0] for m in mods for a in m.syms if usable(m.syms[a][0])}  # real names already there
    taken = set(known.values())
    # candidates of every generated-name ARM function: name -> [(weight, repo/file, relocs)]
    cands = {}
    for m in mods:
        for a, (name, kind, mode, size) in m.syms.items():
            if kind != "function" or mode != "arm" or usable(name) or size < 12:
                continue
            fp = donorlib.fingerprint(m.code(a, size))
            if not fp:
                continue
            by = {}
            seen = set()
            for repo, rel, dname, relocs in con.execute("SELECT repo, file, name, relocs FROM fn WHERE fp=? AND size=?",
                                                         (fp, size)):
                w = weight(repo, rel, dname)
                if not w or not usable(dname) or (repo, dname) in seen:
                    continue
                seen.add((repo, dname))
                by.setdefault(dname, []).append((w, f"{repo.replace('_', '/', 1)}:{rel}",
                                                 json.loads(relocs or "[]")))
            if by:
                cands[a] = by
    log(f"{len(cands)} functions with a generated name have donor twins")

    found = {}  # address -> (name, origin, score)
    for rnd in range(rounds):
        names = dict(known)
        names.update({a: v[0] for a, v in found.items()})
        new = {}
        votes = collections.defaultdict(lambda: collections.defaultdict(float))  # addr -> name -> score
        origin = {}
        for a, by in cands.items():
            m = owner[a]
            size = m.syms[a][3]
            scored = []
            for dname, rows in by.items():
                best = None
                for w, where, relocs in rows:
                    agree = clash = 0
                    for off, rtype, sym, add in relocs:
                        t = reloc_target(m, a, off, rtype, add)
                        if t is None or t not in names:
                            continue
                        if names[t] == sym:
                            agree += 1
                        elif usable(sym):
                            clash += 1
                    if clash > agree:
                        continue
                    s = (w, agree, where, relocs)
                    if best is None or (agree, w) > (best[1], best[0]):
                        best = s
                if best:
                    total = sum(r[0] for r in rows) * (1 + best[1])
                    scored.append((total, dname, best))
            if not scored:
                continue
            scored.sort(reverse=True)
            top, dname, (w, agree, where, relocs) = scored[0]
            second = scored[1][0] if len(scored) > 1 else 0
            # a small function looks like many others (a getter, a wrapper): its callees must confirm the name
            if top < 2 * second or (size < MIN_SIZE_ALONE and not agree):
                continue
            votes[a][dname] += top
            origin[(a, dname)] = where
            # what this donor's code calls and loads names the game's targets too
            for off, rtype, sym, add in relocs:
                t = reloc_target(m, a, off, rtype, add)
                if t is None or not usable(sym) or t not in owner or owner[t].syms[t][1] == "function" and \
                        owner[t].syms[t][2] == "thumb" and rtype not in BRANCHES:
                    continue
                if usable(owner[t].syms[t][0]):
                    continue
                votes[t][sym] += w * 0.5
                origin.setdefault((t, sym), f"{where} (used by {dname})")
        for t, by in votes.items():
            ranked = sorted(by.items(), key=lambda kv: -kv[1])
            name, score = ranked[0]
            if len(ranked) > 1 and score < 2 * ranked[1][1]:
                continue
            new[t] = (name, origin[(t, name)], score)
        # one name, one address: the best score keeps it; names that already exist elsewhere are refused
        by_name = {}
        for t, (name, where, score) in new.items():
            if name in taken:
                continue
            if name not in by_name or score > new[by_name[name]][2]:
                by_name[name] = t
        new = {t: new[t] for t in by_name.values()}
        changed = {t: v[0] for t, v in new.items()} != {t: v[0] for t, v in found.items()}
        found = new
        log(f"  round {rnd + 1}: {len(found)} names")
        if not changed:
            break
    return found


# ---------------------------------------------------------------- renaming

def source_files() -> list[Path]:
    out = []
    for d in ("src", "include", "libs"):
        p = ROOT / d
        if p.exists():
            out += [f for f in p.rglob("*") if f.suffix in (".c", ".h", ".cpp", ".hpp", ".s", ".inc") and f.is_file()]
    return out


def word_re(names) -> re.Pattern:
    return re.compile(r"\b(" + "|".join(sorted(map(re.escape, names), key=len, reverse=True)) + r")\b")


def apply(renames: dict[str, str], dry: bool = False) -> tuple[dict[Path, bytes], list[Path], dict[str, list[str]]]:
    """Renames everywhere. Returns (original contents of every changed file, files created, names used per source
    file) so it can be undone."""
    saved, created, uses = {}, [], {}
    if not renames:
        return saved, created, uses
    rx = word_re(renames)

    def sub(text):
        return rx.sub(lambda m: renames[m.group(1)], text)

    for p in project.CONFIG.rglob("symbols.txt"):
        t = p.read_text(encoding="utf-8")
        n = re.sub(r"^(\S+)(?= kind:)", lambda m: renames.get(m.group(1), m.group(1)), t, flags=re.M)
        if n != t:
            saved[p] = t.encode()
            p.write_text(n, encoding="utf-8", newline="\n")
    # source files: contents, then the file name of one-function files named after their function
    moves = {}
    # the linker names objects by file name only, without folder and case: OS_UnLockCartridge.c in src/donor/
    # and OS_UnlockCartridge.c in src/auto/ would be the same object for it
    lower = {f.stem.lower() for f in source_files()}
    for f in source_files():
        t = f.read_text(encoding="utf-8", errors="surrogateescape")
        used = sorted(set(rx.findall(t)))
        if not used:
            continue
        rel = f.relative_to(ROOT).as_posix()
        saved[f] = f.read_bytes()
        f.write_text(sub(t), encoding="utf-8", errors="surrogateescape", newline="")
        new_stem = renames.get(f.stem)
        if new_stem and f.parent.name in ("auto", "donor"):
            new_rel = f.with_name(new_stem + f.suffix).relative_to(ROOT).as_posix()
            if new_stem.lower() not in lower:
                lower.add(new_stem.lower())
                moves[rel] = new_rel
                uses[new_rel] = used
                continue
        uses[rel] = used
    for old, new in moves.items():
        (ROOT / old).rename(ROOT / new)
        created.append(ROOT / new)
    if moves:
        path_rx = re.compile(r"^(" + "|".join(map(re.escape, moves)) + r")(?=[:\s])", re.M)
        for p in list(project.CONFIG.rglob("delinks.txt")) + [project.COMPILERS_TXT]:
            if p.exists():
                t = p.read_text(encoding="utf-8")
                n = path_rx.sub(lambda m: moves[m.group(1)], t)
                if n != t:
                    saved.setdefault(p, t.encode())
                    p.write_text(n, encoding="utf-8", newline="\n")
    blocks = ROOT / ".studio" / "blocks.json"
    if blocks.exists():
        t = blocks.read_text(encoding="utf-8")
        n = re.sub(r'"([A-Za-z_]\w*)"', lambda m: '"' + renames.get(m.group(1), m.group(1)) + '"', t)
        if n != t:
            saved[blocks] = t.encode()
            blocks.write_text(n, encoding="utf-8", newline="\n")
    return saved, created, uses


def clashes(renames: dict[str, str]) -> set[str]:
    """Old names whose new name already appears in a source file that uses the old one (a donor file can hold the
    original function under its real name, a parameter can have that name...): renaming would break that file."""
    if not renames:
        return set()
    rx = re.compile(r"\b[A-Za-z_]\w*\b")
    out = set()
    for f in source_files():
        idents = set(rx.findall(f.read_text(encoding="utf-8", errors="replace")))
        out |= {old for old in idents & renames.keys() if renames[old] in idents}
    return out


def current_uses(renames: dict[str, str]) -> dict[str, list[str]]:
    """{source file: old names of the renamed symbols it uses now}"""
    back = {v: k for k, v in renames.items()}
    rx = re.compile(r"[A-Za-z_]\w*")
    out = {}
    for f in source_files():
        found = set(rx.findall(f.read_text(encoding="utf-8", errors="replace"))) & back.keys()
        if found:
            out[f.relative_to(ROOT).as_posix()] = sorted(back[n] for n in found)
    return out


def build() -> str:
    """configure + ninja -k 0: every file that does not compile is reported at once."""
    fc.run([sys.executable, "tools/configure.py", project.VERSION])
    r = fc.run(["ninja", "-k", "0"])
    return (r.stdout or "") + (r.stderr or "")


DRAFT_DIRS = ("build/auto/near", "build/drafts", "build/qwen_auto")


def rename_drafts(renames: dict[str, str]) -> int:
    """The work files of auto_match and Qwen (build/auto/near/<name>.c, build/drafts/, build/qwen_auto/) are looked
    up by function name and call other functions by name: they follow the renames too, file names included.
    build/donor/hits.json (the Studio's "Portable" level) too. Returns the number of files changed."""
    if not renames:
        return 0
    rx = word_re(renames)
    n = 0
    for d in DRAFT_DIRS:
        folder = ROOT / d
        for f in sorted(folder.glob("*.c")) if folder.exists() else []:
            t = f.read_text(encoding="utf-8", errors="surrogateescape")
            new_t = rx.sub(lambda m: renames[m.group(1)], t)
            dest = f.with_name(renames[f.stem] + ".c") if f.stem in renames else f
            if new_t == t and dest == f:
                continue
            if dest != f and dest.exists():
                continue  # a draft under the new name already exists: keep it
            dest.write_text(new_t, encoding="utf-8", errors="surrogateescape", newline="")
            if dest != f:
                f.unlink()
            n += 1
    hits = ROOT / "build" / "donor" / "hits.json"
    if hits.exists():
        try:
            d = json.loads(hits.read_text(encoding="utf-8"))
            hits.write_text(json.dumps({renames.get(k, k): v for k, v in d.items()}, indent=0), encoding="utf-8")
        except ValueError:
            pass
    return n


def all_renamed() -> dict[str, str]:
    """Every rename of the past runs (build/names/renamed.tsv), chained: func_x -> A -> B gives func_x -> B."""
    f = WORK / "renamed.tsv"
    out = {}
    for line in f.read_text(encoding="utf-8").splitlines() if f.exists() else []:
        if "\t" in line:
            old, new = line.split("\t", 1)
            for k, v in out.items():
                if v == old:
                    out[k] = new
            out[old] = new
    return out


def sources_of(paths) -> list:
    return [p for p in paths if ROOT / "src" in Path(p).parents or ROOT / "include" in Path(p).parents]


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


def undo(saved: dict[Path, bytes], created: list[Path]) -> None:
    for p in created:
        p.unlink(missing_ok=True)
    for p, b in saved.items():
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_bytes(b)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dry-run", action="store_true", help="Only write build/names/names.tsv")
    ap.add_argument("--max", type=int, default=0, help="Rename at most N symbols (0 = all)")
    ap.add_argument("--rounds", type=int, default=8, help="Rebuilds at most to give up the names that break the ROM")
    ap.add_argument("--drafts", action="store_true",
                    help="Only rename the work files of auto_match / Qwen after the renames already done")
    args = ap.parse_args()
    if args.drafts:
        WORK.mkdir(parents=True, exist_ok=True)
        print(f"{rename_drafts(all_renamed())} work files renamed")
        return
    if not DB.exists():
        raise SystemExit(f"No donor database at {DB}: run `python tools/donors.py index` in decomp ds/ first.")
    WORK.mkdir(parents=True, exist_ok=True)
    rejected_file = WORK / "rejected.txt"
    rejected = set(rejected_file.read_text(encoding="utf-8").split()) if rejected_file.exists() else set()
    mods = game_modules()
    con = sqlite3.connect(DB, timeout=120)
    found = find_names(mods, con)
    syms = {a: m.syms[a] for m in mods for a in m.syms}
    rows = sorted(found.items())
    with open(WORK / "names.tsv", "w", encoding="utf-8", newline="\n") as f:
        f.write("address\told\tnew\tkind\tscore\tsource\n")
        for a, (name, where, score) in rows:
            f.write(f"0x{a:08x}\t{syms[a][0]}\t{name}\t{syms[a][1]}\t{score:g}\t{where}\n")
    existing = all_symbol_names()
    renames = {syms[a][0]: name for a, (name, where, score) in rows
               if name not in rejected and name not in existing and syms[a][0] not in rejected}
    clash = clashes(renames)
    renames = {k: v for k, v in renames.items() if k not in clash}
    if args.max:
        renames = dict(list(renames.items())[:args.max])
    n_func = sum(1 for a, v in rows if syms[a][1] == "function")
    print(f"{len(rows)} names found ({n_func} functions, {len(rows) - n_func} data), {len(renames)} to apply "
          f"({len(clash)} already used inside a source file) (build/names/names.tsv)")
    if args.dry_run or not renames:
        return
    # Killed before the end: the next tool run puts every file back (pipeline_lock journal)
    touched = list(project.CONFIG.rglob("symbols.txt")) + list(project.CONFIG.rglob("delinks.txt")) + \
        [project.COMPILERS_TXT, ROOT / ".studio" / "blocks.json"] + source_files()
    journal_begin([p for p in touched if p.exists()])
    _saved, created, uses = apply(renames)
    journal_created(created)
    clang_format(sources_of(list(_saved) + created))
    print(f"Renamed {len(renames)} symbols in {len(_saved)} files, rebuilding the ROM...", flush=True)
    try:
        for rnd in range(args.rounds + 1):
            out = build()
            if fc.rom_ok(out):
                break
            (WORK / f"build_fail_{rnd + 1}.log").write_text(out, encoding="utf-8")
            culprits = [c for c in fc.find(out) if c["file"].startswith("src/")]
            for c in culprits:
                print(f"  {c['file']}: {'; '.join(c['reasons'][:2])}")
            for line in [l for l in out.splitlines() if re.search(r"\berror\b", l, re.I)][:10]:
                print("    " + line.strip()[:200])
            # the names the files use, as they are called now (uses: file -> old names)
            bad = {n for c in culprits for n in uses.get(c["file"], [])}
            # `dsd check symbols` names the symbol that is missing from the link: that name alone is the cause,
            # the bytes that differ after it are only its consequence
            back_all = {v: k for k, v in renames.items()}
            missing = {back_all[m] for m in re.findall(r"Symbol '(\S+)' in .*? not found by name", out) if m in back_all}
            if missing:
                bad = missing
            if not bad or rnd == args.rounds:
                print("The ROM does not rebuild and no name can be blamed: every name is put back.")
                print("\n".join(out.splitlines()[-30:]))
                apply({v: k for k, v in renames.items()})
                renames = {}
                break
            # only the files that use these names change again: the next build is incremental
            print(f"  giving up {len(bad)} names used by these files, rebuilding...", flush=True)
            back = {renames[n]: n for n in bad}
            clang_format(sources_of(apply(back)[0]))
            rejected |= set(back)
            renames = {k: v for k, v in renames.items() if k not in bad}
            uses = current_uses(renames)
    finally:
        rejected_file.write_text("\n".join(sorted(rejected)) + ("\n" if rejected else ""), encoding="utf-8")
    journal_end()
    with open(WORK / "renamed.tsv", "a", encoding="utf-8", newline="\n") as f:
        for old, new in renames.items():
            f.write(f"{old}\t{new}\n")
    if not renames:
        sys.exit(1)
    n = rename_drafts(renames)
    print(f"{n} work files of auto_match / Qwen (build/auto/near, build/drafts, build/qwen_auto) follow the renames")
    print(f"OK: {len(renames)} symbols renamed, ROM identical (build/names/renamed.tsv). "
          f"Run `python tools/match.py verify` before committing.")


if __name__ == "__main__":
    from pipeline_lock import pipeline_lock

    if "--dry-run" in sys.argv or "--drafts" in sys.argv:
        main()  # reads only: no need to wait for a running pipeline
    else:
        with pipeline_lock("names"):
            main()
