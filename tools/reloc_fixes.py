#!/usr/bin/env python3
"""Per-game fix for false pointers found by dsd (run from a project root, or pass --project).

dsd turns every 4-byte value that looks like an address into a relocation in relocs.txt. A table of bytes such as
`02 02 03 02` (= 0x02030202) is taken for a pointer into the main program; at link time that "pointer" has no
symbol, the 4 bytes become zeros and `dsd check modules` fails (seen on Heroes of Mana, overlay 123).

Nothing changes for a game unless it has a file `config/<version>/reloc_fixes.txt`:

    # <module> <address of the relocation>   # reason
    overlays/ov123 0x020d4ec4                # bytes 02 02 03 02 read as pointer 0x02030202

<module> is `main`, `itcm`, `dtcm` or `overlays/ovNNN`. Only `kind:load` relocations can be dropped.

    python tools/reloc_fixes.py apply      # remove the listed relocations (idempotent; configure.py calls it)
    python tools/reloc_fixes.py detect     # compare the built modules with the original ones and explain the gaps
    python tools/reloc_fixes.py detect --write   # ... and add the false pointers to reloc_fixes.txt, then apply
    python tools/reloc_fixes.py auto       # ninja; if it fails, detect --write; repeat (3 rounds at most)
"""

import argparse
import re
import subprocess
import sys
from pathlib import Path

HEADER = ("# False pointers that dsd found in data (see tools/reloc_fixes.py).\n"
          "# <module> <address>   # reason\n")


def versions(root: Path) -> list[str]:
    return sorted(p.parent.parent.name for p in (root / "config").glob("*/arm9/config.yaml"))


def module_dirs(root: Path, ver: str) -> dict[str, Path]:
    arm9 = root / "config" / ver / "arm9"
    mods = {"main": arm9, "itcm": arm9 / "itcm", "dtcm": arm9 / "dtcm"}
    for ov in sorted((arm9 / "overlays").glob("ov*")):
        mods[f"overlays/{ov.name}"] = ov
    return {k: v for k, v in mods.items() if (v / "relocs.txt").exists()}


def read_fixes(root: Path, ver: str) -> list[tuple[str, int, str]]:
    path = root / "config" / ver / "reloc_fixes.txt"
    out = []
    if path.exists():
        for line in path.read_text(encoding="utf-8").splitlines():
            body, _, why = line.partition("#")
            parts = body.split()
            if len(parts) == 2:
                out.append((parts[0], int(parts[1], 16), why.strip()))
    return out


def apply(root: Path, ver: str, quiet: bool = False) -> int:
    """Removes the listed `kind:load` relocations from the modules' relocs.txt. Returns how many were removed."""
    fixes = read_fixes(root, ver)
    if not fixes:
        return 0
    mods = module_dirs(root, ver)
    removed = 0
    for module, addr, _ in fixes:
        if module not in mods:
            print(f"reloc_fixes: unknown module {module!r} in config/{ver}/reloc_fixes.txt")
            continue
        path = mods[module] / "relocs.txt"
        lines = path.read_text(encoding="utf-8").splitlines(keepends=True)
        keep = [l for l in lines if not re.match(rf"from:0x0*{addr:x}\s+kind:load\b", l.strip(), re.I)]
        if len(keep) != len(lines):
            path.write_text("".join(keep), encoding="utf-8", newline="")
            removed += len(lines) - len(keep)
    if removed and not quiet:
        print(f"reloc_fixes: {removed} false pointer(s) removed ({ver})")
    return removed


def module_base(mod_dir: Path) -> int | None:
    """Load address of a module: the lowest section start of its delinks.txt."""
    path = mod_dir / "delinks.txt"
    starts = [int(m, 16) for m in re.findall(r"^\s+\.\w+\s+start:0x([0-9a-fA-F]+)", path.read_text(), re.M)] \
        if path.exists() else []
    return min(starts) if starts else None


def binaries(root: Path, ver: str, module: str) -> tuple[Path, Path]:
    """(rebuilt, original) binaries of a module."""
    build, extract = root / "build" / ver / "build", root / "extract" / ver
    if module == "main":
        return build / "arm9.bin", extract / "arm9" / "arm9.bin"
    if module in ("itcm", "dtcm"):
        return build / f"{module}.bin", extract / "arm9" / f"{module}.bin"
    n = module.split("/")[-1][2:]
    return build / f"arm9_ov{n}.bin", extract / "arm9_overlays" / f"ov{n}.bin"


