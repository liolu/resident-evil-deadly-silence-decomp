/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_0207a068 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/os/os_terminate.c (license: none), reused
 * by tools/donor_match.py */
extern void func_02105510(void);
// clang-format off
asm void func_02105510(void) {
    mov r0, #0
    mcr p15, 0, r0, c7, c0, 4
    bx lr
}
// clang-format on
