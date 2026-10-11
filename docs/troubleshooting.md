# Troubleshooting

Known errors, their cause and the fix. Add an entry every time you solve a new problem
(format: symptom → cause → fix).

## Build

**`sjiswrap: File ... contains Shift JIS encoding errors`**
- Cause: non-ASCII characters (accents, UTF-8) in a source or header. `sjiswrap` reads sources as Shift-JIS.
- Fix: ASCII only, comments in English. Check with `grep -rnP "[^\x00-\x7F]" src include`.

**`ninja` prints `Downloading dsd ...` although dsd is present**
- Cause: `configure.py` downloads the exact `DSD_VERSION` it expects.
- Fix: nothing to do. To use pre-installed compilers, pass `--compiler` or set `MWCCARM`.

**After marking a file `complete`: `Symbol 'data_020bc02c' ... not found by name in linked binary (Possible name: @44)`**
- Cause: the compiler gives internal names to anonymous string literals (`@43`, `@44`) and to local statics
  (`name$37`). The ROM itself is already correct; only the name check fails.
- Fix: `ninja apply` copies these names into `symbols.txt` as `local` symbols, then run `ninja` again.

## Matching

**Code at 100% but `.data` at ~58% (assertion strings)**
- Cause: in the game, the function name string comes **before** the expression and file name strings, although the
  call passes them in the order expression, file, function.
- Fix: declare `static char szFunctionName[] = "...";` at the top of the function and pass it to the assertion.
  This is the shape of the OpenSpace assertion macro: reuse it everywhere.

**`.data` at ~99% although the bytes are identical**
- Cause: dsd includes alignment padding in data symbol sizes (0x20 instead of 0x1f).
- Fix: give the real size in `symbols.txt`, e.g. `kind:data(byte[31])`.

**`func_0200cbdc` (search in a linked list) does not match (open)**
- Symptom: the game has `b <test>` at the top of the loop and a separate `bxeq lr`. Every tried form (`for`,
  `while`, `break`, `return` inside the loop) gives either a rotated loop or conditional instructions
  (`ldrne`/`cmpne`). Same result with every 2.0 compiler, so it is not a compiler version issue.
- Ideas: an OpenSpace list macro (`LST_M_...` in ACP_Ray2), an inline function, or different flags for that file.

## Probe tool

**Every compiler gives `N/N diff` even with correct C**
- Cause: a wrong function size was typed by hand.
- Fix: leave the size out, `probe_compiler.py` reads it from `symbols.txt`.

**`error: argument --flags: expected one argument`**
- Cause: a value starting with `-` (`-O4,p`) is parsed as an option.
- Fix: write `--flags=-O4,p`.

## Environment

**`dsd init` fails with `Local function call from 0x... leads to no function`**
- Seen on other games (Children of Mana, The Sims 2 DS, Viva Piñata DS), not on this one.
- Cause: dsd's automatic analysis misses a called function (unusual code, data mixed with code).
- Fix: add the missing function to `symbols.txt` by hand and run `dsd init` again.

**GCC not found after installing WinLibs with winget (Windows)**
- Cause: the package does not add GCC to the `PATH`.
- Fix: add its `mingw64/bin` directory to the `PATH` of your shell.

## Automation

**Files declared in `delinks.txt` disappear from the link (`Unreferenced symbols ... [whole file]`), symbols shift**
- Cause: mwldarm dead-strips unreferenced files **by default**, e.g. `AutoloadCallback`, which is only reached
  through the ROM header. Removing `-dead` is not enough.
- Fix: `-nodead` in the linker flags (`tools/configure.py`).

**Drafts or `auto_match` use old symbol names (link error `Undefined : "func_0201b39c"`)**
- Cause: `dsd dis` does not delete its old output, and the gap file names change when `delinks.txt` changes, so a
  stale `.s` file with the old names was read first.
- Fix: delete `build/usa/asm/` before `ninja dis` (the moulinette and `auto_match.py` do it).


**The permuter keeps running after its time limit / worker processes stay alive (Windows)**
- Cause: `taskkill /T` needs WMI; on some Windows installs WMI is broken (`Invalid provider registration` /
  `Inscription du fournisseur non valide`), so only the parent process was stopped.
- Fix: `tools/permute.py` kills the process tree with `psutil` (`pip install psutil`).

**The permuter fails to compile anything when started from PowerShell**
- Cause: `bash` resolves to `C:\Windows\System32\bash.exe` (WSL) instead of Git Bash.
- Fix: put Git's `bin` directory first in `PATH`.

**`unknown relocation type 'R_ARM_V4BX'` in the permuter**
- Cause: GNU as targets ARMv4 by default and tags every `bx` with a V4BX relocation.
- Fix: assemble the target with `-mcpu=arm946e-s` (done by `tools/permute.py`).

**Assembly functions no longer compile after `pre-commit` (`add r2, r0, #0x2 swpb r0, r1, [r2] bx lr`)**
- Cause: clang-format joins the instructions of an `asm` function on one line.
- Fix: wrap every `asm` function in `// clang-format off` / `// clang-format on`. The moulinette re-verifies the
  build after formatting, which is how this was caught.

**`func_0200c4f8` tail call uses `r1` instead of `ip` (open)**
- The game loads the target in `r1` (`ldr r1, =func_0200c61c; bx r1`); every C form tried (8 signatures, every
  compiler version) uses `ip`. Possibly hand-written assembly.

## Notes

**Raw address `.word 0x20bbb2c` in `func_0200b53c`**
- This is the start of the `.ctor` section (empty in this game). The function calls the static initializers.
- dsd already handles it correctly (`relocs.txt`: `kind:link_time_const(ARM9_CTOR_START)`). Nothing to do.
