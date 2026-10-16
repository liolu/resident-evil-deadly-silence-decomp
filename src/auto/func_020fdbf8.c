/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02061b70 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_mtx22.c (license: none), reused by
 * tools/donor_match.py */
typedef int s32;
typedef struct {
    s32 _00, _01;
    s32 _10, _11;
} UnkMtx22;
extern void func_020fdbf8(UnkMtx22 *m);
// clang-format off
asm void func_020fdbf8(register UnkMtx22* m) {
    mov     r1, #0
    mov     r2, #0x1000
    mov     r3, #0
    stmia   r0!, {r2, r3}
    stmia   r0!, {r1, r2}
    bx      lr
}
// clang-format on
