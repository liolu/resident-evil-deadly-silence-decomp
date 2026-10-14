#include "m2c.h"

/* Uses instructions the compiler never generates: written in assembly. */
// clang-format off
asm void func_021063b4(void) {
    stmfd sp!, {r4, r5, r6, lr}
    ldr r5, [r0], #0x4
    mov r2, r5, lsr #0x8
L_021063c0:
    cmp r2, #0x0
    ble L_02106440
    ldrb lr, [r0], #0x1
    mov r4, #0x8
L_021063d0:
    subs r4, r4, #0x1
    blt L_021063c0
    tst lr, #0x80
    bne L_021063f4
    ldrb r6, [r0], #0x1
    swpb r6, r6, [r1]
    add r1, r1, #0x1
    sub r2, r2, #0x1
    b L_02106430
L_021063f4:
    ldrb r5, [r0, #0x0]
    mov r6, #0x3
    add r3, r6, r5, asr #0x4
    ldrb r6, [r0], #0x1
    and r5, r6, #0xf
    mov ip, r5, lsl #0x8
    ldrb r6, [r0], #0x1
    orr r5, r6, ip
    add ip, r5, #0x1
    sub r2, r2, r3
L_0210641c:
    ldrb r5, [r1, -ip]
    swpb r5, r5, [r1]
    add r1, r1, #0x1
    subs r3, r3, #0x1
    bgt L_0210641c
L_02106430:
    cmp r2, #0x0
    movgt lr, lr, lsl #0x1
    bgt L_021063d0
    b L_021063c0
L_02106440:
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
}
// clang-format on
