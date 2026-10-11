#!/usr/bin/env python3
"""Automatic matching: m2c drafts that already compile to the original instructions are added to the project.

    python tools/auto_match.py                       # scan every function that is not in a source file yet
    python tools/auto_match.py --permute 20 --minutes 5   # also run the permuter on 20 near misses

For every ARM function of the main module that is not covered by delinks.txt:
  1. m2c generates a draft (`--valid-syntax`, types from include/m2c.h);
  2. the draft is compiled with the project's compiler and flags;
  3. if the instructions are identical, the function is written to src/auto/<name>.c and declared `complete`
     in delinks.txt; drafts of the same size that differ in a few instructions are kept in
     build/auto/near/ (permuter candidates).
Finally `tools/match.py verify` runs; if it fails, every change made by this run is rolled back.

src/auto/ holds raw m2c code: it matches, but it is not clean. When a real source file (e.g. StdGame.c) is
created over the same addresses, move the functions into it and delete their src/auto entries.
"""

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
from multiprocessing import Pool
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import probe_compiler as pc  # noqa: E402

DELINKS = ROOT / "config" / "usa" / "arm9" / "delinks.txt"
SYMBOLS = ROOT / "config" / "usa" / "arm9" / "symbols.txt"
ASM_DIR = ROOT / "build" / "usa" / "asm"
AUTO_SRC = ROOT / "src" / "auto"
WORK = ROOT / "build" / "auto"
M2C = Path(os.environ.get("M2C_PATH", ROOT / "tools" / "m2c")) / "m2c.py"
MWCC_ROOT = Path(os.environ.get("MWCCARM", ROOT / "tools" / "mwccarm"))
# Main compiler first, then the one used for some libraries (see docs/compiler.md)
# (version, extra flags): profiles found in this game, most common first (see docs/compiler.md)
COMPILERS = [("2.0/sp1p5", ""), ("1.2/sp2p3", ""), ("1.2/sp2p3", "-proc arm7tdmi")]
MWCC = MWCC_ROOT / COMPILERS[0][0] / "mwccarm.exe"
COMPILERS_TXT = ROOT / "config" / "usa" / "compilers.txt"
MARKER = "/* compiler: "
MAIN_TEXT = (0x02000000, 0x02118edc)
CONTEXT = ROOT / "build" / "auto" / "m2c_context.c"


def header(name: str) -> str:
    # m2c_protos.h declares every known function except the one defined in this file
    return f'#define M2C_SELF_{name}\n#include "m2c_protos.h"\n\n'


def covered_ranges() -> list[tuple[int, int]]:
    files = DELINKS.read_text().split("\n\n", 1)[1] if "\n\n" in DELINKS.read_text() else ""
    return [(int(a, 16), int(b, 16)) for a, b in re.findall(r"\.text\s+start:0x([0-9a-f]+) end:0x([0-9a-f]+)", files)]


def candidates() -> list[tuple[str, int, int]]:
    taken = covered_ranges()
    out = []
    for line in SYMBOLS.read_text().splitlines():
        m = re.match(r"(\S+) kind:function\(arm,size=0x([0-9a-f]+)\) addr:0x([0-9a-f]+)", line)
        if not m:
            continue
        name, size, addr = m.group(1), int(m.group(2), 16), int(m.group(3), 16)
        if MAIN_TEXT[0] <= addr < MAIN_TEXT[1] and not any(a <= addr < b for a, b in taken):
            out.append((name, size, addr))
    return out


_ASM = None


def function_asm(name: str) -> str | None:
    global _ASM
    if _ASM is None:
        _ASM = "\n".join(f.read_text(encoding="utf-8") for f in ASM_DIR.glob("*.s"))
    m = re.search(rf"^{re.escape(name)}: .*?^\s+arm_func_end {re.escape(name)}$", _ASM, re.S | re.M)
    return m.group(0) if m else None


