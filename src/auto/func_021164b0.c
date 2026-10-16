/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_021164b0 from https://github.com/kh-recoded-decomp/kh-recoded-decomp eu/src/asm_stubs/calls/func_021164b0.c (license:
 * MIT), reused by tools/donor_match.py */
// clang-format off
#pragma ipa file
asm double func_021164b0 (int value)
{
    ands r2, r0, #0x80000000
    rsbmi r0, r0, #0
    cmp r0, #0
    mov r1, #0
    bxeq lr
    mov r3, #0x400
    add r3, r3, #0x1e
    clz r12, r0
    movs r0, r0, lsl r12
    sub r3, r3, r12
    movs r1, r0
    mov r0, r1, lsl #21
    add r1, r1, r1
    orr r1, r2, r1, lsr #12
    orr r1, r1, r3, lsl #20
    bx lr
}
// clang-format on
