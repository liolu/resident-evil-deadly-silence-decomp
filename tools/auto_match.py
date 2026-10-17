#!/usr/bin/env python3
"""Automatic matching: m2c drafts that already compile to the original instructions are added to the project.

    python tools/auto_match.py                       # scan every function that is not in a source file yet
    python tools/auto_match.py --permute 20 --minutes 5   # also run the permuter on 20 near misses
    python tools/auto_match.py --neighbours a,b      # retry only the callers and callees of a, b (just matched)
    python tools/auto_match.py --names a,b           # retry only these functions (cache ignored for them)

A function that just matched gives its real signature to the context (gen_context.py reads src/): its callers and
callees get better drafts, so `--neighbours` retries them even when the cache has a failure for them.

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
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
import time
from multiprocessing import Pool
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(Path(__file__).resolve().parent))
import project  # noqa: E402  (this game's version, ROM name, paths: tools/project.py)
sys.path.insert(0, str(ROOT / "tools"))
import probe_compiler as pc  # noqa: E402
from pipeline_lock import journal_begin, journal_created, journal_end  # noqa: E402

DELINKS = project.DELINKS
SYMBOLS = project.SYMBOLS
ASM_DIR = project.ASM_DIR
AUTO_SRC = ROOT / "src" / "auto"
WORK = ROOT / "build" / "auto"
M2C = Path(os.environ.get("M2C_PATH", ROOT / "tools" / "m2c")) / "m2c.py"
MWCC_ROOT = Path(os.environ.get("MWCCARM", ROOT / "tools" / "mwccarm"))
# Main compiler first, then the one used for some libraries (see docs/compiler.md)
# (version, extra flags): profiles found in this game, most common first (see docs/compiler.md)
COMPILERS = [("2.0/sp1p5", ""), ("1.2/sp2p3", ""), ("1.2/sp2p3", "-proc arm7tdmi")]
# Other mwccarm builds to try, e.g. AUTO_EXTRA_PROFILES="1.2/sp3,1.2/sp4" (Heroes of Mana: 1.2/sp3 builds code that ends in
# `pop {.., pc}` and keeps `sub sp` instead of the `push r3` pad, which 2.0 and 1.2/sp2p3 do not produce).
EXTRA_PROFILES = [(v.strip(), "") for v in os.environ.get("AUTO_EXTRA_PROFILES", "").split(",") if v.strip()]
COMPILERS += [c for c in EXTRA_PROFILES if c not in COMPILERS]
MWCC = MWCC_ROOT / COMPILERS[0][0] / "mwccarm.exe"
COMPILERS_TXT = project.COMPILERS_TXT
MARKER = "/* compiler: "
MAIN_TEXT = project.MAIN_TEXT
CONTEXT = ROOT / "build" / "auto" / "m2c_context.c"


FUNCTION_BUDGET = 45  # seconds spent on one function over all compilers/variants


def run_limited(cmd, cwd=None, shell=False, timeout=15):
    """subprocess.run with a time limit; the compiler sometimes loops forever on odd sources.
    On timeout the whole process tree is killed and a failed result is returned."""
    p = subprocess.Popen(cmd, shell=shell, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    try:
        out, err = p.communicate(timeout=timeout)
    except subprocess.TimeoutExpired:
        import psutil
        try:
            for c in psutil.Process(p.pid).children(recursive=True):
                c.kill()
            p.kill()
        except Exception:
            pass
        p.communicate()
        return subprocess.CompletedProcess(cmd, 1, "", "timeout")
    return subprocess.CompletedProcess(cmd, p.returncode, out, err)

AUTO_VERSION = hashlib.sha1(Path(__file__).read_bytes()).hexdigest()[:12]
CACHE = WORK / "cache.jsonl"
_M2C = {}


def m2c_cached(name, cmd):
    """m2c's output does not depend on the compiler: run it once per function and mode."""
    key = (name, "--context" in cmd)
    if key not in _M2C:
        _M2C[key] = run_limited(cmd)
    return _M2C[key]


def cache_key(f):
    return hashlib.sha1((function_asm(f[0]) or "").encode()).hexdigest()[:20] + f[0]


def load_cache():
    out = {}
    if CACHE.exists() and not os.environ.get("AUTO_FRESH"):
        for line in CACHE.read_text(encoding="utf-8", errors="replace").splitlines():
            try:
                d = json.loads(line)
                if d["r"][3] == "match" or d.get("v") == AUTO_VERSION:  # failures are redone when the tool changed
                    out[d["k"]] = tuple(d["r"])
            except Exception:
                pass  # a line cut by an interruption
    return out



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
    m = re.search(rf"^{re.escape(name)}: .*?^\s+(?:arm|thumb)_func_end {re.escape(name)}$", _ASM, re.S | re.M)
    return m.group(0) if m else None


def neighbours(names: set[str]) -> set[str]:
    """Functions calling or called by `names` (bl / b / blx to a symbol, from the disassembly)."""
    function_asm("")  # loads the disassembly
    out = set()
    for m in re.finditer(r"^(\w+): ; 0x[0-9a-f]+\n(.*?)^\s+(?:arm|thumb)_func_end \1$", _ASM, re.S | re.M):
        callees = set(re.findall(r"^\s+(?:blx|bl|b)(?:eq|ne|cs|hs|cc|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le)?\s+(\w+)\s*$",
                                 m.group(2), re.M))
        callees = {c for c in callees if not re.fullmatch(r"r\d+|lr|ip|sp|pc", c) and not c.startswith("_L")}
        if m.group(1) in names:
            out |= callees
        elif callees & names:
            out.add(m.group(1))
    return out - names


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
ASM_ONLY = re.compile(r"^\s+(swpb?|mrs|msr|mcr|mrc|ldc|stc|cdp|svc|swi)\b", re.M)


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