def restore_leading_args(source: str, name: str) -> str:
    """m2c drops parameters that the function never reads, but names the others after their register
    (`arg1` = r1). Put the missing ones back so that the remaining arguments land in the right registers."""
    m = re.search(rf"^(.*\b{re.escape(name)}\()([^)]*)(\) \{{)$", source, re.M)
    if not m or m.group(2).strip() in ("", "void"):
        return source
    params = [p.strip() for p in m.group(2).split(",")]
    by_index = {}
    for p in params:
        idx = re.search(r"\barg(\d+)$", p)
        if idx is None:
            return source  # unexpected form (e.g. stack arguments): leave untouched
        by_index[int(idx.group(1))] = p
    fixed = [by_index.get(i, f"s32 arg{i}") for i in range(max(by_index) + 1)]
    return source[:m.start(2)] + ", ".join(fixed) + source[m.end(2):]


def fix_byte_offsets(source: str) -> str:
    """m2c writes `&data_X + (i * 16)` meaning a byte offset, but `data_X` is an `M2C_UNK` (4 bytes), so C scales
    the offset a second time. Make the addition explicit in bytes."""
    unk = set(re.findall(r"^extern M2C_UNK (\w+);", source, re.M))
    if not unk:
        return source

    def repl(m: re.Match) -> str:
        if m.group(1) not in unk:
            return m.group(0)
        return f"(M2C_UNK *)((s8 *)&{m.group(1)} + ({m.group(2)}))"

    # The offset may contain one level of parentheses, e.g. `((arg0 >> 0xC) * 4)`
    return re.sub(r"&(\w+) \+ \(((?:[^()]|\([^()]*\))*)\)", repl, source)


# Instructions the compiler never generates: functions using them were written in assembly
ASM_ONLY = re.compile(r"^\s+(swpb?|mrs|msr|mcr|mrc|ldc|stc|cdp)\b", re.M)


def asm_function(name: str, asm: str) -> str | None:
    """Rewrites a straight-line function (no labels, no literal pool) that uses assembly-only instructions
    as a CodeWarrior `asm` function. Returns None when the function does not qualify."""
    body = [line.split(";")[0].rstrip() for line in asm.splitlines()[1:-1]]
    body = [line for line in body if line.strip()]
    if not ASM_ONLY.search(asm) or any(".L_" in line or ".word" in line or line.endswith(":") for line in body):
        return None
    # The clang-format guards keep the formatter from joining the instructions on one line
    return (f"/* Uses instructions the compiler never generates: written in assembly. */\n"
            f"// clang-format off\nasm void {name}(void) {{\n" + "\n".join(body) + "\n}\n// clang-format on\n")


COPROC = re.compile(r"^(\s*)(mcr2?|mrc2?|cdp2?|ldc2?l?|stc2?l?)\b(.*)$")


