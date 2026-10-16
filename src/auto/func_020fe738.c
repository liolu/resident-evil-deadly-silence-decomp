/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02062740 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_mtx44.c (license: none), reused by
 * tools/donor_match.py */
typedef int s32;
typedef struct {
    s32 _00, _01, _02, _03;
    s32 _10, _11, _12, _13;
    s32 _20, _21, _22, _23;
    s32 _30, _31, _32, _33;
} Mtx44;
extern void func_020fe738(Mtx44 *m);
// clang-format off
asm void func_020fe738(register Mtx44* m) {
    mov     r2, #0x1000
    mov     r3, #0
    stmia   r0!, {r2, r3}
    mov     r1, #0
    stmia   r0!, {r1, r3}
    stmia   r0!, {r1, r2, r3}
    stmia   r0!, {r1, r3}
    stmia   r0!, {r1, r2, r3}
    stmia   r0!, {r1, r3}
    stmia   r0!, {r1, r2}
    bx      lr
}
// clang-format on
