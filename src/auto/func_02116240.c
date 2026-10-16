/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_0202354c from https://github.com/kh-recoded-decomp/kh-recoded-decomp eu/src/asm_stubs/calls/func_0202354c.c (license:
 * MIT), reused by tools/donor_match.py */
// clang-format off
#pragma ipa file
asm void func_02116240 (void)
{
    and       r2, r1, #0x80000000
    mov       r12, r1, lsr #0x14
    bics      r12, r12, #0x800
    beq       L078
    mov       r3, r12, lsl #0x15
    cmn       r3, #0x200000
    bhs       L05c
    subs      r12, r12, #0x380
    bls       L088
    cmp       r12, #0xff
    bge       L0f8
    mov       r1, r1, lsl #0xc
    orr       r3, r2, r1, lsr #9
    orr       r3, r3, r0, lsr #29
    movs      r1, r0, lsl #3
    orr       r0, r3, r12, lsl #23
    bxeq      lr
    tst       r1, #0x80000000
    bxeq      lr
    movs      r1, r1, lsl #1
    andeqs    r1, r0, #1
    addne     r0, r0, #1
    bx        lr
L05c:
    orrs      r3, r0, r1, lsl #12
    bne       L070
    mov       r0, #0xff000000
    orr       r0, r2, r0, lsr #1
    bx        lr
L070:
    mvn       r0, #0x80000000
    bx        lr
L078:
    orrs      r3, r0, r1, lsl #12
    bne       L0f0
    mov       r0, r2
    bx        lr
L088:
    cmn       r12, #0x17
    beq       L0dc
    bmi       L0f0
    mov       r1, r1, lsl #0xb
    orr       r1, r1, #0x80000000
    mov       r3, r1, lsr #8
    orr       r3, r3, r0, lsr #29
    rsb       r12, r12, #1
    movs      r1, r0, lsl #3
    orr       r0, r2, r3, lsr r12
    rsb       r12, r12, #0x20
    mov       r3, r3, lsl r12
    orrne     r3, r3, #1
    movs      r1, r3
    bxeq      lr
    tst       r1, #0x80000000
    bxeq      lr
    movs      r1, r1, lsl #1
    andeqs    r1, r0, #1
    addne     r0, r0, #1
    bx        lr
L0dc:
    orr       r0, r0, r1, lsl #12
    movs      r1, r0
    mov       r0, r2
    addne     r0, r0, #1
    bx        lr
L0f0:
    mov       r0, r2
    bx        lr
L0f8:
    mov       r0, #0xff000000
    orr       r0, r2, r0, lsr #1
    bx        lr
}
// clang-format on
