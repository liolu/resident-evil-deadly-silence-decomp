/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02117de0 from https://github.com/kh-recoded-decomp/kh-recoded-decomp eu/src/asm_stubs/calls/func_02117de0.c (license:
 * MIT), reused by tools/donor_match.py */
// clang-format off
#pragma ipa file
asm unsigned int func_02117de0 (float value)
{
    tst r0, #0x80000000
    bne @negative
    mov r1, #0x9e
    subs r1, r1, r0, lsr #23
    blt @overflow
    mov r2, r0, lsl #8
    orr r0, r2, #0x80000000
    mov r0, r0, lsr r1
    bx lr
@negative:
    mov r2, #0xff000000
    cmp r2, r0, lsl #1
    movhs r0, #0
    mvnlo r0, #0
    bx lr
@overflow:
    mvn r0, #0
    bx lr
}
// clang-format on
