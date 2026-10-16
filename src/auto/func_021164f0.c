/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

// clang-format on

/* func_020231e8 from https://github.com/kh-recoded-decomp/kh-recoded-decomp eu/src/asm_stubs/calls/func_020231e8.c (license:
 * MIT), reused by tools/donor_match.py */
// clang-format off
asm double func_021164f0 (double left, double right)
{
    stmfd sp!, {r4, r5, r6, r7, lr}
    eor lr, r1, r3
    and lr, lr, #0x80000000
    mov r12, r1, lsr #0x14
    mov r1, r1, lsl #0xb
    orr r1, r1, r0, lsr #21
    mov r0, r0, lsl #0xb
    movs r6, r12, lsl #0x15
    cmnne r6, #0x200000
    beq @L108
    orr r1, r1, #0x80000000
    bic r12, r12, #0x800
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    cmnne r5, #0x200000
    beq @L150
    orr r3, r3, #0x80000000
    bic r4, r4, #0x800
@L054:
    add r12, r4, r12
    umull r5, r4, r0, r2
    umull r7, r6, r0, r3
    adds r4, r7, r4
    adc r6, r6, #0
    umull r7, r0, r1, r2
    adds r4, r7, r4
    adcs r0, r0, r6
    umull r7, r2, r1, r3
    adc r1, r2, #0
    adds r0, r0, r7
    adc r1, r1, #0
    orrs r4, r4, r5
    orrne r0, r0, #1
    cmp r1, #0
    blt @L0a0
    sub r12, r12, #1
    adds r0, r0, r0
    adc r1, r1, r1
@L0a0:
    add r12, r12, #2
    subs r12, r12, #0x400
    bmi @L23c
    beq @L23c
    mov r6, r12, lsl #0x14
    cmn r6, #0x100000
    bmi @L33c
    movs r2, r0, lsl #0x15
    mov r0, r0, lsr #0xb
    orr r0, r0, r1, lsl #21
    add r1, r1, r1
    orr r1, lr, r1, lsr #12
    orr r1, r1, r12, lsl #20
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L108:
    bics r12, r12, #0x800
    beq @L164
    orrs r6, r0, r1, lsl #1
    bne @L2f0
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    beq @L144
    cmn r5, #0x200000
    bne @L2dc
    orrs r5, r2, r3, lsl #1
    beq @L2dc
    b @L2f0
@L144:
    orrs r5, r3, r2
    beq @L304
    b @L2dc
@L150:
    bics r4, r4, #0x800
    beq @L1f8
    orrs r6, r2, r3, lsl #1
    bne @L2f0
    b @L2dc
@L164:
    orrs r6, r0, r1, lsl #1
    beq @L1cc
    mov r12, #1
    cmp r1, #0
    bne @L188
    sub r12, r12, #0x20
    movs r1, r0
    mov r0, #0
    bmi @L1a4
@L188:
    clz r6, r1
    movs r1, r1, lsl r6
    rsb r6, r6, #0x20
    orr r1, r1, r0, lsr r6
    rsb r6, r6, #0x20
    mov r0, r0, lsl r6
    sub r12, r12, r6
@L1a4:
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    cmnne r5, #0x200000
    beq @L150
    orr r3, r3, #0x80000000
    bic r4, r4, #0x800
    b @L054
@L1cc:
    mov r4, r3, lsr #0x14
    mov r3, r3, lsl #0xb
    orr r3, r3, r2, lsr #21
    mov r2, r2, lsl #0xb
    movs r5, r4, lsl #0x15
    beq @L350
    cmn r5, #0x200000
    bne @L350
    orrs r6, r2, r3, lsl #1
    beq @L304
    b @L2f0
@L1f8:
    orrs r5, r2, r3, lsl #1
    beq @L350
    mov r4, #1
    cmp r3, #0
    bne @L21c
    sub r4, r4, #0x20
    movs r3, r2
    mov r2, #0
    bmi @L054
@L21c:
    clz r6, r3
    movs r3, r3, lsl r6
    rsb r6, r6, #0x20
    orr r3, r3, r2, lsr r6
    rsb r6, r6, #0x20
    mov r2, r2, lsl r6
    sub r4, r4, r6
    b @L054
@L23c:
    cmn r12, #0x34
    beq @L2d4
    bmi @L32c
    mov r2, r1
    mov r3, r0
    add r4, r12, #0x34
    cmp r4, #0x20
    movge r2, r3
    movge r3, #0
    subge r4, r4, #0x20
    rsb r5, r4, #0x20
    mov r2, r2, lsl r4
    orr r2, r2, r3, lsr r5
    movs r3, r3, lsl r4
    orrne r2, r2, #1
    rsb r12, r12, #0xc
    cmp r12, #0x20
    movge r0, r1
    movge r1, #0
    subge r12, r12, #0x20
    rsb r4, r12, #0x20
    mov r0, r0, lsr r12
    orr r0, r0, r1, lsl r4
    orr r1, lr, r1, lsr r12
    cmp r2, #0
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    tst r2, #0x80000000
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    movs r2, r2, lsl #1
    andeqs r2, r0, #1
    ldmeqfd sp!, {r4, r5, r6, r7, lr}
    bxeq lr
    adds r0, r0, #1
    adc r1, r1, #0
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L2d4:
    orr r0, r0, r1, lsl #1
    b @L314
@L2dc:
    ldr r1, =0x7ff00000
    orr r1, lr, r1
    mov r0, #0
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L2f0:
    mov r1, r3
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L304:
    mvn r0, #0
    bic r1, r0, #0x80000000
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L314:
    movs r2, r0
    mov r1, lr
    mov r0, #0
    addne r0, r0, #1
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L32c:
    mov r1, lr
    mov r0, #0
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L33c:
    ldr r1, =0x7ff00000
    orr r1, lr, r1
    mov r0, #0
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
@L350:
    mov r1, lr
    mov r0, #0
    ldmfd sp!, {r4, r5, r6, r7, lr}
    bx lr
}