def asm_function_general(name: str, asm: str) -> str | None:
    """Like asm_function, for assembly-only functions with local labels and a literal pool: the pool words
    become `ldr rX, =value` (the compiler rebuilds the pool) and `.L_xxx` labels become plain labels."""
    lines = [line.split(";")[0].rstrip() for line in asm.splitlines()[1:-1]]
    lines = [line for line in lines if line.strip()]
    pool = {}
    body = []
    for line in lines:
        m = re.match(r"^\.L_(\w+): \.word (.+)$", line)
        if m:
            pool[m.group(1)] = m.group(2).strip()
        elif re.match(r"^\s*\.(?!L_)", line) or ".word" in line:
            return None  # other directives (jump tables, data in code...)
        else:
            body.append(line)
    if not ASM_ONLY.search(asm) or not body:
        return None
    out, calls, data = [], set(), set()
    for line in body:
        m = re.match(r"^\.L_(\w+):$", line)
        if m:
            out.append(f"L_{m.group(1)}:")
            continue
        # mwcc's assembler only knows the stack-addressing-mode spellings
        line = re.sub(r"^(\s*)push(\w{0,2})\s+", r"\1stm\2fd sp!, ", line)
        line = re.sub(r"^(\s*)pop(\w{0,2})\s+", r"\1ldm\2fd sp!, ", line)
        line = re.sub(r"^(\s*)ldm(\w{0,2})db\b", r"\1ldm\2ea", line)
        line = re.sub(r"^(\s*)stm(\w{0,2})db\b", r"\1stm\2fd", line)
        line = re.sub(r"^(\s*)(ldm|stm)(eq|ne|cs|hs|cc|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?\s+", r"\1\2\3ia ", line)
        line = re.sub(r"^(\s*)(lsl|lsr|asr|ror)(s?)(eq|ne|cs|hs|cc|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?\s+(\w+),\s*(\w+),\s*(.+)$",
                      lambda m: f"{m.group(1)}mov{m.group(4) or ''}{m.group(3)} {m.group(5)}, {m.group(6)}, "
                                f"{m.group(2)} {m.group(7)}", line)
        c = COPROC.match(line)
        if c:
            line = c.group(1) + c.group(2) + c.group(3).replace("#", "")
        m = re.match(r"^(\s*ldr\w*\s+\w+,\s*)\.L_(\w+)$", line)
        if m and m.group(2) in pool:
            value = pool[m.group(2)]
            out.append(f"{m.group(1)}={value}")
            data.update(re.findall(r"[A-Za-z_]\w*", re.sub(r"0x[0-9a-fA-F]+", "", value)))
            continue
        m = re.match(r"^(\s*b\w*\s+)(\w+)$", line)  # b / bl / bx lr / conditional forms
        if m and not re.match(r"^\s*bx", line) and m.group(2) not in ("lr",):
            calls.add(m.group(2))
        line = re.sub(r"\.L_(\w+)", r"L_\1", line)
        out.append(line)
    calls = {c for c in calls if not c.startswith("L_")}
    decls = "".join(f"extern void {c}();\n" for c in sorted(calls))
    decls += "".join(f"extern char {d}[];\n" for d in sorted(data - calls - {name}))
    return (f"/* Uses instructions the compiler never generates: written in assembly. */\n{decls}"
            f"// clang-format off\nasm void {name}(void) {{\n" + "\n".join(out) + "\n}\n// clang-format on\n")


def try_function(f: tuple[str, int, int]) -> tuple[str, int, int, str, str]:
    """Tries every compiler; a match with a non-default compiler is tagged with a marker comment."""
    first = None
    for version, extra in COMPILERS:
        result = try_function_with(f, MWCC_ROOT / version / "mwccarm.exe", extra)
        if result[3] == "match":
            if (version, extra) != COMPILERS[0]:
                result = result[:4] + (f"{MARKER}{version} {extra} */\n" + result[4],)
            return result
        first = first or result
    return first


def try_function_with(f: tuple[str, int, int], mwcc: Path, extra: str = "") -> tuple[str, int, int, str, str]:
    """Returns (name, size, addr, status, source). Status: match, near, size, compile, m2c."""
    name, size, addr = f
    asm = function_asm(name)
    if asm is None:
        return name, size, addr, "m2c", ""
    with tempfile.TemporaryDirectory() as tmp:
        t = Path(tmp)
        if ASM_ONLY.search(asm):
            # m2c cannot express these instructions: go straight to an assembly-language rewrite
            source = asm_function(name, asm) or asm_function_general(name, asm)
            if source:
                status = compile_and_compare(t, '#include "m2c.h"\n\n' + source, name, size, addr, mwcc, extra)
                if status == "match":
                    return name, size, addr, status, '#include "m2c.h"\n\n' + source
        (t / "f.s").write_text(asm + "\n")
        m2c = [sys.executable, str(M2C), "-t", "arm-mwcc-c", "--valid-syntax", str(t / "f.s")]
        # With the context first, then without it: guessed signatures help most drafts but can also make m2c
        # fail or produce calls that do not compile. Without context, only plain m2c.h types are used (m2c's own
        # extern declarations would conflict with m2c_protos.h).
        best = (name, size, addr, "m2c", "")
        for cmd, head in ((m2c[:-1] + ["--context", str(CONTEXT), m2c[-1]], header(name)),
                          (m2c, '#include "m2c.h"\n\n')):
            result = evaluate(t, subprocess.run(cmd, capture_output=True, text=True), head, asm, f, mwcc, extra)
            if RANK[result[3]] > RANK[best[3]]:
                best = result
            if best[3] == "match":
                break
        return best


