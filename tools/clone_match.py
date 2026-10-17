#!/usr/bin/env python3
"""Matches several functions at once, without any AI, by reusing functions that already match.

    python tools/clone_match.py                    # find, compile, integrate (src/auto/), verify
    python tools/clone_match.py --list             # only write build/clone/families.json (nothing changes)
    python tools/clone_match.py --sources a,b      # only clone from these functions (right after they matched)
    python tools/clone_match.py --other-games      # also take sources from the other projects next to this one
    python tools/clone_match.py --dry-run          # compile and report, change nothing

An unmatched function can be the twin of a matched one:
  dup       same machine code once calls and loaded addresses are masked (copy-paste, getters/setters, generated
            code): the C is copied, the function and what it calls / loads are renamed;
  template  same instructions, only immediates differ (constants, struct offsets): the C constants are replaced
            too (every combination when a constant is ambiguous);
  game      the same code already matched in another of our projects (--other-games): 1 match there = 1 match here.
Each candidate is compiled as ninja will compile it (configure.py flags + the source's compiler) and compared word
for word with the ROM, calls and loaded addresses included (relocations of the object). Matches found in a round
become sources of the next round. Then they go to src/auto/ + delinks.txt, and `match.py verify` checks the ROM
(files that break it are removed with find_culprits, like auto_match does).
"""
import argparse
import ast
import hashlib
import itertools
import json
import os
import re
import struct
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402
import donorlib  # noqa: E402
import auto_match as am  # noqa: E402
from pipeline_lock import journal_begin, journal_created, journal_end  # noqa: E402

WORK = ROOT / "build" / "clone"
FAMILIES = WORK / "families.json"
ARM9_BASE = 0x02000000
FUNC_RE = re.compile(r"^(\S+) kind:function\(arm,size=0x([0-9a-f]+)\).*?addr:0x([0-9a-f]+)", re.M)
SYM_RE = re.compile(r"^(\S+) kind:(function|data|bss)\S* addr:0x([0-9a-f]+)", re.M)
DELINK_RE = re.compile(r"^(src/\S+):\n((?:[ \t]+\S.*\n?)+)", re.M)
TEXT_RE = re.compile(r"\.text\s+start:0x([0-9a-f]+) end:0x([0-9a-f]+)")
MAX_COMBOS = 32  # C files tried per pair when constants are ambiguous


# ---------------------------------------------------------------- one project (this game or another one)

def _configure_value(root: Path, var: str, default: str) -> str:
    try:
        text = (root / "tools" / "configure.py").read_text(encoding="utf-8")
    except OSError:
        return default
    if var == "CC_FLAGS":
        m = re.search(r'^CC_FLAGS = " "\.join\((\[.*?\])\)', text, re.M | re.S)
        return " ".join(ast.literal_eval(m.group(1))) if m else default
    m = re.search(rf'^{var} = "([^"]*)"', text, re.M)
    return m.group(1) if m else default


