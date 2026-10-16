/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02061f80 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_mtx43.c (license: none), reused by
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
extern void func_020fe05c(const Mtx43 *src, Mtx44 *dst);
// clang-format off
asm void func_020fe05c(register const Mtx43* src, register Mtx44* dst) {
    stmdb   sp!, {r4}
    mov     r12, #0
    ldmia   r0!, {r2-r4}
    stmia   r1!, {r2-r4, r12}
    ldmia   r0!, {r2-r4}
    stmia   r1!, {r2-r4, r12}
    ldmia   r0!, {r2-r4}
    stmia   r1!, {r2-r4, r12}
    mov     r12, #0x1000
    ldmia   r0!, {r2-r4}
    stmia   r1!, {r2-r4, r12}
    ldmia   sp!, {r4}
    bx      lr
}
// clang-format on
