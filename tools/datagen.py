"""Give the initialized data (.data / .rodata) of each module to C files: src/data/<module>_<sec>_<addr>.c.

Each symbol becomes a definition of its exact bytes: a char array when it is a string, a u32 table when it is
word-sized (pointers written as `(u32)&symbol`, so the relocations match too), else a u8 array. Contiguous symbols of
one section go to the same file. Not covered (left to the gap): symbols with a pointer that a u32 table cannot hold,
pointers to an ambiguous module, thumb pointers, alias labels, -profile name records (they belong to their function).

    python tools/datagen.py [--mods main,ov004,...] [--sections .data,.rodata] [--max-run N] [--dry-run]
"""
import argparse
import json
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402
from bssgen import SECTION, modules  # noqa: E402

ROOT = project.ROOT
SYM = re.compile(r"^(\S+) kind:(\w+)(\S*) addr:0x([0-9a-f]+)", re.M)


def module_key(name: str) -> str:
    return f"overlay({int(name[2:])})" if name.startswith("ov") else name


def load_symbols(folder: Path) -> list[tuple[int, str, str]]:
    return sorted((int(a, 16), n, k) for n, k, _x, a in SYM.findall((folder / "symbols.txt").read_text(encoding="utf-8")))


def image(name: str, folder: Path) -> tuple[bytes, int]:
    """(bytes, base address) of a module as the game has it."""
    head = (folder / "delinks.txt").read_text(encoding="utf-8").split("\n\n", 1)[0]
    base = int(re.search(r"start:0x([0-9a-f]+)", head).group(1), 16)
    if name == "main":
        return (project.EXTRACT / "arm9" / "arm9.bin").read_bytes(), 0x02000000
    if name in ("itcm", "dtcm"):
        return (project.EXTRACT / "arm9" / f"{name}.bin").read_bytes(), base
    return (project.EXTRACT / "arm9_overlays" / f"{name}.bin").read_bytes(), base


class Mod:
    def __init__(self, name: str, folder: Path, targets: dict[str, list[tuple[int, str, str]]]):
        self.name, self.folder = name, folder
        text = (folder / "delinks.txt").read_text(encoding="utf-8")
        head, _sep, body = text.partition("\n\n")
        self.sections = {sec: (int(s, 16), int(e, 16)) for sec, s, e in SECTION.findall(head)}
        self.taken = [(int(s, 16), int(e, 16)) for _sec, s, e in SECTION.findall(body)]
        self.symbols = targets[module_key(name)]
        self.bin, self.base = image(name, folder)
        self.relocs: dict[int, tuple[int, str]] = {}
        for frm, kind, to, mod in re.findall(r"^from:0x([0-9a-f]+) kind:(\w+) to:0x([0-9a-f]+) module:(\S+)",
                                             (folder / "relocs.txt").read_text(encoding="utf-8"), re.M):
            if kind == "load":
                self.relocs[int(frm, 16)] = (int(to, 16), mod)


def target_name(targets, to: int, mod: str) -> tuple[str, int] | None:
    syms = targets.get(mod)
    if not syms:
        return None
    best = None
    for a, n, k in syms:
        if a > to:
            break
        if k != "label":
            best = (a, n)
    return (best[1], to - best[0]) if best else None


