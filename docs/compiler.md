# Compiler identification

Method adapted from ray3 (`docs/compiler-identification.md`): small game functions are reconstructed in C and
compiled with **every** `mwccarm` version and several optimization levels (`tools/probe_compiler.py`). `bl` targets
and literal pools are masked, so only the instructions have to match.

## Result

**mwccarm 2.0 with `-O4,p`.** The project uses `2.0/sp1p5`, like Phantom Hourglass (decomp.me preset
`mwcc_30_131`).

| Probe (`tools/probes/`) | Function | 1.2.x | 2.0 (all) | `-O4,s` / `-O2` / `-O3` |
|---|---|---|---|---|
| `hie_pop.c` | `HIE_fn_bPopOnCameraMatrixStack` 0x0201b39c | ✗ (size 0x88-0x8c) | ✓ | ✓ (too simple to tell) |
| `list_nth.c` | `func_0201c2e8` | ✗ | ✓ | ✗ (size 0x28) ⇒ **`-O4,p`** |
| `call_table.c` | `func_0200b53c` | ✗ | ✓ | – |
| `str_cat.c` | `func_02003e30` (strcat) | ✗ | ✓ | – |
| `list_find.c` | `func_0200cbdc` | ✗ | ✗ | unsolved, see [troubleshooting.md](troubleshooting.md) |

The DSi compilers (`dsi/*`) also match with `-O4,p`, but they were released after the game (March 2007), so they
are ruled out.

**Still open:** no probe has told the 2.0 sub-versions apart yet (base, sp1, sp1p2 ... sp2p4). If a function refuses
to match although everything looks right, run the probe against all versions:

```shell
python tools/probe_compiler.py <file.c> <function> <address> --flags=-O4,p
```

## A second compiler: mwccarm 1.2 for some libraries

About 220 functions (mostly around `0x0200xxxx`-`0x0201xxxx` and `0x020bxxxx`) start with `push {lr}` +
`sub sp, sp, #0x4` and return with `ldmfd` + `bx lr`: the 1.2 prologue. They match with **1.2 (base to sp2p3)**
`-O4,p`, never with 2.0. These are probably libraries built separately.

Files built with another compiler are listed in `config/usa/compilers.txt` (`<source path> <version>`), read by
`tools/configure.py`. `tools/auto_match.py` tries 2.0/sp1p5 first, then 1.2/sp2p3, and records the files that need 1.2.

## `pop {..., lr}` + `bx lr` epilogues are 1.2 too

390 functions return with `pop {..., lr}` + `bx lr` instead of `pop {..., pc}`. This first looked like code built for
an ARMv4T processor, but it is the normal 1.2 epilogue: `func_02013f44` matches with plain 1.2/sp2p3 once its fields
are `volatile` and its interrupt guard is written (see below). One function, `func_02098974`, needs
`-proc arm7tdmi`; `compilers.txt` accepts extra flags after the version for such cases.

## Interrupt guards

The SDK interrupt helpers (named from their code: `OS_EnableIrq`, `OS_DisableIrq`, `OS_RestoreIrq`,
`OS_DisableInterrupts`, `OS_RestoreInterrupts`, `OS_GetProcMode`) are assembly functions. Callers keep the returned
state in `r0` and pass it back: `state = OS_DisableIrq(); ...; OS_RestoreIrq(state);`.

## Flags (`tools/configure.py`)

`-O4,p -enum int -char signed -str noreuse -proc arm946e -gccext,on -fp soft -inline noauto -lang=c -interworking`

- `-char signed`: confirmed (`ldrsb` in strcat).
- `-lang=c`: the engine is written in C.

## Reproduced observations
- A function that works in `r2`/`r3` and leaves `r0`/`r1` untouched before a call forwards its arguments to the
  callee: the first scratch register used tells how many (`r3` → three arguments).
- A value computed into `r0` right before `bx lr` (e.g. `ldr r0, [r1]; add r0, r0, #1; str r0, [r1]`) means the
  function returns it: `return ++x;`.
- `ldr r0, [r1, r0, lsl #N]` is a plain array access `table[i]` (or `table[i].first_field` for a stride of
  `1 << N` bytes).
- Hardware registers are `volatile`; a register written as two words at `addr` and `addr + 4` is a 64-bit register
  (e.g. `REG_SQRT_PARAM` at `0x040002B8`): otherwise the compiler merges the addresses into `base + offset`.
- `mul` (32-bit) instead of `smulbb` (16-bit) for `count * 12` means the size is `count * sizeof(elem)`:
  `sizeof` is unsigned long, so the product is computed on 32 bits.
- `smlabb` with a `short` argument indexes a table through a pointer to it: `&g_p_stTable[wIndex]`.
- Copy loops written as `if (n <= 0) return; do { n--; *p op= v; p++; } while (n > 0);`.
- No `__swpb` intrinsic: functions using `swp`/`swpb` (and `mrs`/`msr`) were written as `asm` functions.
- When the first argument of a function is unused, the code still reads the second argument from `r1`: declare the
  unused parameter.
- Functions save `{r3, lr}` to keep the stack 8-byte aligned. This is typical of 2.0; 1.2 uses another sequence.
- `x > 0` on an `unsigned long` compiles to `subs` + `bne` (a `!= 0` test).
- A `static char[]` declared inside a function is placed in `.data` **before** the string literals of that function.
- String literals go to `.data` (not `.rodata`), each one aligned to 4 bytes.
