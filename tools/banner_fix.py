#!/usr/bin/env python3
"""Puts the original palette indices back into the icon of a rebuilt ROM.

    python tools/banner_fix.py <rebuilt rom>      # ninja runs it through tools/rom_build.py

dsd extracts the 32x32 icon of the banner as a colour PNG. When the icon's 16-colour palette holds the same colour
twice (Spore Creatures: two whites; Star Wars Lethal Alliance: three repeated colours), the PNG cannot say which of
the two indices a pixel used, so the rebuilt icon differs from the original while looking the same. For every
pixel whose colour is still the original one, this takes the original index back (an edited icon keeps its new
pixels), then recomputes the banner CRCs. It does nothing when the icon already matches or when the original ROM
(extract/baserom_*.nds) is missing.
"""
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BITMAP, PALETTE, TITLES = 0x20, 0x220, 0x240
CRC_RANGES = {1: [(0x02, 0x20, 0x840)], 2: [(0x02, 0x20, 0x840), (0x04, 0x20, 0x940)],
              3: [(0x02, 0x20, 0x840), (0x04, 0x20, 0x940), (0x06, 0x20, 0xA40)],
              0x103: [(0x02, 0x20, 0x840), (0x04, 0x20, 0x940), (0x06, 0x20, 0xA40), (0x08, 0x1240, 0x23C0)]}


def crc16(data: bytes) -> int:
    crc = 0xFFFF
    for b in data:
        crc ^= b
        for _ in range(8):
            crc = (crc >> 1) ^ 0xA001 if crc & 1 else crc >> 1
    return crc


def fix(orig: bytes, rom: bytearray) -> int:
    """Pixels given their original index back; -1 if the banners cannot be compared."""
    bo, bn = struct.unpack_from("<I", orig, 0x68)[0], struct.unpack_from("<I", rom, 0x68)[0]
    if not bo or not bn or bn + TITLES > len(rom):
        return -1
    if orig[bo:bo + 0x840] == rom[bn:bn + 0x840]:
        return 0
    po = struct.unpack_from("<16H", orig, bo + PALETTE)
    pn = struct.unpack_from("<16H", rom, bn + PALETTE)
    changed = 0
    for i in range(BITMAP, PALETTE):
        o, n = orig[bo + i], rom[bn + i]
        new = 0
        for shift in (0, 4):
            oi, ni = (o >> shift) & 0xF, (n >> shift) & 0xF
            keep = oi if oi != ni and (po[oi] & 0x7FFF) == (pn[ni] & 0x7FFF) else ni
            changed += keep != ni
            new |= keep << shift
        rom[bn + i] = new
    version = struct.unpack_from("<H", rom, bn)[0]
    for at, s, e in CRC_RANGES.get(version, CRC_RANGES[1]):
        if bn + e <= len(rom):
            struct.pack_into("<H", rom, bn + at, crc16(rom[bn + s: bn + e]))
    return changed


def main():
    args = sys.argv[1:]
    rom_path = Path(args[0]) if args else None
    base = next((ROOT / "extract").glob("baserom*.nds"), None)
    if rom_path is None or base is None or not rom_path.exists():
        return
    rom = bytearray(rom_path.read_bytes())
    n = fix(base.read_bytes(), rom)
    if n > 0:
        rom_path.write_bytes(rom)
        print(f"banner_fix: {n} icon pixels given their original palette index back")


if __name__ == "__main__":
    main()
