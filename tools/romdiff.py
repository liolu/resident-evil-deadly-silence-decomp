#!/usr/bin/env python3
"""Where the rebuilt ROM differs from the original one, region by region: header fields, ARM9 / ARM7, overlay
tables, file name table, FAT, banner, each file of the file system, padding.

    python tools/romdiff.py                      # extract/baserom_<game>_<ver>.nds against <game>_<ver>.nds
    python tools/romdiff.py <original> <rebuilt>

For the games whose modules all pass `dsd check` but whose ROM SHA-1 differs (the difference is outside the code).
"""
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))

HEADER_FIELDS = [  # (offset, size, name)
    (0x00, 12, "title"), (0x0C, 4, "game code"), (0x10, 2, "maker"), (0x12, 1, "unit code"), (0x14, 1, "card size"),
    (0x1E, 1, "rom version"), (0x1F, 1, "autostart"),
    (0x20, 4, "arm9 rom offset"), (0x24, 4, "arm9 entry"), (0x28, 4, "arm9 ram address"), (0x2C, 4, "arm9 size"),
    (0x30, 4, "arm7 rom offset"), (0x34, 4, "arm7 entry"), (0x38, 4, "arm7 ram address"), (0x3C, 4, "arm7 size"),
    (0x40, 4, "fnt offset"), (0x44, 4, "fnt size"), (0x48, 4, "fat offset"), (0x4C, 4, "fat size"),
    (0x50, 4, "arm9 overlay table offset"), (0x54, 4, "arm9 overlay table size"),
    (0x58, 4, "arm7 overlay table offset"), (0x5C, 4, "arm7 overlay table size"),
    (0x60, 4, "card control normal"), (0x64, 4, "card control key1"), (0x68, 4, "banner offset"),
    (0x6C, 2, "secure area crc"), (0x6E, 2, "secure area delay"), (0x70, 4, "arm9 autoload callback"),
    (0x74, 4, "arm7 autoload callback"), (0x78, 8, "secure area disable"), (0x80, 4, "rom size used"),
    (0x84, 4, "header size"), (0x88, 4, "arm9 module params offset"), (0x8C, 4, "arm7 module params offset"),
    (0x94, 2, "nand end of rom"), (0x96, 2, "nand start of rw"), (0x15C, 2, "logo crc"), (0x15E, 2, "header crc"),
]


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]


def regions(rom: bytes) -> list[tuple[int, int, str]]:
    """[(start, end, name)] of everything the header and the FAT point to."""
    out = [(0, 0x4000, "header + secure area")]
    for off, size, name in ((0x20, 0x2C, "ARM9"), (0x30, 0x3C, "ARM7"), (0x40, 0x44, "file name table"),
                            (0x48, 0x4C, "FAT"), (0x50, 0x54, "ARM9 overlay table"), (0x58, 0x5C, "ARM7 overlay table")):
        a, n = u32(rom, off), u32(rom, size)
        if n:
            out.append((a, a + n, name))
    if u32(rom, 0x68):
        b = u32(rom, 0x68)
        out.append((b, b + 0x23C0 if b + 0x23C0 <= len(rom) else len(rom), "banner"))
    fat, fat_size = u32(rom, 0x48), u32(rom, 0x4C)
    names = file_names(rom)
    ov9 = {u32(rom, u32(rom, 0x50) + i * 32 + 24): i for i in range(u32(rom, 0x54) // 32)}
    for i in range(fat_size // 8):
        s, e = u32(rom, fat + i * 8), u32(rom, fat + i * 8 + 4)
        if e > s:
            label = names.get(i) or (f"ARM9 overlay {ov9[i]}" if i in ov9 else f"file id {i}")
            out.append((s, e, label))
    return sorted(out)


def file_names(rom: bytes) -> dict[int, str]:
    """{file id: path} from the file name table."""
    fnt = u32(rom, 0x40)
    out = {}

    def walk(dir_id: int, prefix: str):
        entry = fnt + (dir_id & 0xFFF) * 8
        off, first = u32(rom, entry), struct.unpack_from("<H", rom, entry + 4)[0]
        p, fid = fnt + off, first
        while True:
            ln = rom[p]
            p += 1
            if ln == 0:
                break
            name = rom[p: p + (ln & 0x7F)].decode("latin-1")
            p += ln & 0x7F
            if ln & 0x80:
                sub = struct.unpack_from("<H", rom, p)[0]
                p += 2
                walk(sub, f"{prefix}{name}/")
            else:
                out[fid] = prefix + name
                fid += 1

    try:
        walk(0xF000, "")
    except (IndexError, struct.error):
        pass
    return out


def diff_runs(a: bytes, b: bytes, gap: int = 16) -> list[tuple[int, int]]:
    n = min(len(a), len(b))
    runs, i = [], 0
    while i < n:
        if a[i] != b[i]:
            j = i
            last = i
            while j < n and j - last <= gap:
                if a[j] != b[j]:
                    last = j
                j += 1
            runs.append((i, last + 1))
            i = last + 1
        else:
            i += 1
    return runs


def main():
    if len(sys.argv) == 3:
        orig, new = Path(sys.argv[1]), Path(sys.argv[2])
    else:
        import project
        orig = ROOT / "extract" / f"baserom_{project.GAME}_{project.VERSION}.nds"
        if not orig.exists():
            orig = next((ROOT / "extract").glob("baserom*.nds"))
        new = ROOT / project.ROM_NAME
    a, b = orig.read_bytes(), new.read_bytes()
    print(f"original {orig.name}: {len(a)} bytes, rebuilt {new.name}: {len(b)} bytes")
    for off, size, name in HEADER_FIELDS:
        if a[off:off + size] != b[off:off + size]:
            fa = int.from_bytes(a[off:off + size], "little") if size <= 4 else a[off:off + size]
            fb = int.from_bytes(b[off:off + size], "little") if size <= 4 else b[off:off + size]
            print(f"  header {name} (0x{off:03x}): {fa:#x} -> {fb:#x}" if size <= 4 else f"  header {name}: {fa} -> {fb}")
    ra = regions(a)
    runs = diff_runs(a, b)
    print(f"{len(runs)} differing runs, {sum(e - s for s, e in runs)} bytes")
    shown = 0
    for s, e in runs:
        owners = [n for rs, re_, n in ra if rs < e and s < re_] or ["padding / unused"]
        if shown < 40:
            print(f"  0x{s:08x}-0x{e:08x} ({e - s} bytes): {', '.join(owners[:3])}")
        shown += 1
    if len(a) != len(b):
        tail = a[len(b):] if len(a) > len(b) else b[len(a):]
        print(f"size differs; the extra bytes are {'all 0xFF' if set(tail) == {0xFF} else 'all 0' if set(tail) == {0} else 'data'}")


if __name__ == "__main__":
    main()
