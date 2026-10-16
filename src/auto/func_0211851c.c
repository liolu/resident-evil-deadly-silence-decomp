/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_0211851c from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/runtime/s32_div_f.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
typedef signed int s32;
extern s32 func_0211851c(s32 dividend, s32 divisor);
// clang-format off
asm s32 func_0211851c(s32 dividend, s32 divisor)
{

    eor r12, r0, r1
    and r12, r12, #0x80000000
    cmp r0, #0
    rsblt r0, r0, #0
    addlt r12, r12, #1
    cmp r1, #0
    rsblt r1, r1, #0
    beq @apply_signs
    cmp r0, r1
    movcc r1, r0
    movcc r0, #0
    bcc @apply_signs


    mov r2, #28
    mov r3, r0, lsr #4
    cmp r1, r3, lsr #12
    suble r2, r2, #16
    movle r3, r3, lsr #16
    cmp r1, r3, lsr #4
    suble r2, r2, #8
    movle r3, r3, lsr #8
    cmp r1, r3
    suble r2, r2, #4
    movle r3, r3, lsr #4
    mov r0, r0, lsl r2
    rsb r1, r1, #0
    adds r0, r0, r0
    add r2, r2, r2, lsl #1
    add pc, pc, r2, lsl #2
    nop
    adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0;
    adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0;
    adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0;
    adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0;
    adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0;
    adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0;
    adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0;
    adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0; adcs r3, r1, r3, lsl #1; subcc r3, r3, r1; adcs r0, r0, r0;
    mov r1, r3

@apply_signs:
    ands r3, r12, #0x80000000
    rsbne r0, r0, #0
    ands r3, r12, #1
    rsbne r1, r1, #0
    bx lr
}
// clang-format on
