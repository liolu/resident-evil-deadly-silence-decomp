"""ld_align.py LINKER_CMD... : linker wrapper for objects that start on a halfword (addr % 4 == 2).

dsd writes `ALIGNALL(4);` in every lcf section and mwcc/dsd objects declare `.text` alignment 4, so an
object whose `.text` starts at an address = 2 mod 4 (Thumb BIOS stubs in the secure area, odd-sized
Thumb functions) is padded by 2 bytes at link time and the ROM differs, although the function matches.

For every `config/**/delinks.txt` entry whose .text range starts at 2 mod 4, and for the object that follows
(in lcf order) an entry ending at 2 mod 4, this wrapper:
  * copies the object to <lcf dir>/ld_align/ with the .text section alignment set to 2,
  * writes <lcf dir>/ld_align/<lcf name> where those object lines are wrapped in ALIGNALL(2); ... ALIGNALL(4);
  * writes an objects file pointing at the copies,
It also injects absolute linker symbols listed in config/<version>/arm9/lcf_symbols.txt (`NAME = VALUE;` per line,
e.g. the NitroSDK `SDK_IRQ_STACKSIZE = 0x320;` / `SDK_SYS_STACKSIZE = 0xe60;` that the original lcf defined and
OS code loads from its literal pool) right after `SECTIONS {`.
Then it runs the linker command with the lcf / @objects arguments replaced. Nothing to do -> runs it unchanged.
Inputs are never modified (no ninja dirty loop).
"""
import re, shutil, struct, subprocess, sys
from pathlib import Path


def ranges():
    """{object basename: (start, end)} of .text ranges from every delinks.txt (sources only)."""
    out = {}
    for d in Path('config').glob('**/delinks.txt'):
        cur = None
        for line in d.read_text(encoding='utf-8').splitlines():
            if line and not line.startswith((' ', '\t')) and line.rstrip().endswith(':'):
                cur = Path(line.rstrip()[:-1]).stem + '.o'
            m = re.match(r'\s+\.text\s+start:0x([0-9a-fA-F]+)\s+end:0x([0-9a-fA-F]+)', line)
            if m and cur:
                out[cur] = (int(m.group(1), 16), int(m.group(2), 16))
    return out


def set_text_align(src: Path, dst: Path, align: int):
    b = bytearray(src.read_bytes())
    if b[:4] != b'\x7fELF' or b[4] != 1:
        raise SystemExit(f'ld_align: {src} is not a 32-bit ELF')
    shoff, = struct.unpack_from('<I', b, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from('<HHH', b, 0x2E)
    stroff = struct.unpack_from('<I', b, shoff + shstrndx * shentsize + 16)[0]
    for i in range(shnum):
        h = shoff + i * shentsize
        name_off = struct.unpack_from('<I', b, h)[0]
        name = bytes(b[stroff + name_off:b.index(0, stroff + name_off)]).decode()
        if name == '.text':
            struct.pack_into('<I', b, h + 32, align)
    dst.write_bytes(bytes(b))


def main():
    cmd = sys.argv[1:]
    lcf_i = next((i for i, a in enumerate(cmd) if a.endswith('.lcf')), None)
    obj_i = next((i for i, a in enumerate(cmd) if a.startswith('@')), None)
    if lcf_i is None or obj_i is None:
        sys.exit(subprocess.call(cmd))
    lcf = Path(cmd[lcf_i]); objfile = Path(cmd[obj_i][1:])
    rng = ranges()
    lcf_lines = lcf.read_text(encoding='utf-8').splitlines()
    text_objs = [m.group(1) for l in lcf_lines for m in [re.match(r'\s*(\S+\.o)\(\.text\)\s*$', l)] if m]
    need = set()
    for k, o in enumerate(text_objs):
        s, e = rng.get(o, (0, 0))
        if s % 4 == 2:
            need.add(o)
        if e % 4 == 2 and k + 1 < len(text_objs):
            need.add(text_objs[k + 1])
    symfile = Path('config') / lcf.parent.name / 'arm9' / 'lcf_symbols.txt'
    extra = [l.strip() for l in symfile.read_text(encoding='utf-8').splitlines()
             if l.strip() and not l.strip().startswith('#')] if symfile.exists() else []
    if not need and not extra:
        sys.exit(subprocess.call(cmd))
    out = lcf.parent / 'ld_align'; out.mkdir(exist_ok=True)
    paths = [p.strip() for p in objfile.read_text(encoding='utf-8').splitlines() if p.strip()]
    new_paths = []
    for p in paths:
        name = Path(p.strip('"')).name
        if name in need:
            dst = out / name
            set_text_align(Path(p.strip('"')), dst, 2)
            new_paths.append(f'"{dst}"')
        else:
            new_paths.append(p)
    new_lcf = []
    for l in lcf_lines:
        m = re.match(r'(\s*)(\S+\.o)\(\.text\)\s*$', l)
        if m and m.group(2) in need:
            new_lcf += [f'{m.group(1)}ALIGNALL(2);', l, f'{m.group(1)}ALIGNALL(4);']
        else:
            new_lcf.append(l)
        if extra and l.strip() == 'SECTIONS {':
            new_lcf += ['    ' + x for x in extra]
            extra = []
    (out / lcf.name).write_text('\n'.join(new_lcf) + '\n', encoding='utf-8')
    (out / objfile.name).write_text('\n'.join(new_paths) + '\n', encoding='utf-8')
    cmd[lcf_i] = str(out / lcf.name)
    cmd[obj_i] = '@' + str(out / objfile.name)
    if need:
        print(f'ld_align: {len(need)} object(s) at halfword alignment: {" ".join(sorted(need))}', file=sys.stderr)
    sys.exit(subprocess.call(cmd))


if __name__ == '__main__':
    main()
