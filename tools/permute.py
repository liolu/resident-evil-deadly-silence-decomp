#!/usr/bin/env python3
"""Runs decomp-permuter (https://github.com/simonlindholm/decomp-permuter) on one function.

    python tools/permute.py FUNCTION                      # source = the delinked file containing it
    python tools/permute.py FUNCTION --source my_try.c    # any C file that defines FUNCTION
    python tools/permute.py FUNCTION --minutes 30 -j 8

The permuter randomly rewrites the C code (temporaries, types, statement order...) and keeps
the variants that get closer to the original. Results are written to build/permuter/<FUNCTION>/output-*/.
A score of 0 means a match: copy that code back into the source file, then check with objdiff.

Set PERMUTER_PATH to the decomp-permuter directory (default: tools/decomp-permuter).
Requires bash (Git Bash on Windows), arm-none-eabi-as/objdump and gcc in PATH.
"""

import argparse
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402  (this game's version, ROM name, paths: tools/project.py)
ASM_DIR = project.ASM_DIR
PERMUTER = Path(os.environ.get("PERMUTER_PATH", ROOT / "tools" / "decomp-permuter"))
MWCC = Path(os.environ.get("MWCCARM", ROOT / "tools" / "mwccarm")) / "2.0" / "sp1p5" / "mwccarm.exe"
CC_FLAGS = ("-O4,p -enum int -char signed -str noreuse -proc arm946e -gccext,on -fp soft -inline noauto "
            "-lang=c -interworking -w off -nolink")

PRELUDE = """.syntax unified
.macro arm_func_start name
    .arm
    .balign 4
.endm
.macro arm_func_end name
.endm
.text
.global {name}
.type {name}, %function
"""


def function_asm(name: str) -> str:
    pattern = re.compile(rf"^{re.escape(name)}: .*?^\s+arm_func_end {re.escape(name)}$", re.S | re.M)
    for f in ASM_DIR.glob("*.s"):
        m = pattern.search(f.read_text(encoding="utf-8"))
        if m:
            return re.sub(r";.*$", "", m.group(0), flags=re.M)
    raise SystemExit(f"{name} not found in {ASM_DIR} (run `ninja dis`)")


def source_for(name: str) -> Path:
    for f in (ROOT / "src").rglob("*.c"):
        if re.search(rf"\b{re.escape(name)}\s*\(", f.read_text(encoding="utf-8")):
            return f
    raise SystemExit(f"No source file in src/ defines {name}: pass --source")


def to_bash_path(p: Path) -> str:
    s = str(p.resolve()).replace("\\", "/")
    return re.sub(r"^([A-Za-z]):", lambda m: "/" + m.group(1).lower(), s)


def kill_tree(proc: subprocess.Popen):
    """Stops the permuter and its worker processes (they outlive the parent otherwise).
    Uses psutil rather than `taskkill /T`, which depends on WMI and fails on some Windows installs."""
    import psutil

    try:
        parent = psutil.Process(proc.pid)
        procs = parent.children(recursive=True) + [parent]
    except psutil.NoSuchProcess:
        procs = []
    for p in procs:
        try:
            p.kill()
        except psutil.NoSuchProcess:
            pass
    psutil.wait_procs(procs, timeout=10)
    proc.wait()


def main():
    ap = argparse.ArgumentParser(description="Run decomp-permuter on one function")
    ap.add_argument("function")
    ap.add_argument("--source", type=Path)
    ap.add_argument("--minutes", type=float, default=10.0)
    ap.add_argument("-j", type=int, default=os.cpu_count() or 4)
    args = ap.parse_args()

    if not (PERMUTER / "permuter.py").exists():
        raise SystemExit(f"decomp-permuter not found at {PERMUTER}: clone it and set PERMUTER_PATH")
    for tool in ("bash", "gcc", "arm-none-eabi-as", "arm-none-eabi-objdump"):
        if shutil.which(tool) is None:
            raise SystemExit(f"{tool} not found in PATH")

    work = ROOT / "build" / "permuter" / args.function
    if work.exists():
        shutil.rmtree(work)
    work.mkdir(parents=True)

    # Target object assembled from the original disassembly
    (work / "target.s").write_text(PRELUDE.format(name=args.function) + function_asm(args.function) + "\n")
    subprocess.run(["arm-none-eabi-as", "-mcpu=arm946e-s", str(work / "target.s"), "-o", str(work / "target.o")],
                   check=True)

    # Preprocessed source reduced to the single function
    source = args.source or source_for(args.function)
    pre = subprocess.run(["gcc", "-E", "-P", "-I", str(ROOT / "include"), "-D__attribute__(x)=", str(source)],
                         capture_output=True, text=True, check=True).stdout
    (work / "base.c").write_text(pre, encoding="utf-8")
    subprocess.run([sys.executable, str(PERMUTER / "strip_other_fns.py"), str(work / "base.c"), args.function],
                   check=True)

    (work / "compile.sh").write_text(
        f'#!/bin/bash\n"{to_bash_path(MWCC)}" {CC_FLAGS} -c "$1" -o "$3"\n', newline="\n")
    (work / "settings.toml").write_text(f'func_name = "{args.function}"\ncompiler_type = "mwcc"\n')

    print(f"Permuting {args.function} from {source} for {args.minutes} min ({work.relative_to(ROOT)})")
    proc = subprocess.Popen([sys.executable, str(PERMUTER / "permuter.py"), str(work), "-j", str(args.j),
                             "--stop-on-zero", "--best-only", "--quiet"], cwd=PERMUTER)
    try:
        proc.wait(timeout=args.minutes * 60)
    except (subprocess.TimeoutExpired, KeyboardInterrupt):
        kill_tree(proc)
    outputs = sorted(work.glob("output-*"), key=lambda p: int(p.name.split("-")[1]))
    if not outputs:
        print("No improvement found.")
        return
    best = outputs[0]
    score = int(best.name.split("-")[1])
    print(("MATCH found: " if score == 0 else f"Best score {score}: ") + str(best.relative_to(ROOT) / "source.c"))


if __name__ == "__main__":
    main()
