/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02061b88 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_mtx33.c (license: none), reused by
 * tools/donor_match.py */
typedef int s32;
typedef struct {
    s32 _00, _01, _02;
    s32 _10, _11, _12;
    s32 _20, _21, _22;
} Mtx33;
extern void func_020fdcdc(Mtx33 *m);
// clang-format off
asm void func_020fdcdc(register Mtx33* m) {
    mov     r2, #0x1000
    str     r2, [r0, #0x20]
    mov     r3, #0
    stmia   r0!, {r2, r3}
    mov     r1, #0
    stmia   r0!, {r1, r3}
    stmia   r0!, {r2, r3}
    stmia   r0!, {r1, r3}
    bx      lr
}
// clang-format on
