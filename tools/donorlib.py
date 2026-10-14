"""Shared by `decomp ds/tools/donors.py` (indexes other public DS decomps) and `tools/donor_match.py` (uses them in
a game): ELF object reading, the code fingerprint, and the rewrite of a donor source file into a candidate.

The fingerprint must be computed the same way on a compiled object and on the game's ROM:
  - literal pool words (loaded by `ldr rX, [pc, #imm]`) are masked;
  - branches leaving the function (calls, tail calls) are masked, branches inside it are kept;
  - every other word is compared bit for bit (registers, immediates, conditions).
So two functions with the same fingerprint differ at most in what they call and which addresses they load.
"""
import hashlib
import re
import struct
from pathlib import Path

R_ARM_PC24, R_ARM_ABS32, R_ARM_CALL, R_ARM_JUMP24 = 1, 2, 28, 29


# ---------------------------------------------------------------- ELF objects

class Obj:
    """Minimal reader for mwccarm ELF objects: sections, symbols, REL relocations."""

    def __init__(self, path: Path):
        self.d = d = Path(path).read_bytes()
        shoff, = struct.unpack_from("<I", d, 0x20)
        shentsize, shnum, shstrndx = struct.unpack_from("<HHH", d, 0x2E)
        self.secs = [struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]
        names = self.secs[shstrndx]
        self.sec_names = [self._str(names[4], s[0]) for s in self.secs]
        self.syms = []
        for s in self.secs:
            if s[1] == 2:  # SHT_SYMTAB
                strtab = self.secs[s[6]][4]
                for i in range(s[5] // 16):
                    nm, val, size, info, _o, shndx = struct.unpack_from("<IIIBBH", d, s[4] + i * 16)
                    self.syms.append((self._str(strtab, nm), val, size, info, shndx))
        self.relocs = {}  # section index -> [(offset, type, symbol index, addend)]
        for s in self.secs:
            if s[1] == 4:  # SHT_RELA (what mwccarm emits)
                lst = self.relocs.setdefault(s[7], [])
                for i in range(s[5] // 12):
                    off, info, addend = struct.unpack_from("<IIi", d, s[4] + i * 12)
                    lst.append((off, info & 0xFF, info >> 8, addend))
            elif s[1] == 9:  # SHT_REL: addend in place
                lst = self.relocs.setdefault(s[7], [])
                for i in range(s[5] // 8):
                    off, info = struct.unpack_from("<II", d, s[4] + i * 8)
                    lst.append((off, info & 0xFF, info >> 8, None))

    def _str(self, base: int, off: int) -> str:
        return self.d[base + off: self.d.index(b"\0", base + off)].decode("latin-1")

    def section_bytes(self, idx: int) -> bytes:
        s = self.secs[idx]
        return b"" if s[1] == 8 else self.d[s[4]: s[4] + s[5]]  # SHT_NOBITS

    def functions(self):
        """Yields (name, section index, offset, size, is_thumb) for every sized function symbol."""
        thumb_ranges = {}
        for name, val, size, info, shndx in self.syms:
            if name.startswith("$t"):
                thumb_ranges.setdefault(shndx, []).append(val)
        for name, val, size, info, shndx in self.syms:
            if info & 0xF == 2 and size and 0 < shndx < len(self.secs):  # STT_FUNC
                thumb = bool(val & 1) or val in thumb_ranges.get(shndx, [])
                yield name, shndx, val & ~1, size, thumb

    def function_relocs(self, shndx: int, off: int, size: int) -> list[tuple[int, int, str, int]]:
        """[(offset in function, reloc type, symbol name, addend)] of one function. REL addends are read in place."""
        out = []
        code = self.section_bytes(shndx)
        for r_off, r_type, r_sym, addend in self.relocs.get(shndx, []):
            if off <= r_off < off + size:
                name, _v, _s, info, sym_shndx = self.syms[r_sym]
                if addend is None:
                    addend = struct.unpack_from("<i", code, r_off)[0] if r_type == R_ARM_ABS32 else 0
                if info & 0xF == 3:  # STT_SECTION: static data, named by the symbol at that offset
                    name, addend = self.symbol_at(sym_shndx, addend)
                out.append((r_off - off, r_type, name, addend))
        return sorted(out)

    def symbol_at(self, shndx: int, offset: int) -> tuple[str, int]:
        """(named symbol holding `offset` of a section, offset inside it), or ("", offset) for anonymous data
        such as string literals."""
        best = ("", offset)
        for name, val, size, info, sh in self.syms:
            if sh == shndx and name and not name.startswith(("$", "@", ".")) and info & 0xF in (0, 1, 2) \
                    and val <= offset < val + max(size, 1):
                best = (name, offset - val)
        return best

    def nonempty_sections(self) -> list[str]:
        """Names of allocated sections holding something (code or data)."""
        return [self.sec_names[i] for i, s in enumerate(self.secs) if s[2] & 2 and s[5] > 0]


# ---------------------------------------------------------------- fingerprint

def pool_words(words: tuple[int, ...]) -> set[int]:
    pool = set()
    for i, w in enumerate(words):
        if (w & 0x0F7F0000) == 0x051F0000:  # ldr rX, [pc, #imm]
            off = (w & 0xFFF) // 4
            pool.add(i + 2 + (off if w & 0x00800000 else -off))
    return pool


def fingerprint(code: bytes, external: set[int] | None = None) -> str | None:
    """Hash of an ARM function. `external`: word indexes known to be relocated (objects); for ROM code, branches
    whose target is outside the function are treated as external. None for code that is not a whole ARM function."""
    n = len(code) // 4
    if n < 3 or len(code) % 4:
        return None
    words = struct.unpack(f"<{n}I", code)
    pool = pool_words(words)
    toks = []
    for i, w in enumerate(words):
        if i in pool:
            toks.append("P")
            continue
        if (w & 0x0E000000) == 0x0A000000:  # b / bl / blx
            simm = w & 0xFFFFFF
            if simm & 0x800000:
                simm -= 1 << 24
            target = i + 2 + simm
            if (external and i in external) or (w >> 28) == 0xF or not 0 <= target < n:
                toks.append("%02xX" % (w >> 24))
                continue
        toks.append("%08x" % w)
    return hashlib.sha1(" ".join(toks).encode()).hexdigest()[:24]


def object_fingerprint(obj: Obj, shndx: int, off: int, size: int) -> tuple[str | None, list]:
    code = obj.section_bytes(shndx)[off: off + size]
    rel = obj.function_relocs(shndx, off, size)
    return fingerprint(code, {o // 4 for o, _t, _n, _s in rel}), rel


# ---------------------------------------------------------------- C source rewriting

_SKIP_RE = re.compile(r'"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'')


def top_level_items(text: str) -> list[str]:
    """Splits a preprocessed C file into top-level items: declarations ending with ';', function definitions
    ending with their '}', and preprocessor lines (#pragma, #line)."""
    items, start, depth, i, n = [], 0, 0, 0, len(text)
    func_body = False
    while i < n:
        c = text[i]
        if c in "\"'":
            m = _SKIP_RE.match(text, i)
            i = m.end() if m else i + 1
            continue
        if c == "/" and text.startswith("//", i):
            j = text.find("\n", i)
            i = n if j < 0 else j
            continue
        if c == "/" and text.startswith("/*", i):
            j = text.find("*/", i + 2)
            i = n if j < 0 else j + 2
            continue
        if c == "#" and depth == 0 and text[start:i].strip() == "":
            j = text.find("\n", i)
            j = n if j < 0 else j
            items.append(text[i:j])
            i = start = j + 1
            continue
        if c in "([":
            depth += 1
        elif c in ")]":
            depth -= 1
        elif c == "{":
            if depth == 0:
                before = text[start:i].rstrip()
                func_body = before.endswith(")") and "=" not in _strip_parens(before)
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0 and func_body:
                j = i + 1
                items.append(text[start:j])
                start = j
                func_body = False
        elif c == ";" and depth == 0:
            items.append(text[start:i + 1])
            start = i + 1
        i += 1
    if text[start:].strip():
        items.append(text[start:])
    return [it.strip() for it in items if it.strip()]


def _strip_parens(s: str) -> str:
    out, depth = [], 0
    for c in s:
        if c == "(":
            depth += 1
        elif c == ")":
            depth -= 1
        elif depth == 0:
            out.append(c)
    return "".join(out)


def function_name(item: str) -> str | None:
    """Name of the function defined by a top-level item, or None if it is not a function definition."""
    if not item.endswith("}"):
        return None
    brace = item.index("{")
    head = item[:brace].rstrip()
    if not head.endswith(")"):
        return None
    depth = 0
    for k in range(len(head) - 1, -1, -1):
        if head[k] == ")":
            depth += 1
        elif head[k] == "(":
            depth -= 1
            if depth == 0:
                m = re.search(r"(\w+)\s*$", head[:k])
                return m.group(1) if m else None
    return None


KEYWORDS = set("""auto break case char const continue default do double else enum extern float for goto if inline int
long register return short signed sizeof static struct switch typedef union unsigned void volatile while asm
__asm _Bool __attribute__ __declspec""".split())
_IDENT = re.compile(r"\b[A-Za-z_]\w*\b")


def _idents(s: str) -> set[str]:
    return {x for x in _IDENT.findall(_SKIP_RE.sub(" ", s)) if x not in KEYWORDS}


def _flat(s: str, opening: str, closing: str) -> str:
    """Removes everything between brackets (keeps the brackets)."""
    out, depth = [], 0
    for c in s:
        if c == opening:
            if depth == 0:
                out.append(c)
            depth += 1
        elif c == closing:
            depth -= 1
            if depth == 0:
                out.append(c)
        elif depth == 0:
            out.append(c)
    return "".join(out)


def declared_names(item: str) -> set[str]:
    """Names a top-level declaration introduces: function, variable, typedef, struct/union/enum tags, enum constants."""
    out = set()
    name = function_name(item)
    if name:
        return {name}
    out |= set(re.findall(r"\b(?:struct|union|enum)\s+(\w+)\s*\{", item))
    for body in re.findall(r"\benum\b[^{;]*\{([^{}]*)\}", item):
        out |= set(re.findall(r"(?:^|,)\s*(\w+)", body))
    s = _flat(item, "{", "}")
    s = re.sub(r"\b(?:struct|union|enum)\s+\w+", " ", s)
    flat = _flat(s, "(", ")")
    # function declaration `T name(...);` (its parameters may be function pointers)
    m = re.search(r"(\w+)\s*\(\)\s*;?\s*$", flat)
    if m and m.group(1) not in KEYWORDS and not re.match(r"\s*typedef\b", s):
        return out | {m.group(1)}
    # function pointer declarators: `(*Name)(...)`
    pointers = set(re.findall(r"\(\s*\*+\s*(?:const\s+)?(\w+)\s*\)", s))
    if pointers:
        return out | pointers
    s = flat
    # plain declarators: the identifier before `[`, `(`, `,`, `;`
    for m in re.finditer(r"(\w+)\s*(?=[\[,;(])", s):
        if m.group(1) not in KEYWORDS:
            out.add(m.group(1))
    return out


def prune(items: list[str], target_index: int) -> list[str]:
    """Keeps the items the target function needs (transitively), in their original order."""
    info = [(declared_names(it), _idents(it)) for it in items]
    needed = set(info[target_index][1])
    keep = {target_index}
    changed = True
    while changed:
        changed = False
        for i, (defs, refs) in enumerate(info):
            if i not in keep and defs & needed:
                keep.add(i)
                needed |= refs
                changed = True
    return [it for i, it in enumerate(items) if i in keep]


def candidate_source(pre: str, target: str, rename: dict[str, str], minimal: bool = True) -> str | None:
    """Turns a preprocessed donor file into a file that defines only `target` (renamed with `rename`): other
    function definitions become prototypes (inline ones are kept), data definitions become extern declarations.
    `minimal`: keep only the declarations the function needs (otherwise the whole file's declarations)."""
    out, found, pragmas = [], None, []
    for item in top_level_items(pre):
        if item.startswith("#"):
            if item.startswith("#pragma"):
                pragmas.append(item)
            continue
        name = function_name(item)
        if name is not None:
            head = item[:item.index("{")].rstrip()
            if name == target:
                if re.search(r"\binline\b", head):
                    return None
                out.append("\n".join(pragmas + [_drop_static(item)]))  # e.g. `#pragma thumb off` just before it
                found = len(out) - 1
            elif re.search(r"\binline\b", head):
                out.append(item)
            else:
                out.append(_drop_static(_drop_asm(head)) + ";")
        else:
            out.append(_declaration(item))
        pragmas = []
    if found is None:
        return None
    if minimal:
        out = prune(out, found)
    # clang-format (run by the game repos' CI) joins assembly lines: keep it away from asm code
    out = [f"// clang-format off\n{x}\n// clang-format on" if re.search(r"\basm\b", x) else x for x in out]
    text = "\n".join(x for x in out if x)
    if rename:
        pat = re.compile(r"\b(" + "|".join(re.escape(k) for k in sorted(rename, key=len, reverse=True)) + r")\b")
        text = _sub_code(text, pat, lambda m: rename[m.group(1)])
    return text + "\n"


def _sub_code(text: str, pat: re.Pattern, repl) -> str:
    """re.sub outside string and character literals."""
    out, last = [], 0
    for m in _SKIP_RE.finditer(text):
        out.append(pat.sub(repl, text[last:m.start()]))
        out.append(m.group(0))
        last = m.end()
    out.append(pat.sub(repl, text[last:]))
    return "".join(out)


def _drop_static(s: str) -> str:
    # only in the declaration specifiers, before the declarator's parameter list
    k = s.find("(")
    k = len(s) if k < 0 else k
    return re.sub(r"\bstatic\s+", "", s[:k]) + s[k:]


def _drop_asm(head: str) -> str:
    return re.sub(r"^\s*asm\s+", "", head)


def _declaration(item: str) -> str:
    """Keeps a declaration but makes sure it allocates nothing."""
    s = item.strip()
    if re.match(r"typedef\b", s):
        return s
    if re.fullmatch(r"(?:struct|union|enum)\s*\w*\s*\{.*\}\s*;", s, re.S) or re.fullmatch(
            r"(?:struct|union|enum)\s+\w+\s*;", s):
        return s
    # cut initializers at depth 0 (`int a[] = {..};`, `int x = 1, y = 2;`)
    out, depth, skipping = [], 0, False
    for c in s:
        if c in "({[":
            depth += 1
        elif c in ")}]":
            depth -= 1
        if depth == 0 and c == "=" and not skipping:
            skipping = True
            continue
        if skipping:
            if depth == 0 and c in ",;":
                skipping = False
                out.append(c)
            continue
        out.append(c)
    s = "".join(out)
    s = _drop_static(s)
    if not re.match(r"\s*extern\b", s):
        s = "extern " + s
    return s
