/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
typedef unsigned int u32;

// clang-format on
typedef unsigned char u8;

/* MI_CpuCopy from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/cpumem.c (license: none), reused by
 * tools/donor_match.py */
// clang-format off
asm void func_02106134(register const u32* src, register u32* dest, register u32 count) {
    stmdb   sp!, {r4, r5, r6, r7, r8, r9, r10}
    add     r10, r1, r2
    mov     ip, r2, lsr #0x5
    add     ip, r1, ip, lsl #0x5
@1:
    cmp     r1, ip
    ldmltia     r0!, {r2, r3, r4, r5, r6, r7, r8, r9}
    stmltia     r1!, {r2, r3, r4, r5, r6, r7, r8, r9}
    blt       @1
@2:
    cmp     r1, r10
    ldmltia     r0!, {r2}
    stmltia     r1!, {r2}
    blt       @2
    ldmia   sp!, {r4, r5, r6, r7, r8, r9, r10}
    bx      lr
}