RANK = {"m2c": 0, "compile": 1, "size": 2, "near": 3, "match": 4}


def evaluate(t: Path, r: subprocess.CompletedProcess, head: str, asm: str, f: tuple[str, int, int], mwcc: Path,
             extra: str) -> tuple[str, int, int, str, str]:
    name, size, addr = f
    if r.returncode != 0:
        return name, size, addr, "m2c", ""
    if "M2C_ERROR" in r.stdout:
        source = asm_function(name, asm)
        if source is None:
            return name, size, addr, "m2c", r.stdout
    else:
        source = head + fix_byte_offsets(restore_leading_args(r.stdout, name))
    status = compile_and_compare(t, source, name, size, addr, mwcc, extra)
    if status == "compile":
        fixed = compile_fixes(source)
        if fixed != source:
            fixed_status = compile_and_compare(t, fixed, name, size, addr, mwcc, extra)
            if fixed_status != "compile":
                source, status = fixed, fixed_status
                if status == "match":
                    return name, size, addr, status, source
    if status in ("near", "size"):
        # Close but not exact: try the known m2c corrections one by one
        for variant in variants(source, name):
            if compile_and_compare(t, variant, name, size, addr, mwcc, extra) == "match":
                return name, size, addr, "match", variant
    return name, size, addr, status, source


def compile_fixes(source: str) -> str:
    """Repairs m2c output that the compiler rejects (docs/automation.md)."""
    s = source
    # Callees declared with a parameter list but called with fewer arguments: use old-style declarations
    s = re.sub(r"^(.*?\b\w+)\([^()]*\);(\s*/\* extern \*/)$", r"\1();\2", s, flags=re.M)
    # `*(void *)0x04000060 = ...` is not valid C
    s = s.replace("*(void *)", "*(M2C_UNK *)")
    # Dereference of a variable that m2c typed as an integer: `*var_r1 = arg0;`
    integers = set(re.findall(r"\b(?:s8|u8|s16|u16|s32|u32|M2C_UNK) (\w+)(?=[;,)])", s))
    s = re.sub(r"(?<![\w)\]])\*(\w+)\b",
               lambda m: f"*(M2C_UNK *){m.group(1)}" if m.group(1) in integers else m.group(0), s)
    # Stack slots m2c refers to without declaring them (sp10, saved_reg_r4...): declare them as locals
    declared = set(re.findall(r"\b(?:s8|u8|s16|u16|s32|u32|M2C_UNK|void \*) \*?(\w+)(?=[;,)\[])", s))
    used = sorted(set(re.findall(r"\b(sp[0-9A-F]+|saved_reg_r\d+|unksp[0-9A-F]+)\b", s)) - declared)
    if used:
        decls = "".join(f"\n    M2C_UNK {u};" for u in used)
        s = re.sub(r"^(\S.*\) \{)$", lambda m: m.group(1) + decls, s, count=1, flags=re.M)
    return s


def compile_and_compare(t: Path, source: str, name: str, size: int, addr: int, mwcc: Path = MWCC,
                        extra: str = "") -> str:
    (t / "f.o").unlink(missing_ok=True)
    (t / "f.c").write_text(source)
    cmd = f'"{mwcc}" -O4,p {pc.BASE_FLAGS} {extra} -i "{ROOT / "include"}" -c f.c -o f.o'
    r = subprocess.run(cmd, shell=True, cwd=t, capture_output=True, text=True)
    if r.returncode != 0 or not (t / "f.o").exists():
        return "compile"
    cand = pc.compiled_function(t / "f.o", name)
    if cand is None:
        return "compile"
    bad, _ = pc.compare(pc.target_bytes(addr, size), cand)
    if bad == 0:
        return "match"
    return "near" if len(cand) == size else "size"


