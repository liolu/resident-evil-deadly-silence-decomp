/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02117eb0 from https://github.com/kh-recoded-decomp/kh-recoded-decomp eu/src/asm_stubs/calls/func_02117eb0.c (license:
 * MIT), reused by tools/donor_match.py */
// clang-format off
#pragma ipa file
asm float func_02117eb0 (float left, float right)
{
    eor r2, r0, r1
    and r2, r2, #0x80000000
    mov r12, #0xff
    ands r3, r12, r0, lsr #23
    mov r0, r0, lsl #8
    cmpne r3, #0xff
    beq @L07c
    orr r0, r0, #0x80000000
    ands r12, r12, r1, lsr #23
    mov r1, r1, lsl #8
    cmpne r12, #0xff
    beq @L0bc
    orr r1, r1, #0x80000000
@L034:
    add r12, r3, r12
    umull r1, r3, r0, r1
    movs r0, r3
    addpl r0, r0, r0
    subpl r12, r12, #1
    subs r12, r12, #0x7f
    bmi @L148
    cmp r12, #0xfe
    bge @L1b4
    ands r3, r0, #0xff
    orr r0, r2, r0, lsr #8
    add r0, r0, r12, lsl #23
    tst r3, #0x80
    bxeq lr
    orrs r1, r1, r3, lsl #25
    andeqs r3, r0, #1
    addne r0, r0, #1
    bx lr
@L07c:
    cmp r3, #0
    beq @L0d0
    movs r0, r0, lsl #1
    bne @L1a4
    mov r12, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands r12, r12, #0xff
    beq @L0b0
    cmp r12, #0xff
    blt @L198
    cmp r1, #0
    beq @L198
    b @L1a4
@L0b0:
    cmp r1, #0
    beq @L1ac
    b @L198
@L0bc:
    cmp r12, #0
    beq @L12c
@L0c4:
    movs r1, r1, lsl #1
    bne @L1a4
    b @L198
@L0d0:
    movs r0, r0, lsl #1
    beq @L108
    mov r0, r0, lsr #1
    clz r3, r0
    movs r0, r0, lsl r3
    rsb r3, r3, #1
    mov r12, r1, lsr #0x17
    mov r1, r1, lsl #8
    ands r12, r12, #0xff
    beq @L12c
    cmp r12, #0xff
    beq @L0c4
    orr r1, r1, #0x80000000
    b @L034
@L108:
    mov r12, r1, lsr #0x17
    mov r1, r1, lsl #9
    ands r12, r12, #0xff
    beq @L1d8
    cmp r12, #0xff
    blt @L1d8
    cmp r1, #0
    beq @L1ac
    b @L1a4
@L12c:
    movs r1, r1, lsl #1
    beq @L1d8
    mov r1, r1, lsr #1
    clz r12, r1
    movs r1, r1, lsl r12
    rsb r12, r12, #1
    b @L034
@L148:
    cmn r12, #0x18
    beq @L190
    bmi @L1d0
    cmp r1, #0
    orrne r0, r0, #1
    mov r3, r0
    mov r0, r0, lsr #8
    rsb r12, r12, #0
    orr r0, r2, r0, lsr r12
    rsb r12, r12, #0x18
    movs r1, r3, lsl r12
    bxeq lr
    tst r1, #0x80000000
    bxeq lr
    movs r1, r1, lsl #1
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
@L190:
    mov r0, r0, lsl #1
    b @L1c0
@L198:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
@L1a4:
    mvn r0, #0x80000000
    bx lr
@L1ac:
    mvn r0, #0x80000000
    bx lr
@L1b4:
    mov r0, #0xff000000
    orr r0, r2, r0, lsr #1
    bx lr
@L1c0:
    movs r1, r0
    mov r0, r2
    addne r0, r0, #1
    bx lr
@L1d0:
    mov r0, r2
    bx lr
@L1d8:
    mov r0, r2
    bx lr
}
// clang-format on
