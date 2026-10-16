/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02117dac from https://github.com/kh-recoded-decomp/kh-recoded-decomp eu/src/asm_stubs/calls/func_02117dac.c (license:
 * MIT), reused by tools/donor_match.py */
// clang-format off
#pragma ipa file
asm int func_02117dac (float value)
{
    bic r1, r0, #0x80000000
    mov r2, #0x9e
    subs r2, r2, r1, lsr #23
    ble @overflow
    mov r1, r1, lsl #8
    orr r1, r1, #0x80000000
    cmp r0, #0
    mov r0, r1, lsr r2
    rsbmi r0, r0, #0
    bx lr
@overflow:
    mvn r0, r0, asr #31
    add r0, r0, #0x80000000
    bx lr
}
// clang-format on
