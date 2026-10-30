/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* _ll_sdiv from https://github.com/tangosdev/sm64ds-decomp src/_ll_sdiv.c (license: MIT), reused by tools/donor_match.py */
extern int func_0211851c(int num, int den);
// clang-format off
asm long long func_0211836c(long long num, long long den)
{
    stmdb sp!, {r4, r5, r6, r7, r11, r12, lr}
    eor r4, r1, r3
    mov r4, r4, asr #1
    mov r4, r4, lsl #1
    orrs r5, r3, r2
    bne _L020
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
    bx lr
_L020:
    mov r5, r0, lsr #0x1f
    add r5, r5, r1
    mov r6, r2, lsr #0x1f
    add r6, r6, r3
    orrs r6, r5, r6
    bne _L054
    mov r1, r2
    bl func_0211851c
    ands r4, r4, #1
    movne r0, r1
    mov r1, r0, asr #0x1f
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
    bx lr
_L054:
    cmp r1, #0
    bge _L064
    rsbs r0, r0, #0
    rsc r1, r1, #0
_L064:
    cmp r3, #0
    bge _L074
    rsbs r2, r2, #0
    rsc r3, r3, #0
_L074:
    orrs r5, r1, r0
    beq _L198
    mov r5, #0
    mov r6, #1
    cmp r3, #0
    bmi _L0a0
_L08c:
    add r5, r5, #1
    adds r2, r2, r2
    adcs r3, r3, r3
    bpl _L08c
    add r6, r6, r5
_L0a0:
    cmp r1, #0
    blt _L0c0
_L0a8:
    cmp r6, #1
    beq _L0c0
    sub r6, r6, #1
    adds r0, r0, r0
    adcs r1, r1, r1
    bpl _L0a8
_L0c0:
    mov r7, #0
    mov r12, #0
    mov r11, #0
    b _L0e8
_L0d0:
    orr r12, r12, #1
    subs r6, r6, #1
    beq _L140
    adds r0, r0, r0
    adcs r1, r1, r1
    adcs r7, r7, r7
_L0e8:
    subs r0, r0, r2
    sbcs r1, r1, r3
    sbcs r7, r7, #0
    adds r12, r12, r12
    adc r11, r11, r11
    cmp r7, #0
    bge _L0d0
_L104:
    subs r6, r6, #1
    beq _L138
    adds r0, r0, r0
    adcs r1, r1, r1
    adc r7, r7, r7
    adds r0, r0, r2
    adcs r1, r1, r3
    adc r7, r7, #0
    adds r12, r12, r12
    adc r11, r11, r11
    cmp r7, #0
    bge _L0d0
    b _L104
_L138:
    adds r0, r0, r2
    adc r1, r1, r3
_L140:
    ands r7, r4, #1
    moveq r0, r12
    moveq r1, r11
    beq _L178
    subs r7, r5, #0x20
    movge r0, r1, lsr r7
    bge _L19c
    rsb r7, r5, #0x20
    mov r0, r0, lsr r5
    orr r0, r0, r1, lsl r7
    mov r1, r1, lsr r5
    b _L178
    mov r0, r1, lsr r7
    mov r1, #0
_L178:
    cmp r4, #0
    blt _L188
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
    bx lr
_L188:
    rsbs r0, r0, #0
    rsc r1, r1, #0
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
    bx lr
_L198:
    mov r0, #0
_L19c:
    mov r1, #0
    cmp r4, #0
    blt _L188
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
    bx lr
}
// clang-format on