class Image:
    """Functions, symbols, matched files and code bytes of the ARM9 main module of a project."""

    def __init__(self, root: Path):
        self.root = root
        vers = sorted(p.name for p in (root / "config").iterdir() if (p / "arm9" / "symbols.txt").exists())
        self.version = vers[0]
        cfg = root / "config" / self.version / "arm9"
        sym_text = (cfg / "symbols.txt").read_text(encoding="utf-8", errors="replace")
        self.bin = (root / "extract" / self.version / "arm9" / "arm9.bin").read_bytes()
        self.addr_of, self.name_at = {}, {}
        for name, _kind, a in SYM_RE.findall(sym_text):
            a = int(a, 16)
            self.addr_of.setdefault(name, a)
            self.name_at.setdefault(a, name)
        dl = (cfg / "delinks.txt").read_text(encoding="utf-8", errors="replace")
        head, _, files = dl.partition("\n\n")
        m = TEXT_RE.search(head)
        self.text = (int(m.group(1), 16), int(m.group(2), 16)) if m else (ARM9_BASE, ARM9_BASE)
        self.files = []  # (start, end, source path) of the complete .text ranges
        for path, body in DELINK_RE.findall(files):
            if "complete" in body:
                for a, b in TEXT_RE.findall(body):
                    self.files.append((int(a, 16), int(b, 16), path))
        self.files.sort()
        self.funcs = {}  # name -> (addr, size)
        for name, size, addr in FUNC_RE.findall(sym_text):
            addr, size = int(addr, 16), int(size, 16)
            if self.text[0] <= addr < self.text[1] and size >= 8 and addr + size - ARM9_BASE <= len(self.bin):
                self.funcs[name] = (addr, size)
        self.default_cc = _configure_value(root, "MWCC_VERSION", "2.0/sp1p5")
        self.compilers = {}
        ct = root / "config" / self.version / "compilers.txt"
        if ct.exists():
            for line in ct.read_text(encoding="utf-8").splitlines():
                if line.strip() and not line.startswith("#"):
                    path, _, prof = line.partition(" ")
                    self.compilers[path] = prof.strip()

    def code(self, name: str) -> bytes:
        a, s = self.funcs[name]
        return self.bin[a - ARM9_BASE: a - ARM9_BASE + s]

    def file_of(self, addr: int) -> str | None:
        lo, hi = 0, len(self.files)
        while lo < hi:
            mid = (lo + hi) // 2
            if self.files[mid][0] <= addr:
                lo = mid + 1
            else:
                hi = mid
        if lo and self.files[lo - 1][0] <= addr < self.files[lo - 1][1]:
            return self.files[lo - 1][2]
        return None

    def matched(self) -> dict[str, str]:
        return {n: f for n, (a, _s) in self.funcs.items() if (f := self.file_of(a))}

    def profile(self, path: str) -> str:
        """`<mwccarm version> [extra flags]` the file is built with."""
        return self.compilers.get(path) or self.default_cc

    _sources: dict = {}

    def source_of(self, name: str, path: str) -> str | None:
        """C of one function: the whole file when it only defines this function, else its declarations + this
        function (merged files of src/nitro...)."""
        key = (str(self.root), name)
        if key not in Image._sources:
            try:
                text = (self.root / path).read_text(encoding="utf-8")
            except OSError:
                Image._sources[key] = None
                return None
            if text.startswith(am.MARKER):
                text = text.split("\n", 1)[1]
            items = donorlib.top_level_items(text)
            defined = [donorlib.function_name(it) for it in items if it.rstrip().endswith("}")]
            defined = [d for d in defined if d]
            if name not in defined:
                Image._sources[key] = None
            elif len(defined) == 1:
                Image._sources[key] = text
            else:
                keep = [it for it in items if not it.rstrip().endswith("}") or donorlib.function_name(it) == name]
                Image._sources[key] = "\n\n".join(keep) + "\n"
        return Image._sources[key]


# ---------------------------------------------------------------- shapes

def words(code: bytes) -> tuple[int, ...]:
    return struct.unpack(f"<{len(code) // 4}I", code)


def is_branch(w: int) -> bool:
    return (w & 0x0E000000) == 0x0A000000


def branch_target(w: int, at: int) -> int:
    simm = w & 0xFFFFFF
    if simm & 0x800000:
        simm -= 1 << 24
    t = at + 8 + simm * 4
    return t + (2 if (w >> 28) == 0xF and w & 0x01000000 else 0)  # blx: H bit


def external(w: int, i: int, n: int) -> bool:
    if not is_branch(w):
        return False
    simm = w & 0xFFFFFF
    if simm & 0x800000:
        simm -= 1 << 24
    return (w >> 28) == 0xF or not 0 <= i + 2 + simm < n


