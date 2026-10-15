#!/usr/bin/env python3
"""Applies the relocation fixes that `dsd delink` suggests, until delinking works.

    python tools/delink_fix.py            # configure + ninja, fix relocs.txt, repeat (at most 20 rounds)

dsd stops on a relocation whose target is not a symbol, typically a pointer to a Thumb function (address + 1):

    [ERROR] No symbol found for relocation from 0x022773c8 in overlay 255 to 0x01ffbaa1 in ITCM
    [ERROR] Perhaps you want to reference the symbol .L_01ffbaa0 with 'to:0x01ffbaa0 add:0x1' instead?

The line `from:0x022773c8 ... to:0x01ffbaa1` of the module's relocs.txt becomes `to:0x01ffbaa0` (Club House
Games). Not dsd's `add:0x1`: the label is a Thumb one, the linker already sets bit 0 for it, and the word would
become 0x01ffbaa2. Only dsd's own suggestions are applied; other errors stop the tool.
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402

ERR = re.compile(r"No symbol found for relocation from 0x([0-9a-f]+) in (.+?) to 0x([0-9a-f]+) in .+\n"
                 r".*Perhaps you want to reference the symbol \S+ with 'to:0x([0-9a-f]+) add:(0x[0-9a-f]+|\d+)'")


def relocs_file(module: str) -> Path:
    m = re.match(r"overlay (\d+)", module)
    if m:
        return project.ARM9 / "overlays" / f"ov{int(m.group(1)):03d}" / "relocs.txt"
    return {"ITCM": project.ARM9 / "itcm" / "relocs.txt", "DTCM": project.ARM9 / "dtcm" / "relocs.txt"}.get(
        module, project.ARM9 / "relocs.txt")


def main():
    for rnd in range(20):
        subprocess.run([sys.executable, "tools/configure.py", project.VERSION], cwd=ROOT, capture_output=True)
        r = subprocess.run(["ninja"], cwd=ROOT, capture_output=True, text=True, encoding="utf-8", errors="replace")
        out = re.sub(r"\x1b\[[0-9;]*m", "", r.stdout + r.stderr)
        fixes = ERR.findall(out)
        if not fixes:
            print("delink OK" if "Failed to delink" not in out else "delink fails for another reason:\n" +
                  "\n".join(l for l in out.splitlines() if "ERROR" in l)[:2000])
            return
        for frm, module, to, new_to, add in fixes:
            p = relocs_file(module)
            t = p.read_text(encoding="utf-8")
            pat = re.compile(rf"^(from:0x{frm} kind:\S+ )to:0x{to}\b", re.M)
            # a Thumb pointer (target = label + 1): the linker adds the Thumb bit itself
            thumb = int(add, 0) == 1 and int(to, 16) == int(new_to, 16) + 1
            n = pat.sub(rf"\g<1>to:0x{new_to}" + ("" if thumb else f" add:{add}"), t)
            if n == t:
                print(f"line from:0x{frm} to:0x{to} not found in {p}")
                return
            p.write_text(n, encoding="utf-8", newline="\n")
            print(f"round {rnd + 1}: {p.relative_to(ROOT).as_posix()}: from 0x{frm} -> to:0x{new_to}"
                  + ("" if thumb else f" add:{add}"))


if __name__ == "__main__":
    main()
