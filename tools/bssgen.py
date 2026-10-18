"""Give the uninitialized data (.bss) of each module to small C files: src/data/<module>_bss_<addr>.c.

mwldarm lays out the .bss objects of one object file sorted by size (smallest first), so a run of symbols whose sizes
grow strictly is what one original file can have produced. Each such run becomes one C file defining those symbols
(as u32/u8 arrays of the size up to the next symbol), plus a `.bss` range in the module's delinks.txt.
Equal sizes are never put in the same file: the linker orders ties in a way the names do not decide.

    python tools/bssgen.py [--mods main,ov004,...] [--skip FILE...] [--dry-run]

Rebuild + check the ROM afterwards (dsd checks that every symbol lands at its address).
"""
import argparse
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402

ROOT = project.ROOT
SECTION = re.compile(r"^\s+(\.\w+)\s+start:0x([0-9a-f]+)\s+end:0x([0-9a-f]+)", re.M)


def modules() -> dict[str, Path]:
    mods = {"main": project.ARM9}
    for d in ("itcm", "dtcm"):
        if (project.ARM9 / d / "delinks.txt").exists():
            mods[d] = project.ARM9 / d
    for d in sorted((project.ARM9 / "overlays").glob("ov*")):
        mods[d.name] = d
    return mods


def plan(name: str, folder: Path) -> list[list[tuple[int, str, int]]]:
    text = (folder / "delinks.txt").read_text(encoding="utf-8")
    header = text.split("\n\n", 1)[0]
    bss = [(int(s, 16), int(e, 16)) for sec, s, e in SECTION.findall(header) if sec == ".bss"]
    if not bss or bss[0][0] == bss[0][1]:
        return []
    start, end = bss[0]
    taken = [(int(s, 16), int(e, 16)) for sec, s, e in SECTION.findall(text.split("\n\n", 1)[1] if "\n\n" in text
                                                                          else "") if sec == ".bss"]
    syms = sorted({(int(a, 16), n) for n, a in re.findall(r"^(\S+) kind:bss\S* addr:0x([0-9a-f]+)",
                                                          (folder / "symbols.txt").read_text(encoding="utf-8"), re.M)
                   if start <= int(a, 16) < end})
    items = []
    shared = {a for i, (a, _n) in enumerate(syms) if i + 1 < len(syms) and syms[i + 1][0] == a}
    for i, (a, n) in enumerate(syms):
        nxt = syms[i + 1][0] if i + 1 < len(syms) else end
        if a in shared:  # two names at one address (an alias label): C cannot define both, leave it to the gap
            items.append((a, None, 0))
        elif not any(s <= a < e for s, e in taken):
            items.append((a, n, nxt - a))
    runs, cur = [], []
    for a, n, size in items:
        if n is None:
            if cur:
                runs.append(cur)
            cur = []
            continue
        contiguous = cur and cur[-1][0] + cur[-1][2] == a
        fits = a % 4 == 0 or size < 4  # mwcc aligns arrays of 4+ bytes to 4
        if cur and contiguous and fits and size > cur[-1][2]:
            cur.append((a, n, size))
            continue
        if cur:
            runs.append(cur)
        cur = [(a, n, size)] if a % 4 == 0 else []
    if cur:
        runs.append(cur)
    # the linker aligns every file's section start to 4: a run must not leave the next file at an odd address
    for r in runs:
        while r and (r[-1][0] + r[-1][2]) % 4:
            r.pop()
    return [r for r in runs if r]


def c_source(run: list[tuple[int, str, int]]) -> str:
    lines = ["/* compiler: 2.0/sp1p5 */", '#include "m2c.h"', ""]
    for a, n, size in run:
        lines.append(f"u32 {n}[{size // 4}];" if size % 4 == 0 and a % 4 == 0 else f"u8 {n}[{size}];")
    return "\n".join(lines) + "\n"


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("--mods", default="")
    ap.add_argument("--skip", nargs="*", default=[], help="file names (src/data/...) not to create")
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()
    want = set(a.mods.split(",")) if a.mods else None
    total = files = 0
    for name, folder in modules().items():
        if want and name not in want:
            continue
        entries = []
        for run in plan(name, folder):
            rel = f"src/data/{name}_bss_{run[0][0]:08x}.c"
            if rel in a.skip:
                continue
            s, e = run[0][0], run[-1][0] + run[-1][2]
            total += e - s
            files += 1
            entries.append(f"\n{rel}:\n    complete\n    .bss        start:0x{s:08x} end:0x{e:08x}\n")
            if not a.dry_run:
                p = ROOT / rel
                p.parent.mkdir(parents=True, exist_ok=True)
                p.write_text(c_source(run), encoding="utf-8", newline="\n")
        if entries and not a.dry_run:
            d = folder / "delinks.txt"
            d.write_text(d.read_text(encoding="utf-8").rstrip("\n") + "\n" + "".join(entries), encoding="utf-8",
                         newline="\n")
    print(f"{files} files, {total} bytes of .bss")


if __name__ == "__main__":
    main()