def variants(source: str, name: str) -> list[str]:
    """Rewrites of a near-miss draft for m2c mistakes seen in this game (docs/automation.md)."""
    out = []
    # 1. The function returns the value it just stored (m2c typed it void): `return x = v;`
    m = re.search(rf"^void ({re.escape(name)}\(.*\) \{{)$", source, re.M)
    last = re.search(r"^    ([^;\n]+?) (=|\+=|-=|\|=|&=) ([^;\n]+);\n\}", source, re.M)
    if m and last and last.start() > m.start():
        returned = source[:last.start()] + f"    return {last.group(1)} {last.group(2)} {last.group(3)};\n}}" + \
            source[last.end():]
        out.append(returned.replace(f"void {m.group(1)}", f"s32 {m.group(1)}", 1))
    # 2. Pointer + constant meant in bytes (m2c scales it by the pointee size)
    ptrs = set(re.findall(r"\b\w+ \*(arg\d+)\b", source))
    bytes_ = re.sub(r"\b(arg\d+) \+ (0x[0-9A-Fa-f]+|\d+)\b",
                    lambda mm: f"((s8 *){mm.group(1)} + {mm.group(2)})" if mm.group(1) in ptrs else mm.group(0), source)
    bytes_ = re.sub(r"\(M2C_UNK \*\)\(\(s8 \*\)&(\w+) \+ \(([^()]*)\)\) \+ (0x[0-9A-Fa-f]+|\d+)",
                    r"(void *)((s8 *)&\1 + (\2) + \3)", bytes_)
    if bytes_ != source:
        out.append(bytes_)
    # 3. Table at a fixed address: M2C_FIELD(((i * 4) + BASE), s32 *, OFF) -> ((s32 *)(BASE + OFF))[i]
    table = re.sub(r"M2C_FIELD\(\(\((\w+) \* 4\) \+ (0x[0-9A-Fa-f]+)\), (\w+) \*, (0x[0-9A-Fa-f]+|\d+)\)",
                   r"((\3 *)(\2 + \4))[\1]", source)
    if table != source:
        out.append(table)
    # 5. Fields of volatile structures (hardware-like objects are re-read after every access)
    vol = re.sub(r"M2C_FIELD\(([^,]+), (\w+) \*, ", r"M2C_FIELD(\1, volatile \2 *, ", source)
    if vol != source:
        out.append(vol)
    # 6. Interrupt guards: the state returned by OS_Disable*/OS_EnableIrq is passed to OS_Restore*
    for base in [source] + ([vol] if vol != source else []):
        guarded = irq_guard(base, name)
        if guarded:
            out.append(guarded)
    # 4. Arguments forwarded to callees: m2c declares callees without parameters (`func()`), so the compiler
    #    reuses r0-r3; in the game the function passes its own first k arguments through.
    for k in range(1, 5):
        forwarded = forward_args(source, name, k)
        if forwarded:
            out.append(forwarded)
    return out


IRQ_GUARDS = {"OS_DisableIrq": "OS_RestoreIrq", "OS_EnableIrq": "OS_RestoreIrq",
              "OS_DisableInterrupts": "OS_RestoreInterrupts"}


def irq_guard(source: str, name: str) -> str | None:
    m = re.search(rf"^.*\b{re.escape(name)}\(.*\) \{{$", source, re.M)
    if not m:
        return None
    for get, restore in IRQ_GUARDS.items():
        if f"    {get}();" in source and f"{restore}();" in source:
            body = source[m.end():]
            body = body.replace(f"    {get}();", f"    m2c_irq = {get}();", 1)
            body = re.sub(rf"\b{restore}\(\);", f"{restore}(m2c_irq);", body)
            return source[:m.end()] + "\n    M2C_UNK m2c_irq;" + body
    return None


