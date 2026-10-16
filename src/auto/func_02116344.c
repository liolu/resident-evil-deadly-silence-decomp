/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02116344 from https://github.com/kh-recoded-decomp/kh-recoded-decomp eu/src/asm_stubs/calls/func_02116344.c (license:
 * MIT), reused by tools/donor_match.py */
// clang-format off
#pragma ipa file
asm int func_02116344(double value)
{
    bic r3, r1, #0x80000000
    ldr r2, =0x41e
    subs r2, r2, r3, lsr #20
    ble @overflow
    cmp r2, #0x20
    bge @underflow
    mov r3, r1, lsl #11
    orr r3, r3, #0x80000000
    orr r3, r3, r0, lsr #21
    cmp r1, #0
    mov r0, r3, lsr r2
    rsbmi r0, r0, #0
    bx lr
@underflow:
    mov r0, #0
    bx lr
@overflow:
    mvn r0, r1, asr #31
    add r0, r0, #0x80000000
    bx lr
}
// clang-format on
