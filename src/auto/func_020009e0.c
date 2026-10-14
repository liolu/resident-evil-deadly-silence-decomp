#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
extern void AutoloadCallback();
extern char BuildInfo[];
// clang-format off
asm void func_020009e0(void) {
    ldr r0, =BuildInfo
    ldr r1, [r0, #0x0]
    ldr r2, [r0, #0x4]
    ldr r3, [r0, #0x8]
L_020009f0:
    cmp r1, r2
    beq L_02000a50
    ldr r5, [r1], #0x4
    ldr r7, [r1], #0x4
    add r6, r5, r7
    mov r4, r5
L_02000a08:
    cmp r4, r6
    ldrmi r7, [r3], #0x4
    strmi r7, [r4], #0x4
    bmi L_02000a08
    ldr r7, [r1], #0x4
    add r6, r4, r7
    mov r7, #0x0
L_02000a24:
    cmp r4, r6
    strlo r7, [r4], #0x4
    blo L_02000a24
    bic r4, r5, #0x1f
L_02000a34:
    mcr p15, 0, r7, c7, c10, 4
    mcr p15, 0, r4, c7, c5, 1
    mcr p15, 0, r4, c7, c14, 1
    add r4, r4, #0x20
    cmp r4, r6
    blt L_02000a34
    b L_020009f0
L_02000a50:
    b AutoloadCallback
}
// clang-format on
