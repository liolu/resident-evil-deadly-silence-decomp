/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02116474 from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/runtime/dfltu.c (license: CC0-1.0),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
// clang-format off
asm double func_02116474(u32 x)
{
    cmp r0, #0
    mov r1, #0
    bxeq lr
    mov r3, #0x400
    add r3, r3, #30
    bmi normalised
    clz ip, r0
    movs r0, r0, lsl ip
    sub r3, r3, ip
normalised:
    mov r1, r0
    mov r0, r1, lsl #21
    add r1, r1, r1
    mov r1, r1, lsr #12
    orr r1, r1, r3, lsl #20
    bx lr
}
// clang-format on
