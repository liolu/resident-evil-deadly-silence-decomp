#!/usr/bin/env python3
"""Ghidra drafts: a second decompiler's reading of functions, next to m2c's.

    python tools/ghidra_draft.py                     # ARM functions of the main module with no usable m2c draft
    python tools/ghidra_draft.py --names a,b --max 50
    python tools/ghidra_draft.py --all-unmatched     # every function not matched yet (slow on a big game)

Ghidra (headless, from $PATH or decomp ds/tools/ghidra_*) imports the main module (extract/<ver>/arm9/arm9.bin at
0x02000000, ARMv5T) once into build/ghidra/project, applies symbols.txt (functions, ARM or Thumb, and data names)
and writes build/ghidra/<name>.c for each function. Those files are drafts for people and agents: Ghidra's types
are turned into the project's (u32, s16...), but the code rarely compiles as it is and never matches by itself.
The workbench, the C editor and Qwen show it when m2c gave nothing, and Qwen shows it next to the m2c draft.
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
import project  # noqa: E402

OUT = ROOT / "build" / "ghidra"
PROJECT_DIR = OUT / "project"
SCRIPTS = OUT / "scripts"
ARM9_BIN = project.EXTRACT / "arm9" / "arm9.bin"

SCRIPT = r'''//Applies dsd's symbols.txt and writes the decompiled C of the functions listed in a file.
//@category DsDecompStudio
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.lang.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.mem.*;
import ghidra.program.model.data.*;
import java.math.BigInteger;
import java.nio.file.*;
import java.util.*;
import java.util.regex.*;

public class DsDraft extends GhidraScript {
    public void run() throws Exception {
        String[] a = getScriptArgs();
        List<String> lines = Files.readAllLines(Paths.get(a[0]));
        Path out = Paths.get(a[1]);
        List<String> wanted = Files.readAllLines(Paths.get(a[2]));
        AddressSpace space = currentProgram.getAddressFactory().getDefaultAddressSpace();
        FunctionManager fm = currentProgram.getFunctionManager();
        Register tmode = currentProgram.getRegister("TMode");
        // Code and constants (everything before .data) read-only: the decompiler then reads literal pool words as
        // the addresses they hold (data_02106a40 instead of *(int *)0x02000f28)
        Memory memory = currentProgram.getMemory();
        Address dataStart = space.getAddress(Long.parseLong(a[3], 16));
        MemoryBlock b = memory.getBlock(dataStart);
        if (b != null && !b.getStart().equals(dataStart)) memory.split(b, dataStart);
        MemoryBlock code = memory.getBlock(space.getAddress(0x02000000L));
        if (code != null && code.isWrite()) code.setWrite(false);
        // .bss is not in arm9.bin: an uninitialized block, so pointers to it name their target
        long bssStart = Long.parseLong(a[5], 16), bssEnd = Long.parseLong(a[6], 16);
        Address bss = space.getAddress(bssStart);
        if (bssEnd > bssStart && !memory.contains(bss)) {
            memory.createUninitializedBlock(".bss", bss, bssEnd - bssStart, false);
        }
        Pattern p = Pattern.compile("^(\\S+) kind:(function|data|bss|label)(?:\\(([^)]*)\\))? addr:0x([0-9a-f]+)");
        Pattern size = Pattern.compile("size=0x([0-9a-f]+)");
        Map<String, Address> funcs = new HashMap<>();
        int made = 0;
        for (String line : lines) {
            Matcher m = p.matcher(line);
            if (!m.find()) continue;
            String name = m.group(1), kind = m.group(2), extra = m.group(3) == null ? "" : m.group(3);
            Address ad = space.getAddress(Long.parseLong(m.group(4), 16));
            if (!currentProgram.getMemory().contains(ad)) continue;
            if (kind.equals("function")) {
                funcs.put(name, ad);
                Function f = fm.getFunctionAt(ad);
                if (f != null) {
                    if (!f.getName().equals(name)) f.setName(name, SourceType.USER_DEFINED);
                    continue;
                }
                Matcher s = size.matcher(extra);
                long n = s.find() ? Long.parseLong(s.group(1), 16) : 4;
                if (extra.startsWith("thumb") && tmode != null) {
                    currentProgram.getProgramContext().setValue(tmode, ad, ad.add(Math.max(1, n) - 1), BigInteger.ONE);
                }
                disassemble(ad);
                try { createFunction(ad, name); made++; } catch (Exception e) { }
            } else if (!kind.equals("label")) {
                try { createLabel(ad, name, true, SourceType.USER_DEFINED); } catch (Exception e) { }
            }
        }
        println("DsDraft: " + made + " functions created");
        // Words dsd found to be addresses (relocs.txt kind:load) become pointers: the decompiler then names what
        // they point at (&data_02106a40) instead of showing a number
        int ptrs = 0;
        Pattern rp = Pattern.compile("^from:0x([0-9a-f]+) kind:load to:0x([0-9a-f]+) module:main");
        for (String line : Files.readAllLines(Paths.get(a[4]))) {
            Matcher m = rp.matcher(line);
            if (!m.find()) continue;
            Address from = space.getAddress(Long.parseLong(m.group(1), 16));
            if (!memory.contains(from) || currentProgram.getListing().getInstructionContaining(from) != null) continue;
            Data d = currentProgram.getListing().getDataAt(from);
            if (d == null || !d.isPointer()) {
                try { d = createData(from, PointerDataType.dataType); ptrs++; } catch (Exception e) { continue; }
            }
            // a literal pool word never changes: constant, so the decompiler uses its value
            if (MutabilitySettingsDefinition.DEF.getChoice(d) != MutabilitySettingsDefinition.CONSTANT)
                MutabilitySettingsDefinition.DEF.setChoice(d, MutabilitySettingsDefinition.CONSTANT);
        }
        println("DsDraft: " + ptrs + " pointers typed");
        DecompInterface di = new DecompInterface();
        di.openProgram(currentProgram);
        int ok = 0;
        for (String name : wanted) {
            name = name.trim();
            Address ad = funcs.get(name);
            if (name.isEmpty() || ad == null) continue;
            Function f = fm.getFunctionAt(ad);
            if (f == null) continue;
            DecompileResults r = di.decompileFunction(f, 60, monitor);
            if (r != null && r.decompileCompleted() && r.getDecompiledFunction() != null) {
                Files.writeString(out.resolve(name + ".c"), r.getDecompiledFunction().getC());
                ok++;
            }
        }
        di.dispose();
        println("DsDraft: " + ok + " functions decompiled");
    }
}
'''

TYPES = [  # Ghidra's names -> the project's (m2c.h)
    (r"\bundefined8\b", "u64"), (r"\bundefined4\b", "u32"), (r"\bundefined2\b", "u16"), (r"\bundefined1\b", "u8"),
    (r"\bundefined\b", "u8"), (r"\bulonglong\b", "u64"), (r"\blonglong\b", "s64"), (r"\buint\b", "u32"),
    (r"\bushort\b", "u16"), (r"\bbyte\b", "u8"), (r"\bsbyte\b", "s8"), (r"\bdword\b", "u32"), (r"\bword\b", "u16"),
    (r"\bcode\s*\*", "void *"),
]


def data_start() -> int:
    """Start of .data in the main module (delinks.txt header): what comes before is code and constants."""
    head = project.DELINKS.read_text(encoding="utf-8").split("\n\n", 1)[0]
    m = re.search(r"^\s+\.data\s+start:0x([0-9a-f]+)", head, re.M)
    return int(m.group(1), 16) if m else 0x02000000 + ARM9_BIN.stat().st_size


def bss_range() -> tuple[int, int]:
    head = project.DELINKS.read_text(encoding="utf-8").split("\n\n", 1)[0]
    m = re.search(r"^\s+\.bss\s+start:0x([0-9a-f]+) end:0x([0-9a-f]+)", head, re.M)
    return (int(m.group(1), 16), int(m.group(2), 16)) if m else (0, 0)


def ghidra_home() -> Path | None:
    for d in [os.environ.get("GHIDRA_HOME", "")] + os.environ.get("PATH", "").split(os.pathsep):
        if d and (Path(d) / "support" / "analyzeHeadless.bat").exists():
            return Path(d)
    tools = ROOT.parent.parent / "tools"
    for d in sorted(tools.glob("ghidra_*"), reverse=True):
        if (d / "support" / "analyzeHeadless.bat").exists():
            return d
    return None


_POOL = None


def pool_targets() -> dict[int, str]:
    """{literal pool word: name of what it points at} (relocs.txt kind:load + symbols.txt)."""
    global _POOL
    if _POOL is None:
        names = {}
        for m in re.finditer(r"^(\S+) kind:\w+(?:\([^)]*\))? addr:0x([0-9a-f]+)",
                             project.SYMBOLS.read_text(encoding="utf-8", errors="replace"), re.M):
            names.setdefault(int(m.group(2), 16), m.group(1))
        _POOL = {}
        relocs = project.SYMBOLS.parent / "relocs.txt"
        if relocs.exists():
            for m in re.finditer(r"^from:0x([0-9a-f]+) kind:load to:0x([0-9a-f]+) module:main",
                                 relocs.read_text(encoding="utf-8"), re.M):
                to = int(m.group(2), 16)
                if to in names:
                    _POOL[int(m.group(1), 16)] = names[to]
    return _POOL


def resolve_pool(c: str) -> str:
    """Ghidra reads a literal pool word as a variable (PTR_data_02000f28, _UNK_02000f28, iRam02000f28): the word
    holds an address, written here as what it points at (&data_02106a40)."""
    pool = pool_targets()

    def rep(m):
        target = pool.get(int(m.group(1), 16))
        return f"&{target}" if target else m.group(0)
    return re.sub(r"\b(?:PTR_\w*?_|_UNK_|[a-z]+Ram)([0-9a-f]{8})\b", rep, c)


def tidy(c: str, name: str) -> str:
    c = resolve_pool(c)
    for pat, rep in TYPES:
        c = re.sub(pat, rep, c)
    return (f"/* {name}: Ghidra draft (types translated, rarely compiles as is, never matches by itself: a reading of\n"
            f"   the code to start from, next to m2c's) */\n#include \"m2c.h\"\n\n" + c.strip() + "\n")


def usable_m2c(name: str) -> bool:
    for p in (ROOT / "build" / "auto" / "near" / f"{name}.c", ROOT / "build" / "drafts" / f"{name}.c"):
        if p.exists() and "m2c failed" not in p.read_text(encoding="utf-8", errors="replace")[:300]:
            return True
    return False


def candidates(all_unmatched: bool) -> list[str]:
    import auto_match as am
    out = []
    for name, _size, _addr in am.candidates():  # ARM, main module, not in a source file
        if all_unmatched or not usable_m2c(name):
            out.append(name)
    return out


def run(names: list[str], log=print) -> int:
    home = ghidra_home()
    if home is None:
        raise SystemExit("Ghidra not found (GHIDRA_HOME, PATH or decomp ds/tools/ghidra_*)")
    OUT.mkdir(parents=True, exist_ok=True)
    SCRIPTS.mkdir(parents=True, exist_ok=True)
    PROJECT_DIR.mkdir(parents=True, exist_ok=True)
    (SCRIPTS / "DsDraft.java").write_text(SCRIPT, encoding="utf-8")
    raw = OUT / "raw"
    shutil.rmtree(raw, ignore_errors=True)
    raw.mkdir()
    wanted = OUT / "wanted.txt"
    wanted.write_text("\n".join(names) + "\n", encoding="utf-8")
    exists = any(PROJECT_DIR.glob("ds.gpr"))
    head = [str(home / "support" / "analyzeHeadless.bat"), str(PROJECT_DIR), "ds"]
    if exists:
        head += ["-process", "arm9.bin"]
    else:
        head += ["-import", str(ARM9_BIN), "-loader", "BinaryLoader", "-loader-baseAddr", "0x02000000",
                 "-processor", "ARM:LE:32:v5t"]
    cmd = head + ["-noanalysis", "-scriptPath", str(SCRIPTS), "-postScript", "DsDraft.java",
                  str(project.SYMBOLS), str(raw), str(wanted), f"{data_start():x}",
                  str(project.SYMBOLS.parent / "relocs.txt"), *(f"{x:x}" for x in bss_range())]
    log(f"Ghidra ({home.name}): {len(names)} function(s){'' if exists else ', first import of the game'}...")
    r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True, encoding="utf-8", errors="replace",
                       stdin=subprocess.DEVNULL)
    for line in (r.stdout + r.stderr).splitlines():
        if "DsDraft:" in line or "ERROR" in line:
            log("  " + line.split("INFO", 1)[-1].strip())
    n = 0
    for f in raw.glob("*.c"):
        (OUT / f.name).write_text(tidy(f.read_text(encoding="utf-8", errors="replace"), f.stem), encoding="utf-8",
                                  newline="\n")
        n += 1
    shutil.rmtree(raw, ignore_errors=True)
    if r.returncode != 0 and not n:
        log((r.stdout + r.stderr)[-3000:])
    return n


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--names", default="", help="comma separated functions (default: those without an m2c draft)")
    ap.add_argument("--all-unmatched", action="store_true", help="every function not matched yet")
    ap.add_argument("--max", type=int, default=0)
    ap.add_argument("--force", action="store_true", help="also functions that already have a Ghidra draft")
    a = ap.parse_args()
    names = [n.strip() for n in a.names.split(",") if n.strip()] or candidates(a.all_unmatched)
    if not a.force:
        names = [n for n in names if not (OUT / f"{n}.c").exists()]
    if a.max:
        names = names[:a.max]
    if not names:
        print("nothing to do (every function asked for already has a Ghidra draft: --force)")
        return
    n = run(names)
    print(f"{n} Ghidra draft(s) in build/ghidra/")


if __name__ == "__main__":
    main()
