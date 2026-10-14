#!/usr/bin/env python3
"""Compiler probe: compiles a C file with every installed mwccarm version and compares
one function against the original bytes of the game.

`bl` targets and literal pool words (relocated addresses) are masked, so only the
instructions themselves have to match.

Usage:
    python tools/probe_compiler.py tools/probes/hie_pop.c HIE_fn_bPopOnCameraMatrixStack 0x0201b39c
    python tools/probe_compiler.py FILE.c FUNCTION ADDRESS --flags=-O4,p --flags=-O4,s --only 2.0/sp1p5 --show

The compiler root is taken from --mwcc, else $MWCCARM, else tools/mwccarm.
"""

import argparse
import os
import shutil
import struct
import subprocess
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
import sys  # noqa: E402
sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402  (this game's version, ROM name, paths: tools/project.py)
ARM9_BIN = project.EXTRACT / "arm9" / "arm9.bin"
SYMBOLS = project.SYMBOLS
ARM9_BASE = 0x02000000

BASE_FLAGS = "-enum int -char signed -str noreuse -proc arm946e -gccext,on -fp soft -inline noauto -lang=c -interworking -w off -nolink"


def target_bytes(addr: int, size: int) -> bytes:
    data = ARM9_BIN.read_bytes()
    return data[addr - ARM9_BASE: addr - ARM9_BASE + size]


def symbol_size(addr: int) -> int:
    for line in SYMBOLS.read_text().splitlines():
        if f"addr:0x{addr:08x}" in line and "size=" in line:
            return int(line.split("size=")[1].split(")")[0], 16)
    raise SystemExit(f"No size found for 0x{addr:08x} in symbols.txt, pass it as an argument")


def compiled_function(obj: Path, name: str) -> bytes | None:
    """Extracts a function's bytes from an ELF object (no external dependency)."""
    d = obj.read_bytes()
    shoff, = struct.unpack_from("<I", d, 0x20)
    shentsize, shnum, _shstrndx = struct.unpack_from("<HHH", d, 0x2E)
    secs = [struct.unpack_from("<IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]
    for s in secs:
        if s[1] != 2:  # SHT_SYMTAB
            continue
        strtab = secs[s[6]]
        for i in range(s[5] // 16):
            st_name, st_value, st_size, _info, _other, st_shndx = struct.unpack_from("<IIIBBH", d, s[4] + i * 16)
            end = d.index(b"\0", strtab[4] + st_name)
            if d[strtab[4] + st_name:end].decode() == name:
                sec = secs[st_shndx]
                return d[sec[4] + st_value: sec[4] + st_value + st_size]
    return None


def compare(target: bytes, cand: bytes) -> tuple[int, int]:
    """Returns (differing instructions, total). Masks bl targets and the literal pool."""
    n = len(target) // 4
    if len(cand) != len(target):
        return (n, n)
    tw = struct.unpack(f"<{n}I", target)
    cw = struct.unpack(f"<{n}I", cand)
    # Literal pool words: loaded by pc-relative ldr instructions
    pool = set()
    for i, w in enumerate(tw):
        if (w & 0x0F7F0000) == 0x051F0000:  # ldr rX, [pc, #imm]
            off = w & 0xFFF
            pool.add(i + 2 + (off // 4 if w & 0x00800000 else -(off // 4)))
    bad = 0
    for i, (a, b) in enumerate(zip(tw, cw)):
        if i in pool:
            continue
        if (a & 0x0F000000) == 0x0B000000:  # bl: only compare condition/opcode
            a &= 0xFF000000
            b &= 0xFF000000
        if a != b:
            bad += 1
    return (bad, n)


def disasm(code: bytes, addr: int) -> list[str]:
    objdump = shutil.which("arm-none-eabi-objdump")
    if objdump is None:
        return ["(arm-none-eabi-objdump not found in PATH)"]
    with tempfile.TemporaryDirectory() as tmp:
        f = Path(tmp) / "code.bin"
        f.write_bytes(code)
        r = subprocess.run([objdump, "-D", "-b", "binary", "-marm", f"--adjust-vma={addr}", str(f)],
                           capture_output=True, text=True)
    out = []
    for line in r.stdout.splitlines():
        parts = line.split("\t")
        if len(parts) >= 3 and parts[0].strip().endswith(":"):
            out.append(" ".join(parts[2:]).split(";")[0].strip())
    return out


def show(target: bytes, cand: bytes, addr: int):
    t, c = disasm(target, addr), disasm(cand, addr)
    print(f"     {'TARGET':38} | CANDIDATE")
    for i in range(max(len(t), len(c))):
        a = t[i] if i < len(t) else ""
        b = c[i] if i < len(c) else ""
        print(f"   {' ' if a == b else '*'} {a:38} | {b}")


def main():
    ap = argparse.ArgumentParser(description="Compile a function with every mwccarm version and compare it to the game")
    ap.add_argument("source", type=Path)
    ap.add_argument("function")
    ap.add_argument("address", type=lambda x: int(x, 0))
    ap.add_argument("size", type=lambda x: int(x, 0), nargs="?", help="Function size (default: read from symbols.txt)")
    ap.add_argument("--flags", action="append", help="Optimization flags to test, repeatable (write --flags=-O4,p)")
    ap.add_argument("--only", help="Only test this version, e.g. 2.0/sp1p5")
    ap.add_argument("--show", action="store_true", help="Print target/candidate disassembly side by side")
    ap.add_argument("--mwcc", type=Path, help="Compiler root directory")
    args = ap.parse_args()

    mwcc_root = args.mwcc or Path(os.environ.get("MWCCARM", ROOT / "tools" / "mwccarm"))
    if args.size is None:
        args.size = symbol_size(args.address)
    flag_sets = args.flags or ["-O4,p", "-O4,s", "-O2", "-O3"]
    target = target_bytes(args.address, args.size)
    versions = sorted(p.parent.relative_to(mwcc_root).as_posix() for p in mwcc_root.rglob("mwccarm.exe"))
    if args.only:
        versions = [v for v in versions if v == args.only]
    if not versions:
        raise SystemExit(f"No mwccarm.exe found under {mwcc_root}")

    with tempfile.TemporaryDirectory() as tmp:
        for ver in versions:
            cc = mwcc_root / ver / "mwccarm.exe"
            row = []
            for flags in flag_sets:
                obj = Path(tmp) / "probe.o"
                obj.unlink(missing_ok=True)
                cmd = f'"{cc}" {flags} {BASE_FLAGS} -i "{ROOT / 'include'}" -c "{args.source.resolve()}" -o "{obj}"'
                r = subprocess.run(cmd, shell=True, capture_output=True, text=True, cwd=tmp)
                if r.returncode != 0 or not obj.exists():
                    if args.show:
                        print("\n".join((r.stdout + r.stderr).strip().splitlines()[:12]))
                    row.append(f"{flags}: compile error")
                    continue
                cand = compiled_function(obj, args.function)
                if cand is None:
                    row.append(f"{flags}: function not found")
                    continue
                bad, n = compare(target, cand)
                if args.show:
                    show(target, cand, args.address)
                tag = "MATCH" if bad == 0 else f"{bad}/{n} diff" + ("" if len(cand) == len(target) else f" (size 0x{len(cand):x})")
                row.append(f"{flags}: {tag}")
            print(f"{ver:14} | " + " | ".join(row))


if __name__ == "__main__":
    main()