IMM_DP = lambda w: (w & 0x0E000000) == 0x02000000  # noqa: E731  data processing, immediate operand
IMM_LS = lambda w: (w & 0x0E000000) == 0x04000000  # noqa: E731  ldr/str/ldrb/strb, immediate offset
IMM_LSH = lambda w: (w & 0x0E400090) == 0x00400090 and (w & 0x60)  # noqa: E731  ldrh/strh/ldrsb/ldrsh, immediate


def shapes(code: bytes) -> tuple[str, str]:
    """(exact, template) fingerprints. exact: pool words and branches leaving the function masked, every other bit
    kept. template: immediates masked too (constants, offsets), registers and opcodes kept."""
    ws = words(code)
    pool = donorlib.pool_words(ws)
    ex, tp = [], []
    for i, w in enumerate(ws):
        if i in pool:
            ex.append("P")
            tp.append("P")
            continue
        if external(w, i, len(ws)):
            ex.append("%02xX" % (w >> 24))
            tp.append(ex[-1])
            continue
        ex.append("%08x" % w)
        if IMM_DP(w):
            w &= 0xFFFFF000
        elif IMM_LS(w):
            w &= 0xFF7FF000
        elif IMM_LSH(w):
            w &= 0xFF7FF0F0
        tp.append("%08x" % w)
    h = lambda t: hashlib.sha1(" ".join(t).encode()).hexdigest()[:20]  # noqa: E731
    return h(ex), h(tp)


def _ror(v: int, r: int) -> int:
    return ((v >> r) | (v << (32 - r))) & 0xFFFFFFFF if r else v


def immediates(w: int) -> list[int]:
    """Values a C literal may have for this instruction's immediate (several readings, e.g. mvn = -(v+1))."""
    if IMM_DP(w):
        v = _ror(w & 0xFF, 2 * ((w >> 8) & 0xF))
        out = [v]
        if (w >> 21) & 0xF == 0xF:  # mvn
            out += [v + 1, (~v) & 0xFFFFFFFF]
        return out
    if IMM_LS(w):
        return [w & 0xFFF]
    if IMM_LSH(w):
        return [((w >> 4) & 0xF0) | (w & 0xF)]
    return []


def resolve(img: Image, value: int) -> str | None:
    """Name of the symbol at this address (Thumb pointers have bit 0 set)."""
    return img.name_at.get(value) or (img.name_at.get(value & ~1) if value & 1 else None)


def pair_maps(src: Image, sname: str, dst: Image, dname: str):
    """What changes from the source function to its twin: ({old name: new name}, {old value: {new values}}).
    None when they cannot be paired (an address of the twin has no symbol, a name maps to two names...)."""
    sw, dw = words(src.code(sname)), words(dst.code(dname))
    if len(sw) != len(dw):
        return None
    pool = donorlib.pool_words(sw)
    if pool != donorlib.pool_words(dw):
        return None
    sa, da = src.funcs[sname][0], dst.funcs[dname][0]
    names, nums = {sname: dname}, {}

    def name_pair(old, new):
        if names.setdefault(old, new) != new:
            raise ValueError
    try:
        for i, (a, b) in enumerate(zip(sw, dw)):
            if i in pool:
                on, nn = resolve(src, a), resolve(dst, b)
                if on and nn:
                    name_pair(on, nn)
                elif on or nn:
                    if src is not dst or a != b:
                        return None  # an address with no symbol on one side: cannot be named in C
                else:
                    nums.setdefault(a, set()).add(b)
                    if a >= 0x80000000:
                        nums.setdefault(0x100000000 - a, set()).add((0x100000000 - b) & 0xFFFFFFFF)
                continue
            if external(a, i, len(sw)):
                on, nn = resolve(src, branch_target(a, sa + 4 * i)), resolve(dst, branch_target(b, da + 4 * i))
                if not (on and nn):
                    return None
                name_pair(on, nn)
                continue
            for x, y in zip(immediates(a), immediates(b)):
                nums.setdefault(x, set()).add(y)
    except ValueError:
        return None
    return names, nums


# ---------------------------------------------------------------- C rewriting

