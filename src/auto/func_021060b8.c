/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
typedef unsigned int u32;

// clang-format on
typedef unsigned char u8;

/* MI_CpuCopyU32 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/cpumem.c (license: none), reused by
 * tools/donor_match.py */
// clang-format off
asm void func_021060b8(register const u32* src, register u32* dest, register u32 count) {
    add     ip, r1, r2
@1:
    cmp     r1, ip
    ldmltia     r0!, {r2}
    stmltia     r1!, {r2}
    blt       @1
    bx      lr
}
