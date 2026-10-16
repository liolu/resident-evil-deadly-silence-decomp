/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
typedef unsigned int u32;

// clang-format on
typedef unsigned char u8;

/* MI_CpuSet from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/cpumem.c (license: none), reused by
 * tools/donor_match.py */
// clang-format off
asm void func_021061d8(register void* dest, register u8 value, register u32 count) {
    cmp     r2, #0x0
    bxeq    lr
    tst     r0, #0x1
    beq     aligned
    ldrh    ip, [r0, #-0x1]
    and     ip, ip, #0xff
    orr     r3, ip, r1, lsl #0x8
    strh    r3, [r0, #-0x1]
    add     r0, r0, #0x1
    subs    r2, r2, #0x1
    bxeq    lr
aligned:
    cmp     r2, #0x2
    blo     final
    orr     r1, r1, r1, lsl #0x8
    tst     r0, #0x2
    beq     word_aligned
    strh    r1, [r0], #0x2
    subs    r2, r2, #0x2
    bxeq    lr
word_aligned:
    orr     r1, r1, r1, lsl #0x10
    bics    r3, r2, #0x3
    beq     check_half
    sub     r2, r2, r3
    add     ip, r3, r0
loop:
    str     r1, [r0], #0x4
    cmp     r0, ip
    blo     loop
check_half:
    tst     r2, #0x2
    strneh    r1, [r0], #0x2
final:
    tst     r2, #0x1
    bxeq    lr
    ldrh    r3, [r0, #0x0]
    and     r3, r3, #0xff00
    and     r1, r1, #0xff
    orr     r1, r1, r3
    strh    r1, [r0, #0x0]
    bx      lr
}