def c_string(raw: bytes) -> str | None:
    if b"\0" not in raw:
        return None
    i = raw.index(b"\0")
    s = raw[:i]
    if not s or any(raw[i:]) or any(c < 0x20 and c not in (9, 10, 13) for c in s):
        return None
    if sum(0x20 <= c < 0x7F for c in s) < len(s) // 2:
        return None
    out = []
    for c in s:
        ch = chr(c)
        if ch in '"\\':
            out.append("\\" + ch)
        elif c == 10:
            out.append("\\n")
        elif c == 9:
            out.append("\\t")
        elif c == 13:
            out.append("\\r")
        elif 0x20 <= c < 0x7F and ch != "?":  # '?' could start a trigraph
            out.append(ch)
        else:
            out.append(f"\\{c:03o}")
    return "".join(out)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--mods", default="")
    ap.add_argument("--sections", default=".data,.rodata")
    ap.add_argument("--skip", nargs="*", default=[])
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()
    wb = None
    mods_all = modules()
    targets = {module_key(n): load_symbols(f) for n, f in mods_all.items()}
    prof = json.loads((ROOT / "build" / "profnames.json").read_text(encoding="utf-8")) \
        if (ROOT / "build" / "profnames.json").exists() else {}
    prof_ranges = [tuple(v["rec"]) for v in prof.values()]
    want = set(a.mods.split(",")) if a.mods else None
    stats = {"files": 0, "bytes": 0, "skipped": 0}
    for name, folder in mods_all.items():
        if want and name not in want:
            continue
        m = Mod(name, folder, targets)
        entries = []
        for secname in a.sections.split(","):
            if secname not in m.sections or m.sections[secname][0] == m.sections[secname][1]:
                continue
            start, end = m.sections[secname]
            syms = [(ad, n) for ad, n, k in m.symbols if start <= ad < end and k == "data"]
            addrs = [ad for ad, _n in syms]
            items = []  # (addr, name, size, c_decl or None, externs)
            for i, (ad, n) in enumerate(syms):
                nxt = syms[i + 1][0] if i + 1 < len(syms) else end
                size = nxt - ad
                bad = size == 0 or addrs.count(ad) > 1 or any(s <= ad < e for s, e in m.taken) \
                    or any(ad < pe and ps < nxt for ps, pe in prof_ranges)
                decl, ext = (None, set()) if bad else declare(wb, m, targets, ad, n, size, secname)
                if decl is None and not bad:
                    stats["skipped"] += 1
                items.append((ad, n, size, decl, ext))
            runs, cur = [], []
            for it in items:
                ad, _n, size, decl, _e = it
                fits = decl is not None and (ad % 4 == 0 or size < 4)
                same_type = cur and decl is not None and cur[-1][3].split("[")[0].split()[-2] == decl.split("[")[0].split()[-2]
                if cur and fits and same_type and cur[-1][0] + cur[-1][2] == ad and size > cur[-1][2]:  # linker sorts by size
                    cur.append(it)
                    continue
                if cur:
                    runs.append(cur)
                cur = [it] if fits and ad % 4 == 0 else []
            if cur:
                runs.append(cur)
            split = []
            for r in runs:  # a pointer to a later symbol of the file needs a forward declaration, which moves that
                while r:    # symbol to the end of the section: start a new file at such a target instead
                    names = [it[1] for it in r]
                    cut = min((names.index(t) for i, it in enumerate(r) for t in it[4]
                               if t in names[i + 1:]), default=None)
                    if cut is None:
                        split.append(r)
                        break
                    split.append(r[:cut])
                    r = r[cut:]
                    if r and r[0][0] % 4:
                        break
            runs = split
            for r in runs:
                while r and (r[-1][0] + r[-1][2]) % 4:
                    r.pop()
                if not r:
                    continue
                tag = secname.strip(".")
                rel = f"src/data/{name}_{tag}_{r[0][0]:08x}.c"
                if rel in a.skip:
                    continue
                s, e = r[0][0], r[-1][0] + r[-1][2]
                stats["files"] += 1
                stats["bytes"] += e - s
                entries.append(f"\n{rel}:\n    complete\n    {secname:<11} start:0x{s:08x} end:0x{e:08x}\n")
                if not a.dry_run:
                    defined = {it[1] for it in r}
                    ext = sorted(set().union(*(it[4] for it in r)) - defined)
                    src = ["/* compiler: 2.0/sp1p5 */", '#include "m2c.h"', ""]
                    src += [f"extern u8 {x}[];" for x in ext]
                    src += [""] if len(src) > 3 else []
                    src += [it[3] for it in r]
                    p = ROOT / rel
                    p.parent.mkdir(parents=True, exist_ok=True)
                    p.write_text("\n".join(src) + "\n", encoding="utf-8", newline="\n")
        if entries and not a.dry_run:
            d = folder / "delinks.txt"
            d.write_text(d.read_text(encoding="utf-8").rstrip("\n") + "\n" + "".join(entries), encoding="utf-8",
                         newline="\n")
    print(stats)


def declare(wb, m: Mod, targets, ad: int, n: str, size: int, secname: str):
    raw = m.bin[ad - m.base: ad - m.base + size]
    const = "const " if secname == ".rodata" else ""
    ptrs = {f: m.relocs[f] for f in range(ad, ad + size) if f in m.relocs}
    if not ptrs and not any(raw):
        return None, set()  # mwcc puts all-zero data in .bss
    if not ptrs:
        s = c_string(raw)
        if s is not None:
            return f'{const}char {n}[{size}] = "{s}";', set()
    if size % 4 == 0 and ad % 4 == 0:
        words, ext = [], set()
        for o in range(0, size, 4):
            w, = struct.unpack_from("<I", raw, o)
            if ad + o in ptrs:
                to, mod = ptrs[ad + o]
                t = target_name(targets, to, mod)
                if t is None or w & 1:  # thumb pointer: the linker adds the bit itself
                    return None, set()
                tn, off = t
                off += w - to
                ext.add(tn)
                words.append(f"(u32)&{tn}" if off == 0 else f"(u32)((u8 *)&{tn} + 0x{off:x})")
            else:
                words.append(f"0x{w:08X}")
        if any(f % 4 for f in ptrs):
            return None, set()
        body = ",\n".join("    " + ", ".join(words[i:i + 4]) for i in range(0, len(words), 4))
        return f"{const}u32 {n}[{size // 4}] = {{\n{body}\n}};", ext
    if ptrs:
        return None, set()
    return f"{const}u8 {n}[{size}] = {{" + ", ".join(f"0x{b:02X}" for b in raw) + "};", set()


if __name__ == "__main__":
    main()
