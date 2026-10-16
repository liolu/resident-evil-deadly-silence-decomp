/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_0206276c from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_mtx44.c (license: none), reused by
 * tools/donor_match.py */
typedef int s32;
typedef struct {
    s32 _00, _01, _02;
    s32 _10, _11, _12;
    s32 _20, _21, _22;
    s32 _30, _31, _32;
} Mtx43;
typedef struct {
    s32 _00, _01, _02, _03;
    s32 _10, _11, _12, _13;
    s32 _20, _21, _22, _23;
    s32 _30, _31, _32, _33;
} Mtx44;
extern void func_020fe764(const Mtx44 *src, Mtx43 *dst);
// clang-format off
asm void func_020fe764(register const Mtx44* src, register Mtx43* dst) {
    ldmia   r0!, {r2-r3, r12}
    add     r0, r0, #4
    stmia   r1!, {r2-r3, r12}
    ldmia   r0!, {r2-r3, r12}
    add     r0, r0, #4
    stmia   r1!, {r2-r3, r12}
    ldmia   r0!, {r2-r3, r12}
    add     r0, r0, #4
    stmia   r1!, {r2-r3, r12}
    ldmia   r0!, {r2-r3, r12}
    add     r0, r0, #4
    stmia   r1!, {r2-r3, r12}
    bx      lr
}
// clang-format on
