/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02104c10 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/os/os_protection.c (license:
 * none), reused by tools/donor_match.py */
// clang-format off
asm void func_02104c10(void) {
    mrc     p15, 0, r0, c1, c0, 0
    orr     r0, r0, #1
    mcr     p15, 0, r0, c1, c0, 0
    bx      lr
}
// clang-format on
