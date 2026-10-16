/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02066dcc from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/gx/gx_sendfifo.c (license: none), reused
 * by tools/donor_match.py */
// clang-format off
asm void func_021025b4(register const void *src, register volatile void *fifo) {
    ldmia   r0!, {r2, r3, r12}
    stmia   r1, {r2, r3, r12}
    ldmia   r0!, {r2, r3, r12}
    stmia   r1, {r2, r3, r12}
    ldmia   r0!, {r2, r3, r12}
    stmia   r1, {r2, r3, r12}
    ldmia   r0!, {r2, r3, r12}
    stmia   r1, {r2, r3, r12}
    bx      lr
}
// clang-format on
