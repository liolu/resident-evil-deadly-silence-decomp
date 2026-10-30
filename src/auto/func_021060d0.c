/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* MI_CpuFillFromSrc from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/mi/cpumem.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
// clang-format off
asm void func_021060d0(register const u32* src, register u32* dest, register u32 count) {
    add     ip, r0, r2
@1:
    cmp     r0, ip
    ldmltia     r0!, {r2}
    strlt     r2, [r1, 0x0]
    blt       @1
    bx      lr
}
// clang-format on