def forward_args(source: str, name: str, k: int) -> str | None:
    m = re.search(rf"^(.*\b{re.escape(name)}\()([^)]*)(\) \{{)$", source, re.M)
    if not m or not re.search(r"^    .*\(\);", source[m.end():], re.M):
        return None
    params = [p.strip() for p in m.group(2).split(",") if p.strip() not in ("", "void")]
    names = []
    for i in range(k):
        if i < len(params):
            mm = re.search(r"(\w+)$", params[i])
            names.append(mm.group(1))
        else:
            params.append(f"s32 arg{i}")
            names.append(f"arg{i}")
    head = source[:m.start(2)] + ", ".join(params) + source[m.end(2):m.end()]
    body = re.sub(r"^(    .*)\(\);", lambda mm: f"{mm.group(1)}({', '.join(names)});", source[m.end():], flags=re.M)
    return head + body


def load_protos() -> dict[str, str]:
    protos = {}
    path = ROOT / "include" / "m2c_protos.h"
    if path.exists():
        for line in path.read_text(encoding="utf-8").splitlines():
            m = re.match(r"^[^#/].*?\b(\w+)\(.*\);$", line)
            if m:
                protos[m.group(1)] = line
    return protos


def freeze(source: str, name: str, protos: dict[str, str]) -> str:
    """Replaces `#include "m2c_protos.h"` by a copy of the prototypes the function uses, so that the file
    keeps compiling the same way when m2c_protos.h is regenerated (guessed signatures get replaced)."""
    head = f'#define M2C_SELF_{name}\n#include "m2c_protos.h"\n'
    if head not in source:
        return source
    marker = ""
    if source.startswith(MARKER):  # the compiler marker must stay on the first line (read by integrate)
        marker, source = source.split("\n", 1)
        marker += "\n"
    body = source.replace(head, "", 1).lstrip("\n")
    # Every known function the code names: called, or only taken by address (e.g. a callback)
    # Top-level declarations start at column 0; calls inside the function are indented
    declared = set(re.findall(r"^[^\s#/].*?\b(\w+)\([^()]*\);", body, re.M))
    used = sorted({c for c in re.findall(r"\b(\w+)\b", body) if c in protos and c != name and c not in declared})
    decls = "".join(protos[c] + "\n" for c in used)
    return marker + '#include "m2c.h"\n#include "engine.h"\n\n' + decls + ("\n" if decls else "") + body


def integrate(found: list[tuple[str, int, int, str]]) -> list[Path]:
    AUTO_SRC.mkdir(parents=True, exist_ok=True)
    created = []
    entries = []
    protos = load_protos()
    for name, size, addr, source in sorted(found, key=lambda x: x[2]):
        path = AUTO_SRC / f"{name}.c"
        path.write_text(freeze(source, name, protos), encoding="utf-8", newline="\n")
        created.append(path)
        entries.append(f"\nsrc/auto/{name}.c:\n    complete\n    .text       start:0x{addr:08x} end:0x{addr + size:08x}\n")
    with DELINKS.open("a", newline="\n") as f:
        f.writelines(entries)
    # Files matched with another compiler are recorded in compilers.txt (read by tools/configure.py)
    overrides = []
    for path in created:
        first_line = path.read_text(encoding="utf-8").split("\n", 1)[0]
        if first_line.startswith(MARKER):
            profile = first_line[len(MARKER):].split("*/")[0].strip()
            overrides.append(f"{path.relative_to(ROOT).as_posix()} {profile}\n")
    if overrides:
        with COMPILERS_TXT.open("a", newline="\n") as f:
            f.writelines(overrides)
    return created