def detect(root: Path, ver: str, write: bool) -> int:
    """Lists the words that differ between the rebuilt and the original modules, and the relocation behind each."""
    mods = module_dirs(root, ver)
    found, unexplained = [], []
    for module, d in mods.items():
        built, orig = binaries(root, ver, module)
        base = module_base(d)
        if not built.exists() or not orig.exists() or base is None:
            continue
        a, b = built.read_bytes(), orig.read_bytes()
        if len(a) != len(b):
            # Everything after the extra/missing bytes is shifted: thousands of pointers differ, none is "false"
            unexplained.append(f"{module}: size {len(a):#x} (rebuilt) vs {len(b):#x} (original), "
                               f"{len(a) - len(b):+d} bytes: layout problem, not a false pointer")
            continue
        words = sorted({i & ~3 for i in range(min(len(a), len(b))) if a[i] != b[i]})
        if not words:
            continue
        relocs = (d / "relocs.txt").read_text(encoding="utf-8")
        for off in words:
            addr = base + off
            m = re.search(rf"^from:0x0*{addr:x}\s+kind:load\s+to:0x([0-9a-fA-F]+)", relocs, re.M | re.I)
            value = int.from_bytes(b[off:off + 4], "little")
            built_value = int.from_bytes(a[off:off + 4], "little")
            # A false pointer is rebuilt as zeros (no symbol to resolve it) and its original bytes are the target
            if m and built_value == 0 and value == int(m.group(1), 16):
                bytes_ = " ".join(f"{x:02x}" for x in b[off:off + 4])
                found.append((module, addr, f"bytes {bytes_} read as pointer 0x{int(m.group(1), 16):08x}"
                              if value == int(m.group(1), 16) else f"pointer to 0x{int(m.group(1), 16):08x}"))
            elif len(unexplained) < 5:
                unexplained.append(f"{module}: word at {addr:#010x} differs (original {value:#010x}, rebuilt "
                                   f"{built_value:#010x}) and is not an unresolved pointer")
    if not found and not unexplained:
        print(f"{ver}: all built modules are identical to the originals, nothing to fix")
        return 0
    for module, addr, why in found:
        print(f"  false pointer: {module} {addr:#010x}  # {why}")
    for line in unexplained:
        print(f"  NOT a false pointer: {line}")
    if write and found:
        path = root / "config" / ver / "reloc_fixes.txt"
        text = path.read_text(encoding="utf-8") if path.exists() else HEADER
        known = {(m, a) for m, a, _ in read_fixes(root, ver)}
        for module, addr, why in found:
            if (module, addr) not in known:
                text += f"{module} {addr:#010x}   # {why}\n"
        path.write_text(text, encoding="utf-8", newline="\n")
        apply(root, ver)
    return len(found)


def ninja_ok(root: Path) -> bool:
    r = subprocess.run(["ninja"], cwd=root, capture_output=True, text=True, encoding="utf-8", errors="replace")
    return r.returncode == 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("command", choices=["apply", "detect", "auto"])
    ap.add_argument("--write", action="store_true", help="detect: record the false pointers and apply them")
    ap.add_argument("--project", type=Path, default=Path.cwd(), help="project root (default: current directory)")
    args = ap.parse_args()
    root = args.project.resolve()
    vers = versions(root)
    if not vers:
        raise SystemExit(f"No config/<version>/arm9/config.yaml under {root}")
    for ver in vers:
        if args.command == "apply":
            apply(root, ver)
        elif args.command == "detect":
            detect(root, ver, args.write)
        else:
            for round_ in range(1, 4):
                if ninja_ok(root):
                    print(f"{ver}: build OK" + (f" after {round_ - 1} fix round(s)" if round_ > 1 else ""))
                    break
                print(f"{ver}: build failed (round {round_}), looking for false pointers...")
                if not detect(root, ver, write=True):
                    print(f"{ver}: nothing fixable by this tool, the failure has another cause")
                    sys.exit(1)
            else:
                sys.exit(1)


if __name__ == "__main__":
    main()
