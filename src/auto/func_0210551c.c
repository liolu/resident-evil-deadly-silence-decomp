/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */

typedef unsigned int u32;
// clang-format on

/* OS_Delay from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/os/cpustat.c (license: none), reused by
 * tools/donor_match.py */
// clang-format off
asm void func_0210551c(register u32 count) {
loop:
    subs count, count, #0x4
    bhs loop
    bx lr
}
