#!/usr/bin/env python3
"""Builds the ROM with dsd, working around what dsd cannot rebuild byte for byte. What ninja runs:

    python tools/rom_build.py <dsd> [dsd flags] rom build --config <rom_config.yaml> --rom <rom> [...]

Before the build: overlays protected by DSProtect (Nintendo's anti-piracy: some functions are stored encrypted).
dsd decrypts them when extracting and encrypts them again when building, but its encryption of the integrity
check functions differs from the original (Professor Layton and the Spectre's Call, overlay 3), so the
compressed overlay changes size and the whole ROM after it moves. When the linked overlay is exactly the extracted
one (its code was not changed), dsd gets the original encrypted bytes instead (taken from extract/baserom_*.nds)
with the protection removed from its config: nothing left to encrypt, same bytes as the original. A changed
overlay is left to dsd.

After the build:
  - the banner icon (banner_fix.py: palettes with the same colour twice);
  - empty files: Nintendo's tool gave them another address than dsd does (Tom and Jerry Tales: structor3/adf/...).
    They hold no data, so their FAT entry takes the original address back.
"""
import re
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import banner_fix  # noqa: E402


def u32(b, o):
    return struct.unpack_from("<I", b, o)[0]


def blz_decompress(data: bytes) -> bytes:
    """Nintendo's backward LZ (compressed ARM9 and overlays)."""
    if len(data) < 8:
        return data
    footer, extra = u32(data, len(data) - 8), u32(data, len(data) - 4)
    hdr, comp_len = footer >> 24, footer & 0xFFFFFF
    out = bytearray(data) + bytearray(extra)
    src, dst, end = len(data) - hdr, len(out), len(data) - comp_len
    while src > end:
        src -= 1
        flags = data[src]
        for _ in range(8):
            if src <= end:
                break
            if flags & 0x80:
                src -= 2
                v = data[src] | (data[src + 1] << 8)
                ln, disp = (v >> 12) + 3, (v & 0xFFF) + 3
                for _ in range(ln):
                    dst -= 1
                    out[dst] = out[dst + disp]
            else:
                src -= 1
                dst -= 1
                out[dst] = data[src]
            flags <<= 1
    return bytes(out)


def original_overlay(rom: bytes, ov_id: int) -> bytes | None:
    """Decompressed contents of an ARM9 overlay of the original ROM (still encrypted where it was)."""
    table, n, fat = u32(rom, 0x50), u32(rom, 0x54) // 32, u32(rom, 0x48)
    if ov_id >= n:
        return None
    e = table + ov_id * 32
    fid, flag = u32(rom, e + 24), u32(rom, e + 28)
    data = rom[u32(rom, fat + fid * 8): u32(rom, fat + fid * 8 + 4)]
    return blz_decompress(data) if flag & 0x01000000 else data


def dsprot_config(config: Path) -> Path:
    """A copy of rom_config.yaml where the unchanged DSProtect overlays come already encrypted. Returns the config
    to give dsd (the original one when there is nothing to do)."""
    base = next((ROOT / "extract").glob("baserom*.nds"), None)
    text = config.read_text(encoding="utf-8")
    m = re.search(r"^arm9_overlays: (\S+)", text, re.M)
    if base is None or not m or m.group(1) == "null":
        return config
    ov_yaml = config.parent / m.group(1)
    ovs = ov_yaml.read_text(encoding="utf-8")
    if "dsprot:" not in ovs:
        return config
    version = config.parent.parent.name  # build/<version>/build/rom_config.yaml
    rom = base.read_bytes()
    blocks = re.split(r"(?m)^(?=  - id: )", ovs)
    changed = 0
    for k, b in enumerate(blocks):
        mid = re.match(r"  - id: (\d+)\n", b)
        if not mid or "\n    dsprot:" not in b:
            continue
        ov_id = int(mid.group(1))
        fname = re.search(r"^    file_name: (\S+)", b, re.M).group(1)
        built = config.parent / fname
        extracted = ROOT / "extract" / version / "arm9_overlays" / f"ov{ov_id:03d}.bin"
        if not (built.exists() and extracted.exists()) or built.read_bytes() != extracted.read_bytes():
            continue  # the code changed: dsd has to encrypt it
        enc = original_overlay(rom, ov_id)
        code_size = int(re.search(r"^    code_size: (\d+)", b, re.M).group(1))
        if enc is None or len(enc) < code_size:
            continue
        out = config.parent / "dsprot" / fname
        out.parent.mkdir(exist_ok=True)
        out.write_bytes(enc[:code_size])
        b = re.sub(r"^    file_name: \S+", f"    file_name: dsprot/{fname}", b, flags=re.M)
        b = re.sub(r"(?m)^    dsprot:\n(?:      .*\n?)*", "", b)
        blocks[k] = b
        changed += 1
    if not changed:
        return config
    new_ov = ov_yaml.with_name(ov_yaml.stem + ".dsprot.yaml")
    new_ov.write_text("".join(blocks), encoding="utf-8", newline="\n")
    new_cfg = config.with_name(config.stem + ".dsprot.yaml")
    new_cfg.write_text(text.replace(f"arm9_overlays: {m.group(1)}", f"arm9_overlays: {new_ov.name}", 1),
                       encoding="utf-8", newline="\n")
    print(f"rom_build: {changed} DSProtect overlay(s) unchanged, original encrypted bytes used")
    return new_cfg


def empty_files_fix(orig: bytes, rom: bytearray) -> int:
    """FAT entries of empty files (start == end in both ROMs) set to the original address."""
    fo, fn = u32(orig, 0x48), u32(rom, 0x48)
    if u32(orig, 0x4C) != u32(rom, 0x4C):
        return 0
    n = 0
    for i in range(u32(orig, 0x4C) // 8):
        so, eo = u32(orig, fo + i * 8), u32(orig, fo + i * 8 + 4)
        sn, en = u32(rom, fn + i * 8), u32(rom, fn + i * 8 + 4)
        if so == eo and sn == en and so != sn:
            struct.pack_into("<II", rom, fn + i * 8, so, eo)
            n += 1
    return n


def main():
    cmd = sys.argv[1:]
    if "--config" in cmd:
        i = cmd.index("--config") + 1
        cmd[i] = str(dsprot_config(Path(cmd[i])))
    r = subprocess.run(cmd)
    if r.returncode:
        sys.exit(r.returncode)
    if "--rom" in cmd:
        rom_path = Path(cmd[cmd.index("--rom") + 1])
        base = next((ROOT / "extract").glob("baserom*.nds"), None)
        if base is not None and rom_path.exists():
            rom, orig = bytearray(rom_path.read_bytes()), base.read_bytes()
            n = banner_fix.fix(orig, rom)
            if n > 0:
                print(f"rom_build: {n} icon pixels given their original palette index back")
            e = empty_files_fix(orig, rom)
            if e:
                print(f"rom_build: {e} empty files given their original address back")
            if n > 0 or e:
                rom_path.write_bytes(rom)


if __name__ == "__main__":
    main()
