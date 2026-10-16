/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02117e20 from https://github.com/kh-recoded-decomp/kh-recoded-decomp eu/src/asm_stubs/calls/func_02117e20.c (license:
 * MIT), reused by tools/donor_match.py */
// clang-format off
#pragma ipa file
asm float func_02117e20 (unsigned int value)
{
    cmp r0, #0
    bxeq lr
    mov r3, #0x9e
    bmi @normalised
    clz r12, r0
    movs r0, r0, lsl r12
    sub r3, r3, r12
@normalised:
    ands r2, r0, #0xff
    add r0, r0, r0
    mov r0, r0, lsr #9
    orr r0, r0, r3, lsl #23
    bxeq lr
    tst r2, #0x80
    bxeq lr
    ands r1, r2, #0x7f
    andeqs r1, r0, #1
    addne r0, r0, #1
    bx lr
}
// clang-format on