IDENT = re.compile(r"[A-Za-z_]\w*")
NUMBER = re.compile(r"(?<![\w.])(0[xX][0-9a-fA-F]+|\d+)([uUlL]*)(?![\w.])")


def rename(source: str, names: dict[str, str]) -> str:
    def sub(m):
        w = m.group(0)
        if w in names:
            return names[w]
        if w.startswith("M2C_SELF_") and w[9:] in names:
            return "M2C_SELF_" + names[w[9:]]
        return w
    return IDENT.sub(sub, source)


OR_NUM = re.compile(r"\(?(0[xX][0-9a-fA-F]+|\d+)\)?\s*\|\s*(0[xX][0-9a-fA-F]+|\d+)\b")


def or_variants(source: str, nums: dict[int, set[int]]) -> list[str]:
    """Sources where `BASE | OFFSET` expressions (e.g. `(0x04000000) | 0x8`, a register address built by OR) take
    the twin's value: the twin's loaded word is the OR of the same base and another offset. One site per line."""
    lines = source.split("\n")
    variants = [source]
    for i, line in enumerate(lines):
        if line.lstrip().startswith(("#", "/*", "//")):
            continue
        for m in OR_NUM.finditer(line):
            a, b = int(m.group(1), 0), int(m.group(2), 0)
            v = a | b
            if v not in nums or nums[v] == {v}:
                continue
            for n in sorted(nums[v]):
                if n & a != a or n ^ a == b:
                    continue
                new = list(lines)
                new[i] = line[:m.start(2)] + f"0x{n ^ a:x}" + line[m.end(2):]
                variants.append("\n".join(new))
            break  # one OR site per line
    return variants[:MAX_COMBOS]


def with_constants(source: str, nums: dict[int, set[int]]) -> list[str]:
    """Sources where the C literals are replaced by the twin's values. A literal whose value maps to several values
    gives one source per choice (at most MAX_COMBOS sources in all)."""
    lines = source.split("\n")
    code_lines = [i for i, l in enumerate(lines) if not l.lstrip().startswith(("#", "/*", "//"))]
    seen = {}
    for i in code_lines:
        for m in NUMBER.finditer(lines[i]):
            v = int(m.group(1), 0)
            if v in nums and nums[v] != {v}:
                seen[v] = sorted(nums[v])
    if not seen:
        return [source]
    keys = list(seen)
    combos = list(itertools.islice(itertools.product(*(seen[k] for k in keys)), MAX_COMBOS))
    out = []
    for combo in combos:
        choice = dict(zip(keys, combo))

        def sub(m):
            v = int(m.group(1), 0)
            if v not in choice:
                return m.group(0)
            n = choice[v]
            lit = m.group(1)
            text = (f"0x{n:X}" if lit[2:].isupper() or lit[2:].isdigit() else f"0x{n:x}") if lit[:2] in ("0x", "0X") else str(n)
            return text + m.group(2)
        new = list(lines)
        for i in code_lines:
            new[i] = NUMBER.sub(sub, new[i])
        out.append("\n".join(new))
    return out


# ---------------------------------------------------------------- compile + exact check

CC_FLAGS = _configure_value(ROOT, "CC_FLAGS", "-O4,p " + am.pc.BASE_FLAGS)


