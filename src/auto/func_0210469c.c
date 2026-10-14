#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_0210469c(void) {
    add r1, r1, r0
    bic r0, r0, #0x1f
L_021046a4:
    mcr p15, 0, r0, c7, c6, 1
    add r0, r0, #0x20
    cmp r0, r1
    blt L_021046a4
    bx lr
}
// clang-format on
