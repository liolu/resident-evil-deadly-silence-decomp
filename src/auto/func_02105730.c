#include "m2c.h"

/* Count leading zeros: the game emits a single `clz r0, r0`. mwccarm has no intrinsic
   for it (`__cntlzw`, `__clz`, `__builtin_clz`, `__CLZ` all become a library call, see
   docs/troubleshooting.md), so the instruction cannot be produced from C. Probed:
   plain C shift loop (wrong length), __builtin_clz, __cntlzw, intrinsic names: none
   generate `clz`. Written in assembly, like the other compiler-never-generates
   instructions (`swp`, `mrs`, `msr`). */
// clang-format off
asm void func_02105730(void) {
    clz r0, r0
    bx lr
}
// clang-format on