def check(img: Image, name: str, source: str, profile: str) -> str:
    """"" if the source compiles (as ninja would) to exactly this function, calls and loaded addresses included,
    and to nothing else; else why not."""
    version, _, flags = profile.partition(" ")
    mwcc = am.MWCC_ROOT / version / "mwccarm.exe"
    if not mwcc.exists():
        return f"no compiler {version}"
    target = img.code(name)
    addr = img.funcs[name][0]
    with tempfile.TemporaryDirectory() as tmp:
        t = Path(tmp)
        (t / "f.c").write_text(source, encoding="utf-8")
        cmd = (f'"{mwcc}" {CC_FLAGS} -lang=c {flags} -i "{ROOT / "include"}" -d {project.VERSION} -c f.c -o f.o')
        r = am.run_limited(cmd, cwd=t, shell=True)
        if r.returncode != 0 or not (t / "f.o").exists():
            return "compile"
        obj = donorlib.Obj(t / "f.o")
        fn = next((f for f in obj.functions() if f[0] == name), None)
        if fn is None:
            return "function not in the object"
        _n, shndx, off, size, thumb = fn
        if thumb or size != len(target):
            return "size"
        extra = [s for s in obj.nonempty_sections() if not s.startswith(".text")]
        if extra:
            return f"extra section {extra[0]}"
        if any(s[4] == 0xFFF2 for s in obj.syms):
            return "common symbol"
        if sum(s[5] for i, s in enumerate(obj.secs) if s[2] & 2 and obj.sec_names[i].startswith(".text")) != size:
            return "other functions in the object"
        code = obj.section_bytes(shndx)[off: off + size]
        relocs = {o: (typ, sym, add) for o, typ, sym, add in obj.function_relocs(shndx, off, size)}
        local = {s[0] for s in obj.syms if s[0] and 0 < s[4] < 0xFF00}  # defined in the object itself
    tw, cw = words(target), words(code)
    for i, (a, b) in enumerate(zip(tw, cw)):
        if 4 * i not in relocs:
            if a != b:
                return f"word {i} differs"
            continue
        typ, sym, add = relocs[4 * i]
        if sym and sym not in img.addr_of and sym not in local:
            return f"uses {sym}, which this game does not have (the link would fail)"
        if typ == donorlib.R_ARM_ABS32:
            want = img.addr_of.get(sym)
            if sym and want is not None and a not in (want + add, (want + add) | 1):
                return f"loads {sym}+{add} instead of 0x{a:08x}"
        else:
            if (a ^ b) & 0xFE000000 and not ((a >> 28) == 0xF or (b >> 28) == 0xF):
                return f"word {i} differs"
            want = resolve(img, branch_target(a, addr + 4 * i))
            if sym and want and sym != want:
                return f"calls {sym} instead of {want}"
    return ""


# ---------------------------------------------------------------- search

def other_images() -> list[Image]:
    out = []
    for d in sorted(ROOT.parent.iterdir()):
        if d == ROOT or d.name.startswith(("_", ".")) or not (d / "config").is_dir():
            continue
        try:
            img = Image(d)
        except (OSError, StopIteration, IndexError):
            continue
        if img.files:
            out.append(img)
    return out


def families(img: Image, others: list[Image]):
    """Index of every function by shape: {exact: [(image, name)]}, {template: [(image, name)]}."""
    ex, tp = {}, {}
    for im in [img] + others:
        names = im.funcs if im is img else im.matched()  # other games only bring sources
        for n in names:
            e, t = shapes(im.code(n))
            ex.setdefault(e, []).append((im, n))
            tp.setdefault(t, []).append((im, n))
    return ex, tp


def unique_stem_ok(name: str, stems: set[str]) -> bool:
    return name.lower() not in stems