def permute_near(near: list[tuple[str, int, int, str]], count: int, minutes: float) -> list[tuple[str, int, int, str]]:
    """Runs the permuter on the smallest near misses; returns the ones that reached a match."""
    won = []
    for name, size, addr, source in sorted(near, key=lambda x: x[1])[:count]:
        src = WORK / "near" / f"{name}.c"
        r = subprocess.run([sys.executable, str(ROOT / "tools" / "permute.py"), name, "--source", str(src),
                            "--minutes", str(minutes)], cwd=ROOT, capture_output=True, text=True)
        best = sorted((ROOT / "build" / "permuter" / name).glob("output-0-*"))
        print(f"  {name}: {'MATCH' if best else 'no match'}")
        if best:
            # The permuter output is preprocessed and self-contained
            won.append((name, size, addr, (best[0] / "source.c").read_text(encoding="utf-8")))
    return won


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("-j", type=int, default=os.cpu_count() or 4)
    ap.add_argument("--permute", type=int, default=0, metavar="N", help="Run the permuter on N near misses")
    ap.add_argument("--minutes", type=float, default=5.0, help="Permuter time per function")
    ap.add_argument("--dry-run", action="store_true", help="Only report, change nothing")
    args = ap.parse_args()

    if not M2C.exists():
        raise SystemExit(f"m2c not found at {M2C} (set M2C_PATH)")
    # dsd does not delete old files and gap file names change when delinks.txt changes
    shutil.rmtree(ASM_DIR, ignore_errors=True)
    subprocess.run(["ninja", "dis"], cwd=ROOT, check=True, capture_output=True)
    protos = ROOT / "include" / "m2c_protos.h"
    old_protos = protos.read_bytes() if protos.exists() else None
    subprocess.run([sys.executable, str(ROOT / "tools" / "gen_context.py")], cwd=ROOT, check=True)
    if old_protos is not None and protos.read_bytes() != old_protos:
        # Files already in src/ include this header: make sure they still build before going on
        check = subprocess.run([sys.executable, "tools/match.py", "verify"], cwd=ROOT, capture_output=True, text=True)
        if check.returncode != 0:
            print(check.stdout[-2000:])
            protos.write_bytes(old_protos)
            raise SystemExit("New m2c_protos.h breaks the build: restored the previous one, stopping.")

    todo = candidates()
    print(f"Trying {len(todo)} functions not yet in a source file...")
    with Pool(args.j) as pool:
        results = pool.map(try_function, todo, chunksize=8)

    stats = {}
    for r in results:
        stats[r[3]] = stats.get(r[3], 0) + 1
    print("Results: " + ", ".join(f"{k} {v}" for k, v in sorted(stats.items())))

    found = [(n, s, a, src) for n, s, a, st, src in results if st == "match"]
    near = [(n, s, a, src) for n, s, a, st, src in results if st == "near"]
    WORK.mkdir(parents=True, exist_ok=True)
    if (WORK / "near").exists():
        shutil.rmtree(WORK / "near")
    (WORK / "near").mkdir()
    for n, s, a, src in near:
        (WORK / "near" / f"{n}.c").write_text(src, encoding="utf-8")
    (WORK / "status.json").write_text(json.dumps([r[:4] for r in results]))
    print(f"{len(near)} near misses kept in {(WORK / 'near').relative_to(ROOT)}")

    if args.permute and near:
        print(f"Permuter on {min(args.permute, len(near))} near misses, {args.minutes} min each:")
        found += permute_near(near, args.permute, args.minutes)

    if args.dry_run or not found:
        print("Nothing added." if not found else f"{len(found)} matches (dry run, nothing added).")
        return

    backup = DELINKS.read_bytes()
    compilers_backup = COMPILERS_TXT.read_bytes() if COMPILERS_TXT.exists() else b""
    created = integrate(found)
    print(f"Added {len(created)} functions to src/auto/, verifying...")
    subprocess.run([sys.executable, "tools/configure.py", "usa"], cwd=ROOT, check=True, capture_output=True)
    verify = subprocess.run([sys.executable, "tools/match.py", "verify"], cwd=ROOT, capture_output=True, text=True)
    print(verify.stdout.strip().splitlines()[-1] if verify.stdout else "")
    if verify.returncode != 0:
        print(verify.stdout[-3000:])
        print("Verification failed: rolling back.")
        DELINKS.write_bytes(backup)
        COMPILERS_TXT.write_bytes(compilers_backup)
        for p in created:
            p.unlink()
        subprocess.run([sys.executable, "tools/configure.py", "usa"], cwd=ROOT, capture_output=True)
        sys.exit(1)
    print(f"OK: {len(created)} new matching functions.")


if __name__ == "__main__":
    main()
