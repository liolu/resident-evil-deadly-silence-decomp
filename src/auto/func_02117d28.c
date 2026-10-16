/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02117d28 from https://github.com/kh-recoded-decomp/kh-recoded-decomp eu/src/asm_stubs/calls/func_02117d28.c (license:
 * MIT), reused by tools/donor_match.py */
// clang-format off
#pragma ipa file
asm double func_02117d28 (float value)
{
    and r2, r0, #0x80000000
    mov r12, r0, lsr #23
    mov r3, r0, lsl #9
    ands r12, r12, #0xff
    beq @zero_or_denormal
    cmp r12, #0xff
    beq @inf_or_nan
@pack:
    add r12, r12, #0x380
    mov r0, r3, lsl #20
    orr r1, r2, r3, lsr #12
    orr r1, r1, r12, lsl #20
    bx lr
@zero_or_denormal:
    cmp r3, #0
    bne @denormal
    mov r1, r2
    mov r0, #0
    bx lr
@denormal:
    mov r3, r3, lsr #1
    clz r12, r3
    movs r3, r3, lsl r12
    rsb r12, r12, #1
    add r3, r3, r3
    b @pack
@inf_or_nan:
    cmp r3, #0
    bhi @nan
    ldr r1, =0x7ff00000
    orr r1, r1, r2
    mov r0, #0
    bx lr
@nan:
    mvn r0, #0
    bic r1, r0, #0x80000000
    bx lr
}
// clang-format on