def search(img: Image, others: list[Image], only_sources: set[str] | None, jobs: int, log=print,
           targets: set[str] | None = None):
    """Rounds of cloning: returns [(name, size, addr, source, kind, from)] that compile to an exact match.
    `targets`: only these unmatched functions (a block)."""
    ex, tp = families(img, others)
    matched = img.matched()
    stems = {p.stem.lower() for p in (ROOT / "src").rglob("*.c")}
    found, done = [], set(matched)
    sources = {(img, n): matched[n] for n in matched if only_sources is None or n in only_sources}
    for im in others:
        for n, f in im.matched().items():
            sources[(im, n)] = f
    shape_of = {n: shapes(img.code(n)) for n in img.funcs if n not in done and (targets is None or n in targets)}
    tried = set()
    for rnd in range(1, 6):
        todo = []
        for n, (e, t) in shape_of.items():
            if n in done or not unique_stem_ok(n, stems):
                continue
            cands = [(im, s, "dup" if im is img else "game") for im, s in ex.get(e, []) if (im, s) in sources]
            cands += [(im, s, "template") for im, s in tp.get(t, [])
                      if im is img and (im, s) in sources and (im, s, "dup") not in [(c[0], c[1], c[2]) for c in cands]]
            cands = [c for c in cands if (n, c[0].root.name, c[1]) not in tried][:3]
            if cands:
                todo.append((n, cands))
        if not todo:
            break
        log(f"round {rnd}: {len(todo)} functions with a matched twin")

        def attempt(item):
            n, cands = item
            for im, s, kind in cands:
                tried.add((n, im.root.name, s))
                path = sources[(im, s)]
                base = im.source_of(s, path)
                if base is None:
                    continue
                pm = pair_maps(im, s, img, n)
                if pm is None:
                    continue
                names, nums = pm
                profile = im.profile(path)
                for cand in (c for v in or_variants(rename(base, names), nums) for c in with_constants(v, nums)):
                    if not check(img, n, cand, profile):
                        return n, cand, kind, f"{im.root.name}:{s}" if im is not img else s, profile
            return None

        new = []
        with ThreadPoolExecutor(max_workers=max(1, jobs)) as ex_:
            for r in ex_.map(attempt, todo):
                if r:
                    new.append(r)
        for n, cand, kind, frm, profile in new:
            a, s = img.funcs[n]
            if profile != img.default_cc:
                cand = f"{am.MARKER}{profile} */\n" + cand
            found.append((n, s, a, cand, kind, frm))
            done.add(n)
            stems.add(n.lower())
            path = f"src/auto/{n}.c"
            sources[(img, n)] = path
            Image._sources[(str(img.root), n)] = cand.split("\n", 1)[1] if cand.startswith(am.MARKER) else cand
            img.compilers[path] = profile
        log(f"round {rnd}: {len(new)} matches" + (f" ({', '.join(sorted({k for *_x, k, _f, _p in new}))})" if new else ""))
        if not new:
            break
    return found


def write_families(img: Image, others: list[Image]) -> dict:
    """build/clone/families.json: for each unmatched function, how many unmatched functions share its shape (the
    matches one AI answer can give) and whether a matched twin exists already. Read by the Studio to order blocks."""
    ex, tp = families(img, [])
    matched = img.matched()
    other_ex = {}
    for im in others:
        for n, path in im.matched().items():
            other_ex.setdefault(shapes(im.code(n))[0], [im.root.name, n, path])
    out = {}
    for groups, kind in ((ex, "dup"), (tp, "template")):
        for members in groups.values():
            names = [n for _im, n in members]
            left = [n for n in names if n not in matched]
            if len(names) < 2 or not left:
                continue
            src = next((n for n in names if n in matched), None)
            for n in left:
                row = out.setdefault(n, {"dup": 0, "template": 0, "twin": None, "first": left[0]})
                row[kind] = max(row[kind], len(left) - 1)
                if src and not row["twin"]:
                    row["twin"] = src
                if kind == "dup":
                    row["first"] = left[0]
    for n in img.funcs:
        if n not in matched:
            g = other_ex.get(shapes(img.code(n))[0])
            if g:
                out.setdefault(n, {"dup": 0, "template": 0, "twin": None, "first": n})["game"] = g
    WORK.mkdir(parents=True, exist_ok=True)
    FAMILIES.write_text(json.dumps(out, indent=0), encoding="utf-8")
    return out


# ---------------------------------------------------------------- integration

def run(cmd):
    return subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, encoding="utf-8", errors="replace")