def code_style(addr: int, size: int) -> str:
    """Which compiler a compiled function comes from, judged on its epilogue (checked on the ~2,100 functions
    already matched: no function contradicts it, except hand-written assembly):
      v20    `ldmfd sp!, {..., pc}`            -> mwccarm 2.0
      v12    `ldmfd sp!, {..., lr}` + `bx lr`  -> mwccarm 1.2
      other  leaf functions (no stack frame) and anything else: any compiler."""
    data = pc.target_bytes(addr, size)
    words = struct.unpack(f"<{len(data) // 4}I", data[: len(data) // 4 * 4])
    pops = [w for w in words if (w & 0xFFFF0000) == 0xE8BD0000]  # ldmfd sp!, {...}
    pc_ret = any(w & 0x8000 for w in pops)
    lr_ret = any(w & 0x4000 and not w & 0x8000 for w in pops)
    if lr_ret and 0xE12FFF1E in words and not pc_ret:  # bx lr
        return "v12"
    if pc_ret and not lr_ret:
        return "v20"
    return "other"


def profiles_for(name: str, size: int, addr: int) -> list[tuple[str, str]]:
    """Compiler profiles worth trying for one function (all of them when in doubt; AUTO_ALL_PROFILES=1 forces that)."""
    if os.environ.get("AUTO_ALL_PROFILES") or ASM_ONLY.search(function_asm(name) or ""):
        return COMPILERS
    style = code_style(addr, size)
    if style == "v20":
        return [c for c in COMPILERS if c[0].startswith("2.") or c in EXTRA_PROFILES]
    if style == "v12":
        return [c for c in COMPILERS if c[0].startswith("1.") and c not in EXTRA_PROFILES or c in EXTRA_PROFILES]
    return COMPILERS


def try_function(f: tuple[str, int, int]) -> tuple[str, int, int, str, str]:
    """Tries every compiler; a match with a non-default compiler is tagged with a marker comment."""
    _M2C.clear()
    first = None
    t0 = time.time()
    for version, extra in profiles_for(*f):
        if first is not None and time.time() - t0 > FUNCTION_BUDGET:
            break
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
        attempts = [(m2c[:-1] + ["--context", str(CONTEXT), m2c[-1]], header(name)),
                    (m2c, '#include "m2c.h"\n\n')]
        if os.environ.get("AUTO_ORDER", "noctx_first") == "noctx_first":
            attempts.reverse()
        for cmd, head in attempts:
            result = evaluate(t, m2c_cached(name, cmd), head, asm, f, mwcc, extra)
            if RANK[result[3]] > RANK[best[3]]:
                best = result
            if best[3] == "match":
                break
            if os.environ.get("AUTO_MODE2") == "fallback" and RANK[best[3]] >= RANK["size"]:
                break  # compiled to something comparable: the second m2c mode rarely does better
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
    if status == "compile":
        # m2c typed an address as an integer: let the compiler say which line, and cast the operand
        fixed = fix_pointer_bases(t, source, mwcc, extra)
        if fixed is not None and fixed != source:
            fixed_status = compile_and_compare(t, fixed, name, size, addr, mwcc, extra)
            if fixed_status != "compile":
                source, status = fixed, fixed_status
                if status == "match":
                    return name, size, addr, status, source
    if status in ("near", "size"):
        # Close but not exact: try the known m2c corrections, all in one compiler call (the first match in the
        # order of the list wins, as when they were tried one by one)
        singles = variants(source, name)
        for variant, variant_status in zip(singles, compile_batch(t, singles, name, size, addr, mwcc, extra)):
            if variant_status == "match":
                return name, size, addr, "match", variant
    return name, size, addr, status, source


ERROR_LINE = re.compile(r"^#\s+(\d+):\s?(.*)$")
POINTER_CASTS = ("s8 *", "s32 *", "s16 *", "u8 *", "M2C_UNK *")


def compile_error(t: Path, source: str, mwcc: Path = MWCC, extra: str = "") -> tuple[int, str] | None:
    """(line number, message) of the first compiler error, or None when the source compiles."""
    (t / "f.o").unlink(missing_ok=True)
    (t / "f.c").write_text(source)
    cmd = f'"{mwcc}" -O4,p {pc.BASE_FLAGS} {extra} -i "{ROOT / "include"}" -c f.c -o f.o'
    r = run_limited(cmd, cwd=t, shell=True)
    if r.returncode == 0 and (t / "f.o").exists():
        return None
    lines = ((r.stdout or "") + (r.stderr or "")).splitlines()
    for i, line in enumerate(lines):
        if "Error:" in line:
            lineno = -1
            for j in range(i - 1, max(-1, i - 3), -1):
                match = ERROR_LINE.match(lines[j])
                if match:
                    lineno = int(match.group(1))
                    break
            return lineno, lines[i + 1].lstrip("# ").strip() if i + 1 < len(lines) else ""
    return -1, "unknown error"


def cast_operand(source: str, line_index: int, cast: str) -> str | None:
    """`*(E)` -> `*(cast)(E)` at the first dereference of that line that is not already cast."""
    lines = source.splitlines()
    if not (0 <= line_index < len(lines)):
        return None
    line = lines[line_index]
    for m in re.finditer(r"\*\(", line):
        if re.match(r"(?:[A-Za-z_]\w*\s*)*\*\)\(", line[m.end():]):  # already `*(type *)(`
            continue
        lines[line_index] = line[:m.start()] + f"*({cast})(" + line[m.end():]
        return "\n".join(lines)
    return None


def fix_pointer_bases(t: Path, source: str, mwcc: Path = MWCC, extra: str = "") -> str | None:
    """m2c computed an address in an integer (`temp_r3 = arg0 + 5; *(temp_r3 + arg1)`) so the draft does not
    compile. Casting the whole operand keeps the byte arithmetic; the compiler's error line says where.
    Returns a source that compiles, or None. 156 of the 295 compile failures start this way."""
    for _ in range(8):
        err = compile_error(t, source, mwcc, extra)
        if err is None:
            return source
        lineno, message = err
        if "pointer/array type was expected" not in message:
            return None
        for cast in POINTER_CASTS:
            fixed = cast_operand(source, lineno - 1, cast)
            if fixed is not None and fixed != source:
                source = fixed
                break
        else:
            return None
    return None


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
    r = run_limited(cmd, cwd=t, shell=True)
    if r.returncode != 0 or not (t / "f.o").exists():
        return "compile"
    cand = pc.compiled_function(t / "f.o", name)
    if cand is None:
        return "compile"
    bad, _ = pc.compare(pc.target_bytes(addr, size), cand)
    if bad == 0:
        return "match"
    return "near" if len(cand) == size else "size"


def compile_batch(t: Path, sources: list[str], name: str, size: int, addr: int, mwcc: Path = MWCC,
                  extra: str = "") -> list[str]:
    """Same result as `compile_and_compare` on each source, in far fewer compiler calls.

    The compiler spends about a second starting up and almost nothing per file, so all the sources go into one call
    (`-c v0.c v1.c ... -o objs`). When a file has an error the compiler stops there: that file is `compile`, and the
    files after it are compiled by the next call. Identical sources are compiled once."""
    if not sources:
        return []
    unique = list(dict.fromkeys(sources))
    work = t / "batch"
    shutil.rmtree(work, ignore_errors=True)
    (work / "objs").mkdir(parents=True)
    for i, s in enumerate(unique):
        (work / f"v{i}.c").write_text(s)
    target = pc.target_bytes(addr, size)
    result = {}
    pending = list(range(len(unique)))
    while pending:
        files = " ".join(f"v{i}.c" for i in pending)
        cmd = f'"{mwcc}" -O4,p {pc.BASE_FLAGS} {extra} -i "{ROOT / "include"}" -c {files} -o objs'
        r = run_limited(cmd, cwd=work, shell=True, timeout=15 + len(pending) // 2)
        if r.stderr == "timeout":
            # One source makes the compiler loop: find it by compiling the rest one at a time
            for i in pending:
                result[i] = compile_and_compare(t, unique[i], name, size, addr, mwcc, extra)
            break
        missing = []
        for i in pending:
            obj = work / "objs" / f"v{i}.o"
            if not obj.exists():
                missing.append(i)  # not compiled: error, or not reached because of an earlier error
                continue
            cand = pc.compiled_function(obj, name)
            if cand is None:
                result[i] = "compile"  # compiled, but the function is not in the object
                continue
            bad, _ = pc.compare(target, cand)
            result[i] = "match" if bad == 0 else ("near" if len(cand) == size else "size")
        if not missing:
            break
        result[missing[0]] = "compile"  # the compiler stopped on the first missing file
        pending = missing[1:]
    return [result.get(unique.index(s), "compile") for s in sources]


def diff_count(t: Path, name: str, size: int, addr: int, source: str, mwcc: Path = MWCC, extra: str = "") -> int:
    """Number of differing instructions of a draft (a large number when it does not compile or changes size)."""
    (t / "f.o").unlink(missing_ok=True)
    (t / "f.c").write_text(source)
    run_limited(f'"{mwcc}" -O4,p {pc.BASE_FLAGS} {extra} -i "{ROOT / "include"}" -c f.c -o f.o', cwd=t, shell=True)
    cand = pc.compiled_function(t / "f.o", name) if (t / "f.o").exists() else None
    if not cand or len(cand) != size:
        return 10**6
    return pc.compare(pc.target_bytes(addr, size), cand)[0]


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
    # 7. Stack buffers declared as scalars, byte offsets on globals (see stack_buffers / addr_plus_var)
    for base in [source] + ([vol] if vol != source else []):
        for fixed in (stack_buffers(base, name), addr_plus_var(base)):
            if fixed:
                out.append(fixed)
    # 4. Arguments forwarded to callees: m2c declares callees without parameters (`func()`), so the compiler
    #    reuses r0-r3; in the game the function passes its own first k arguments through.
    for k in range(1, 5):
        forwarded = forward_args(source, name, k)
        if forwarded:
            out.append(forwarded)
    # 8. Accumulated flags/sums: m2c folds `x = 0; if (c) x |= 0x10;` into `x = 0x10;`
    out += accumulate(source)
    # 9. Element type of tables at unknown globals: `*(&data_X + (i * 2))` -> `((s16 *)&data_X)[i]`
    out += typed_tables(source)
    # 10. Rotated `for` loops, local signedness, signed constants and byte offsets (see each function)
    out += rotated_loops(source)
    out += local_types(source)
    out += signed_constants(source)
    out += pointer_add_bytes(source)
    # 11. A wrapper only reads part of its arguments, so m2c declares fewer parameters than the game passes on
    out += forward_extra_arg(source, name)
    # 12. Load type of a global reached through `(M2C_UNK *)((s8 *)&data_X + n)`: byte and halfword loads
    out += typed_global_loads(source)
    # 13. Consecutive word copies are one struct assignment (`ldm`/`stm` in the game)
    out += struct_copy(source, name)
    # 14. Method calls through a table of function pointers (C++ virtual calls, "objects" in C) pass the object
    out += method_calls(source)
    return out


METHOD_CALL = re.compile(r"M2C_FIELD\(\*(\w+), ([^,()]*\(\*\*\)\([^()]*\)), (0x[0-9A-Fa-f]+|\d+)\)\(([^()]*)\)")


def method_calls(source: str) -> list[str]:
    """`M2C_FIELD(*obj, T (**)(), 4)()` is `obj->vtable->f(obj)` in the game: the object stays in r0 and the function
    pointer goes to r1 (`ldr r1, [r0]; ldr r1, [r1, #4]; blx r1`). m2c drops the object when the callee never names
    it; give it back as the first argument (keeping the arguments m2c kept)."""
    def add_self(m):
        args = m.group(4).strip()
        return f"M2C_FIELD(*{m.group(1)}, {m.group(2)}, {m.group(3)})({m.group(1)}{', ' + args if args else ''})"
    fixed = METHOD_CALL.sub(add_self, source)
    return [fixed] if fixed != source else []


def accumulate(source: str) -> list[str]:
    """`x = K;` after `x = 0;` where x is also accumulated with `|=` / `+=`: the original accumulated there too."""
    out = []
    zero = set(re.findall(r"^\s+(\w+) = 0;$", source, re.M))
    for op in ("|=", "+="):
        names = zero & set(re.findall(rf"^\s+(\w+) {re.escape(op)} ", source, re.M))
        if not names:
            continue
        fixed = re.sub(r"^(\s+)(\w+) = (?!0;)([^;\n]+);$",
                       lambda m: f"{m.group(1)}{m.group(2)} {op} {m.group(3)};" if m.group(2) in names else m.group(0),
                       source, flags=re.M)
        if fixed != source:
            out.append(fixed)
    return out


def _closing(s: str, i: int) -> int:
    """Index of the parenthesis closing the one opened just before s[i]."""
    depth = 1
    while i < len(s):
        depth += {"(": 1, ")": -1}.get(s[i], 0)
        if depth == 0:
            return i
        i += 1
    return -1


TABLE_TYPES = {1: ("s8", "u8"), 2: ("s16", "u16"), 4: ("s32",)}


def typed_tables(source: str) -> list[str]:
    """m2c leaves `*(&data_X + byte_offset)` when data_X is an `M2C_UNK`: the load type is lost. Rewrite it as an
    indexed table of each plausible element type (from the scale of the offset)."""
    out = []
    for g in sorted(set(re.findall(r"^extern M2C_UNK (\w+);", source, re.M))):
        for ty_index in range(2):
            fixed, pos, changed = source, 0, False
            while True:
                start = fixed.find(f"*(&{g} + ", pos)
                if start < 0:
                    break
                body = start + len(f"*(&{g} + ")
                end = _closing(fixed, body)
                if end < 0:
                    break
                offset = fixed[body:end]
                scale = 1
                m = re.fullmatch(r"\((.*) \* ([124])\)", offset)
                if m and _closing(offset, 1) == len(offset) - 1:
                    offset, scale = m.group(1), int(m.group(2))
                types = TABLE_TYPES[scale]
                if ty_index >= len(types):
                    pos = end
                    continue
                repl = f"(({types[ty_index]} *)&{g})[{offset}]"
                fixed = fixed[:start] + repl + fixed[end + 1:]
                pos = start + len(repl)
                changed = True
            if changed:
                out.append(fixed)
    return out


# The compiler turns `for (v = init; cond; step)` into a do/while with an entry test at the top; m2c rebuilds
# that rotated shape as `if (guard) { do { step; body } while (cond); }`. The original is often the `for` loop.
ROTATED_LOOP = re.compile(
    r"^(?P<ind>[ ]*)(?P<var>\w+) = (?P<init>[^;\n]+);\n"
    r"^(?P=ind)if \((?P<guard>[^()]*(?:\([^()]*\)[^()]*)*)\) \{\n"
    r"^(?P=ind)    do \{\n"
    r"(?P<body>(?:^(?P=ind)        [^\n]*\n)+)"
    r"^(?P=ind)    \} while \((?P<cond>[^\n]*)\);\n"
    r"^(?P=ind)\}\n", re.M)
ROTATED_LOOP_NO_INIT = re.compile(
    r"^(?P<ind>[ ]*)if \((?P<guard>[^()]*(?:\([^()]*\)[^()]*)*)\) \{\n"
    r"^(?P=ind)    do \{\n"
    r"(?P<body>(?:^(?P=ind)        [^\n]*\n)+)"
    r"^(?P=ind)    \} while \((?P<cond>[^\n]*)\);\n"
    r"^(?P=ind)\}\n", re.M)
LOOP_STEP = re.compile(r"^\s*(\w+) (\+=|-=|\|=|&=|\*=|/=) ([^;]+);\s*$")
LOOP_STEP_INCDEC = re.compile(r"^\s*(\w+)(\+\+|--);\s*$")


def rotated_loops(source: str) -> list[str]:
    """Writes a rotated loop back as the `for` loop the compiler started from (`func_0205e720`)."""
    out = []
    for regex, withinit in ((ROTATED_LOOP, True), (ROTATED_LOOP_NO_INIT, False)):
        m = regex.search(source)
        if not m:
            continue
        ind, cond = m.group("ind"), m.group("cond")
        lines = [line for line in m.group("body").splitlines() if line.strip()]
        names = set(re.findall(r"\b(\w+)\b", cond))
        step, step_index = None, -1
        for i, line in enumerate(lines):
            match = LOOP_STEP.match(line) or LOOP_STEP_INCDEC.match(line)
            if match and match.group(1) in names:
                step, step_index = line.strip().rstrip(";"), i
                break
        if step is None:
            continue
        del lines[step_index]
        rest = "\n".join(f"{ind}    {line.strip()}" for line in lines)
        init = f'{m.group("var")} = {m.group("init")}' if withinit else ""
        new = f"{ind}for ({init}; {cond.strip()}; {step}) {{\n{rest}\n{ind}}}\n"
        out.append(source[:m.start()] + new + source[m.end():])
    return out


def local_types(source: str) -> list[str]:
    """m2c types every local `s32`; the original often uses an unsigned type there, which makes the compiler
    emit an unsigned condition (`addcc`) where the game has a signed one (`addlt`)."""
    out = []
    for old, new in (("s32", "u32"), ("u32", "s32")):
        fixed = re.sub(rf"^(    ){old} (\w+);$", rf"\1{new} \2;", source, flags=re.M)
        if fixed != source:
            out.append(fixed)
    return out


SIGNED_COMPARISON = re.compile(r"(<=|>=|==|!=|<|>)\s*(0x[89A-Fa-f][0-9A-Fa-f]{7})\b")


def signed_constants(source: str) -> list[str]:
    """`0xFFFFCDBC` has type `unsigned int` in C, so `x < 0xFFFFCDBC` compiles as an unsigned comparison.
    m2c writes negative constants that way; the original wrote the signed value."""
    fixed = SIGNED_COMPARISON.sub(lambda m: f"{m.group(1)} {int(m.group(2), 16) - 0x100000000}", source)
    return [fixed] if fixed != source else []


POINTER_LOCAL = re.compile(r"^[ \t]+([A-Za-z_][\w ]*?)\s*\*[ \t]*(\w+);", re.M)


def pointer_add_bytes(source: str) -> list[str]:
    """`var_r1 += 0xC;` on a pointer m2c typed `M2C_UNK *` means 12 bytes, but C scales the offset by 4."""
    types = {m.group(2): m.group(1).strip() for m in POINTER_LOCAL.finditer(source)}
    if not types:
        return []
    out = source
    for var, ty in types.items():
        def repl(m, var=var, ty=ty):
            sign = "+" if m.group(2) == "+=" else "-"
            return f"{m.group(1)}{var} = ({ty} *)((s8 *){var} {sign} {m.group(3)});"
        out = re.sub(rf"^(\s*){re.escape(var)} (\+=|-=) (0x[0-9A-Fa-f]+|\d+);$", repl, out, flags=re.M)
    return [out] if out != source else []


CAST_GLOBAL_LOAD = re.compile(r"\*\(\(M2C_UNK \*\)\(\(s8 \*\)&")
GLOBAL_LOAD_TYPES = ("u8", "s8", "u16", "s16", "u32")


def typed_global_loads(source: str) -> list[str]:
    """`fix_byte_offsets` and `addr_plus_var` write `&data_X + n` as `(M2C_UNK *)((s8 *)&data_X + (n))`, so the
    load is always 32 bits wide even when the game loads a byte or a halfword (`ldrb` became `ldr`). The byte
    offset is kept as it is and only the pointee type is changed."""
    if not CAST_GLOBAL_LOAD.search(source):
        return []
    out = []
    for ty in GLOBAL_LOAD_TYPES:
        fixed = CAST_GLOBAL_LOAD.sub(f"*(({ty} *)((s8 *)&", source)
        if fixed != source:
            out.append(fixed)
    return out


COPY_STMT = re.compile(r"^    M2C_FIELD\((?P<d>\w+), s32 \*, (?P<do>0x[0-9A-Fa-f]+|\d+)\) = "
                       r"\(s32\) M2C_FIELD\((?P<s>\w+), s32 \*, (?P<so>0x[0-9A-Fa-f]+|\d+)\);$", re.M)
TEMP_INIT = re.compile(r"^    (?P<v>\w+) = (?P<base>\w+) \+ (?P<k>0x[0-9A-Fa-f]+|\d+);$", re.M)


def struct_copy(source: str, name: str) -> list[str]:
    """Consecutive word copies from one base to another are a single struct assignment in the game: the
    compiler emits `ldm r1, {r0-r3}; stm ip, {r0-r3}` for a 16-byte structure copy (`func_0204a038`)."""
    stmts = list(COPY_STMT.finditer(source))
    if not 2 <= len(stmts) <= 8:
        return []
    temps = {m.group("v"): (m.group("base"), int(m.group("k"), 0)) for m in TEMP_INIT.finditer(source)}

    def resolve(var):
        if var in temps:
            base, offset = temps[var]
            return None if base in temps else (base, offset)
        return var, 0

    rows = []
    for m in stmts:
        dst, src = resolve(m.group("d")), resolve(m.group("s"))
        if dst is None or src is None:
            return []
        rows.append((int(m.group("do"), 0) + dst[1], int(m.group("so"), 0) + src[1], dst[0], src[0]))
    if len({r[2] for r in rows}) != 1 or len({r[3] for r in rows}) != 1:
        return []
    dst_offs, src_offs = [r[0] for r in rows], [r[1] for r in rows]
    if any(b - a != 4 for a, b in zip(dst_offs, dst_offs[1:])) or \
       any(b - a != 4 for a, b in zip(src_offs, src_offs[1:])):
        return []
    sig = re.search(r"^[A-Za-z_][\w \*]*?\b\w+\([^)]*\) \{$", source, re.M)
    if not sig:
        return []
    n = len(rows)
    ty = f"M2C_S{n * 4}"
    typedef = f"typedef struct {{ {' '.join('s32 f%d;' % i for i in range(n))} }} {ty};\n\n"
    stmt = (f"    *({ty} *)((s8 *){rows[0][2]} + {dst_offs[0]}) = *({ty} *)((s8 *){rows[0][3]} + {src_offs[0]});\n")
    fixed = source[:stmts[0].start()] + stmt + source[stmts[-1].end():]
    return [fixed[:sig.start()] + typedef + fixed[sig.start():]]


def forward_extra_arg(source: str, name: str) -> list[str]:
    """A wrapper that passes its arguments through: m2c only declares the parameters it reads, so the wrapper
    looks one or two parameters shorter than the game (`func_0200bd40` forwards three to `func_02017f60`)."""
    out = []
    sig = re.search(rf"^(?P<ret>[A-Za-z_][\w \*]*?){re.escape(name)}\((?P<params>[^)]*)\) \{{$", source, re.M)
    if not sig:
        return out
    params_txt = sig.group("params")
    params = [] if params_txt.strip() in ("", "void") else [p.strip() for p in params_txt.split(",")]
    n = len(params)
    last_type = re.match(r"(.*?)\s*\w+$", params[-1]).group(1) if params else "M2C_UNK"
    body_start = sig.end()
    seen = set()
    for m in re.finditer(r"^(    )(\w+)\(([^;()]*)\);$", source[body_start:], re.M):
        args = [a.strip() for a in m.group(3).split(",") if a.strip()]
        if len(args) != n or m.group(2) in seen:
            continue
        seen.add(m.group(2))
        for extra in (1, 2):
            new_params = params + [f"{last_type} arg{n + i}" for i in range(extra)]
            new_args = args + [f"arg{n + i}" for i in range(extra)]
            call = f"{m.group(1)}{m.group(2)}({', '.join(new_args)});"
            new = (source[:sig.start("params")] + ", ".join(new_params)
                   + source[sig.end("params"):body_start + m.start()] + call
                   + source[body_start + m.end():])
            # The callee is usually declared in the same draft: widen its declaration too
            decl = re.search(rf"^([A-Za-z_][\w \*]*?){re.escape(m.group(2))}\(([^)]*)\);", new, re.M)
            if decl:
                existing = [p for p in decl.group(2).split(",") if p.strip() and p.strip() != "void"]
                filled = existing + ["M2C_UNK"] * max(0, len(new_args) - len(existing))
                new = new[:decl.start(2)] + ", ".join(filled) + new[decl.end(2):]
            out.append(new)
    return out

def stack_buffers(source: str, name: str) -> str | None:
    """`M2C_UNK sp2;` only used as `&sp2` is really a buffer: size it from the stack frame of the original."""
    asm = function_asm(name)
    if not asm:
        return None
    frame = 0
    for line in asm.splitlines()[1:]:
        s = line.split(";")[0].strip()
        m = re.match(r"sub sp, sp, #(0x[0-9a-fA-F]+|\d+)$", s)
        if m:
            frame += int(m.group(1), 0)
        elif not s.startswith(("push", "stmfd", "stmdb")) and frame:
            break
    if frame <= 4:
        return None
    decl = re.compile(r"^    (?:[us](?:8|16|32)|M2C_UNK|void \*) \*?(sp[0-9A-F]+);\n", re.M)
    offsets = {m.group(1): int(m.group(1)[2:], 16) for m in decl.finditer(source)}
    if not offsets:
        return None
    ordered = sorted(offsets.values())
    out = source
    changed = False
    for var, off in offsets.items():
        uses = re.findall(rf"(&?)\b{var}\b", out)
        if len(uses) < 2 or any(u != "&" for u in uses[1:]):
            continue  # also used as a value: keep it a scalar
        nxt = next((o for o in ordered if o > off), frame)
        size = nxt - off
        if size <= 4:
            continue
        out = re.sub(rf"^    (?:[us](?:8|16|32)|M2C_UNK|void \*) \*?{var};\n", f"    u8 {var}[{size}];\n", out, count=1, flags=re.M)
        out = re.sub(rf"&{var}\b", var, out)
        changed = True
    return out if changed else None


def addr_plus_var(source: str) -> str | None:
    """`&data_X + temp_r3` on an M2C_UNK global is a byte offset."""
    unk = set(re.findall(r"^extern M2C_UNK (\w+);", source, re.M))
    if not unk:
        return None

    def repl(m):
        if m.group(1) not in unk:
            return m.group(0)
        return f"(M2C_UNK *)((s8 *)&{m.group(1)} + {m.group(2)})"

    out = re.sub(r"&(\w+) \+ ([A-Za-z_]\w*)\b(?!\()", repl, source)
    return out if out != source else None


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


PERMUTE_STATE = WORK / "permute_state.json"


def permute_near(near: list[tuple[str, int, int, str]], count: int, minutes: float) -> list[tuple[str, int, int, str]]:
    """Runs the permuter on near misses that were not tried yet; returns the ones that reached a match.
    Every attempt is written to build/auto/permute_state.json (after each function, so an interruption loses nothing):
    the next run goes on with the following functions. AUTO_PERMUTE_MAX = attempts per function (default 1),
    AUTO_PERMUTE_RETRY=1 retries the ones that failed."""
    try:
        state = json.loads(PERMUTE_STATE.read_text(encoding="utf-8"))
    except Exception:
        state = {}
    limit = 10**6 if os.environ.get("AUTO_PERMUTE_RETRY") else int(os.environ.get("AUTO_PERMUTE_MAX", "1"))
    todo = [x for x in near if state.get(x[0], {}).get("attempts", 0) < limit]
    print(f"  permuter: {len(near)} near misses, {len(near) - len(todo)} already tried, {len(todo)} left", flush=True)
    won = []
    # Least tried first, then fewest differing instructions: those are the ones the permuter can actually finish
    with tempfile.TemporaryDirectory() as tmp:
        ranked = sorted(todo, key=lambda x: (state.get(x[0], {}).get("attempts", 0), diff_count(Path(tmp), *x), x[1]))
    for name, size, addr, source in ranked[:count]:
        src = WORK / "near" / f"{name}.c"
        subprocess.run([sys.executable, str(ROOT / "tools" / "permute.py"), name, "--source", str(src),
                        "--minutes", str(minutes)], cwd=ROOT, capture_output=True, text=True)
        best = sorted((ROOT / "build" / "permuter" / name).glob("output-0-*"))
        print(f"  {name}: {'MATCH' if best else 'no match'}", flush=True)
        st = state.setdefault(name, {"attempts": 0})
        st["attempts"] += 1
        st["minutes"] = st.get("minutes", 0) + minutes
        st["result"] = "match" if best else "no match"
        PERMUTE_STATE.write_text(json.dumps(state), encoding="utf-8")
        if best:
            # The permuter output is preprocessed and self-contained
            won.append((name, size, addr, (best[0] / "source.c").read_text(encoding="utf-8")))
    return won


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("-j", type=int, default=int(os.environ.get("AUTO_JOBS", os.cpu_count() or 4)))
    ap.add_argument("--permute", type=int, default=0, metavar="N", help="Run the permuter on N near misses")
    ap.add_argument("--minutes", type=float, default=5.0, help="Permuter time per function")
    ap.add_argument("--dry-run", action="store_true", help="Only report, change nothing")
    ap.add_argument("--cached-only", action="store_true",
                    help="Do not try new functions: only integrate the matches already in the cache (resume)")
    ap.add_argument("--names", help="Only these functions (comma separated), tried again even if cached")
    ap.add_argument("--neighbours", help="Only the callers and callees of these functions, tried again even if cached")
    args = ap.parse_args()

    if not M2C.exists():
        raise SystemExit(f"m2c not found at {M2C} (set M2C_PATH)")
    # dsd does not delete old files and gap file names change when delinks.txt changes
    shutil.rmtree(ASM_DIR, ignore_errors=True)
    subprocess.run(["ninja", "dis"], cwd=ROOT, check=True, capture_output=True)
    protos = ROOT / "include" / "m2c_protos.h"
    old_protos = protos.read_bytes() if protos.exists() else None
    journal_begin([protos])
    subprocess.run([sys.executable, str(ROOT / "tools" / "gen_context.py")], cwd=ROOT, check=True)
    if old_protos is not None and protos.read_bytes() != old_protos:
        # Files already in src/ include this header: make sure the ROM still builds byte-identical before going on
        # (a ninja build: seconds; the objects do not change unless the header does)
        import find_culprits
        out = find_culprits.build()
        if not find_culprits.rom_ok(out):
            print(out[-2000:])
            protos.write_bytes(old_protos)
            journal_end()
            raise SystemExit("New m2c_protos.h breaks the build: restored the previous one, stopping. "
                             "If the ROM already failed before, run tools/find_culprits.py.")
    journal_end()

    todo = candidates()
    focus = None  # --names / --neighbours: a few functions, retried because the context changed
    if args.names or args.neighbours:
        focus = set(args.names.split(",")) if args.names else set()
        if args.neighbours:
            focus |= neighbours(set(args.neighbours.split(",")))
        todo = [f for f in todo if f[0] in focus]
    cached = load_cache()
    keys = {f[0]: cache_key(f) for f in todo}
    results = [cached[keys[f[0]]] for f in todo if keys[f[0]] in cached and (focus is None or cached[keys[f[0]]][3] == "match")]
    pending = [f for f in todo if keys[f[0]] not in cached or (focus is not None and cached[keys[f[0]]][3] != "match")]
    if args.cached_only:
        # The asm text (part of the cache key) can change between dsd runs: in this mode take back the matches by
        # name + size + address. Nothing is trusted blindly: verify and find_culprits check the result.
        by_name = {}
        for line in CACHE.read_text(encoding="utf-8", errors="replace").splitlines() if CACHE.exists() else []:
            try:
                r = tuple(json.loads(line)["r"])
            except Exception:
                continue
            if r[3] == "match":
                by_name[(r[0], r[1], r[2])] = r
        have = {r[0] for r in results}
        results += [by_name[f] for f in todo if f[0] not in have and f in by_name]
        pending = []
    print(f"Trying {len(pending)} functions ({len(results)} already in the cache)...", flush=True)
    WORK.mkdir(parents=True, exist_ok=True)
    with Pool(args.j) as pool, CACHE.open("a", encoding="utf-8") as cache_out:
        for i, r in enumerate(pool.imap_unordered(try_function, pending, chunksize=4)):
            results.append(r)
            cache_out.write(json.dumps({"k": keys[r[0]], "v": AUTO_VERSION, "r": list(r)}) + chr(10))
            cache_out.flush()
            if i % 100 == 99:
                print(f"[{i + 1}/{len(pending)}] evaluated", flush=True)

    stats = {}
    for r in results:
        stats[r[3]] = stats.get(r[3], 0) + 1
    print("Results: " + ", ".join(f"{k} {v}" for k, v in sorted(stats.items())))

    found = [(n, s, a, src) for n, s, a, st, src in results if st == "match"]
    # Matches that broke the ROM once linked (find_culprits): known bad, not integrated again
    bad = set((WORK / "culprits.txt").read_text(encoding="utf-8").split()) if (WORK / "culprits.txt").exists() else set()
    if bad & {f[0] for f in found}:
        print(f"Skipping {len(bad & {f[0] for f in found})} match(es) known to break the ROM (build/auto/culprits.txt)")
        found = [f for f in found if f[0] not in bad]
    near = [(n, s, a, src) for n, s, a, st, src in results if st == "near"]
    WORK.mkdir(parents=True, exist_ok=True)
    if focus is not None and not args.cached_only:
        # Partial pass: update the near misses and the status of these functions only
        (WORK / "near").mkdir(exist_ok=True)
        for n, s, a, st, src in results:
            p = WORK / "near" / f"{n}.c"
            if st == "near":
                p.write_text(src, encoding="utf-8")
            elif st == "match":
                p.unlink(missing_ok=True)
        try:
            old = json.loads((WORK / "status.json").read_text())
        except Exception:
            old = []
        mine = {r[0]: list(r[:4]) for r in results}
        (WORK / "status.json").write_text(json.dumps([mine.pop(r[0], r) for r in old] + list(mine.values())))
    elif not args.cached_only:  # a partial pass must not replace the full list of near misses (Qwen, permuter use it)
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
    # Killed before the end (job cancelled): the next run puts these files back and deletes the new sources
    journal_begin([DELINKS, COMPILERS_TXT])
    created = integrate(found)
    journal_created(created)
    print(f"Added {len(created)} functions to src/auto/, verifying...")
    subprocess.run([sys.executable, "tools/configure.py", project.VERSION], cwd=ROOT, check=True, capture_output=True)
    verify = subprocess.run([sys.executable, "tools/match.py", "verify"], cwd=ROOT, capture_output=True, text=True)
    for _ in range(8):
        bad = re.findall(r"FAIL: (src/auto/\S+?\.c) is marked complete", verify.stdout) if verify.returncode else []
        if not bad:
            break
        print(f"Dropping {len(bad)} file(s) that do not match once linked: " + ", ".join(bad[:5]))
        # The cache keeps them as 'match': without this list every run would add them and verify again
        with (WORK / "culprits.txt").open("a", encoding="utf-8") as f:
            f.writelines(Path(b).stem + "\n" for b in bad)
        text = DELINKS.read_text()
        for rel in bad:
            text = re.sub(r"\n" + re.escape(rel) + r":\n    complete\n    \.text[^\n]*\n", "\n", text)
            (ROOT / rel).unlink(missing_ok=True)
        DELINKS.write_text(text, newline="\n")
        if COMPILERS_TXT.exists():
            keep = [l for l in COMPILERS_TXT.read_text().splitlines(True) if l.split(" ")[0] not in bad]
            COMPILERS_TXT.write_text("".join(keep), newline="\n")
        created = [c for c in created if c.relative_to(ROOT).as_posix() not in bad]
        subprocess.run([sys.executable, "tools/configure.py", project.VERSION], cwd=ROOT, check=True, capture_output=True)
        verify = subprocess.run([sys.executable, "tools/match.py", "verify"], cwd=ROOT, capture_output=True, text=True)
    if verify.returncode != 0:
        # Before throwing the whole run away, find the few files that break the ROM (one build, byte comparison)
        import find_culprits
        print("Verification failed: looking for the files that break the ROM...", flush=True)
        new = {c.relative_to(ROOT).as_posix() for c in created}
        ok, dropped = find_culprits.repair(allowed=new, log=lambda m: print(m, flush=True))
        if dropped:
            print(f"Dropped {len(dropped)} file(s) that break the ROM (kept in build/culprits/)")
            created = [c for c in created if c.relative_to(ROOT).as_posix() not in dropped]
            # Never retry them blindly: the cache keeps them as 'match', so mark them in a list auto_match skips
            with (WORK / "culprits.txt").open("a", encoding="utf-8") as f:
                f.writelines(Path(d).stem + "\n" for d in dropped)
        if ok:
            verify = subprocess.run([sys.executable, "tools/match.py", "verify"], cwd=ROOT, capture_output=True, text=True)
    print(verify.stdout.strip().splitlines()[-1] if verify.stdout else "")
    if verify.returncode != 0:
        print(verify.stdout[-3000:])
        WORK.mkdir(parents=True, exist_ok=True)
        (WORK / 'verify_fail.log').write_text(verify.stdout + chr(10) + verify.stderr, encoding='utf-8')
        print("Verification failed: rolling back.")
        DELINKS.write_bytes(backup)
        COMPILERS_TXT.write_bytes(compilers_backup)
        for p in created:
            p.unlink()
        subprocess.run([sys.executable, "tools/configure.py", project.VERSION], cwd=ROOT, capture_output=True)
        journal_end()
        sys.exit(1)
    journal_end()
    print(f"OK: {len(created)} new matching functions.")


if __name__ == "__main__":
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    from pipeline_lock import pipeline_lock

    with pipeline_lock("auto_match"):
        main()