def drop(paths: list[Path]) -> None:
    """Removes integrated files again: their delinks.txt / compilers.txt entries and the sources."""
    rels = {p.relative_to(ROOT).as_posix() for p in paths}
    text = am.DELINKS.read_text(encoding="utf-8")
    for rel in rels:
        text = re.sub(r"\n" + re.escape(rel) + r":\n    complete\n    \.text[^\n]*\n", "\n", text)
    am.DELINKS.write_text(text, encoding="utf-8", newline="\n")
    if am.COMPILERS_TXT.exists():
        keep = [l for l in am.COMPILERS_TXT.read_text(encoding="utf-8").splitlines(True) if l.split(" ")[0] not in rels]
        am.COMPILERS_TXT.write_text("".join(keep), encoding="utf-8", newline="\n")
    for p in paths:
        p.unlink(missing_ok=True)


def integrate_verified(found: list[tuple[str, int, int, str]], log=print) -> list[str]:
    """Adds the matches to src/auto/ + delinks.txt and keeps the ones the ROM accepts. Returns the names kept."""
    backup = am.DELINKS.read_bytes()
    compilers_backup = am.COMPILERS_TXT.read_bytes() if am.COMPILERS_TXT.exists() else b""
    journal_begin([am.DELINKS, am.COMPILERS_TXT])
    created = am.integrate(found)
    journal_created(created)
    pc_exe = __import__("shutil").which("pre-commit")
    if pc_exe:  # in chunks: a command line of a thousand paths is too long for Windows (WinError 206)
        rels = [str(p.relative_to(ROOT)) for p in created]
        for k in range(0, len(rels), 100):
            run([pc_exe, "run", "clang-format", "--files", *rels[k:k + 100]])
    run([sys.executable, "tools/configure.py", project.VERSION])
    verify = run([sys.executable, "tools/match.py", "verify"])
    for _ in range(5):
        # A link error names the object that needs a missing symbol: drop those files and build again
        # Files the report does not see at 100 % although the ROM is identical (a relocation objdiff reads
        # differently): auto_match drops them the same way
        out = verify.stdout + verify.stderr
        bad = set(re.findall(r'Referenced from "\w+" in (\w+)\.o', out))
        bad |= {Path(p).stem for p in re.findall(r"FAIL: (src/auto/\S+?\.c) is marked complete", out)}
        bad_paths = [c for c in created if c.stem in bad]
        if verify.returncode == 0 or not bad_paths:
            break
        log(f"dropping {len(bad_paths)} file(s) the build or the report rejects: {', '.join(p.stem for p in bad_paths)}")
        drop(bad_paths)
        created = [c for c in created if c not in bad_paths]
        run([sys.executable, "tools/configure.py", project.VERSION])
        verify = run([sys.executable, "tools/match.py", "verify"])
    if verify.returncode != 0:
        import find_culprits
        log("verify failed: looking for the files that break the ROM...")
        new = {c.relative_to(ROOT).as_posix() for c in created}
        ok, dropped = find_culprits.repair(allowed=new, log=log)
        if dropped:
            log(f"dropped {len(dropped)} file(s) that break the ROM")
            created = [c for c in created if c.relative_to(ROOT).as_posix() not in dropped]
        if ok:
            verify = run([sys.executable, "tools/match.py", "verify"])
    if verify.returncode != 0 or "VERIFY PASSED" not in verify.stdout:
        log(verify.stdout[-2000:])
        log("verify failed: rolling back")
        am.DELINKS.write_bytes(backup)
        am.COMPILERS_TXT.write_bytes(compilers_backup)
        for p in created:
            p.unlink(missing_ok=True)
        run([sys.executable, "tools/configure.py", project.VERSION])
        journal_end()
        return []
    journal_end()
    log("VERIFY PASSED")
    return [p.stem for p in created]


def commit(names: list[str], push: bool) -> None:
    """Commits exactly what this run added (sources, delinks.txt, compilers.txt), never anything else."""
    files = [f"src/auto/{n}.c" for n in names if (ROOT / "src" / "auto" / f"{n}.c").exists()]
    cfg = [p.relative_to(ROOT).as_posix() for p in (am.DELINKS, am.COMPILERS_TXT) if p.exists()]
    if run(["git", "diff", "--cached", "--quiet"]).returncode:
        print("commit skipped: other changes are already staged in this repository")
        return
    paths = files + cfg
    for k in range(0, len(paths), 100):  # in chunks: Windows limits the length of a command line
        run(["git", "add", "--", *paths[k:k + 100]])
    msg = (f"clone_match: {len(names)} matching functions\n\nFunctions with the same code as functions already "
           "matched in this game or in another of our DS projects (tools/clone_match.py). VERIFY PASSED.\n")
    r = run(["git", "commit", "-q", "-m", msg])  # the index holds only these files (checked above)
    if r.returncode:
        print(f"commit failed: {(r.stdout + r.stderr).strip()[-300:]}")
        return
    print("committed")
    if push and run(["git", "remote"]).stdout.strip():
        r = run(["git", "push", "-q", "origin", "HEAD"])
        print("pushed" if r.returncode == 0 else f"push failed: {(r.stdout + r.stderr).strip()[-300:]}")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--list", action="store_true", help="only write build/clone/families.json")
    ap.add_argument("--sources", help="only clone from these matched functions (comma separated)")
    ap.add_argument("--names", help="only try to match these functions (comma separated, e.g. a block)")
    ap.add_argument("--other-games", action="store_true", help="also use the matches of the other projects")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--max", type=int, default=0, help="integrate at most N matches")
    ap.add_argument("-j", type=int, default=os.cpu_count() or 4)
    ap.add_argument("--report", type=Path, help="write the names integrated to this file (one per line)")
    ap.add_argument("--commit", action="store_true", help="after VERIFY PASSED: commit the new files (and only them)")
    ap.add_argument("--push", action="store_true", help="with --commit: push when the game has a remote")
    ap.add_argument("--emit", type=Path, help="change nothing: write the matches found to this JSON file "
                                              "([name, size, addr, source]...) for a caller that integrates them")
    args = ap.parse_args()

    img = Image(ROOT)
    others = other_images() if args.other_games or args.list else []
    if args.list:
        fam = write_families(img, others)
        dup = sum(1 for r in fam.values() if r["dup"] or r["template"])
        twin = sum(1 for r in fam.values() if r["twin"])
        game = sum(1 for r in fam.values() if r.get("game"))
        print(f"{len(fam)} unmatched functions in families ({dup} with an unmatched sibling, {twin} with a matched "
              f"twin here, {game} matched in another game) -> {FAMILIES.relative_to(ROOT)}")
        return
    only = set(args.sources.split(",")) if args.sources else None
    found = search(img, others, only, args.j, targets=set(args.names.split(",")) if args.names else None)
    if args.max:
        found = found[:args.max]
    for n, s, a, _src, kind, frm in found:
        print(f"  {n} <- {frm} ({kind}, {s} bytes)")
    if args.emit:
        args.emit.write_text(json.dumps([[n, s, a, src] for n, s, a, src, _k, _f in found]), encoding="utf-8")
        print(f"{len(found)} matches written to {args.emit}")
        return
    if not found:
        print("Nothing to clone.")
        if not args.names and not args.sources:
            write_families(img, others or other_images())
        return
    if args.dry_run:
        print(f"{len(found)} matches (dry run, nothing added).")
        return
    kept = integrate_verified([(n, s, a, src) for n, s, a, src, _k, _f in found])
    if args.report:
        args.report.write_text("".join(k + "\n" for k in kept), encoding="utf-8")
    print(f"OK: {len(kept)} functions matched by cloning.")
    if kept and args.commit:
        commit(kept, args.push)
    write_families(Image(ROOT), others or other_images())  # the Studio's levels and queue order read it


if __name__ == "__main__":
    from pipeline_lock import pipeline_lock
    if "--list" in sys.argv:
        main()
    else:
        with pipeline_lock("clone_match"):
            main()
