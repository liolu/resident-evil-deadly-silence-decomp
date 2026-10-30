/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020626a0 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_mtx43.c (license: none), reused by
 * tools/donor_match.py */
typedef long long s64;
typedef int s32;
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec;
typedef struct {
    s32 _00, _01, _02;
    s32 _10, _11, _12;
    s32 _20, _21, _22;
    s32 _30, _31, _32;
} Mtx43;
extern void func_020fe090(const Vec *vec, const Mtx43 *m, Vec *dst);
void func_020fe090(const Vec *vec, const Mtx43 *m, Vec *dst) {
    s32 x = vec->x;
    s32 y = vec->y;
    s32 z = vec->z;

    dst->x = (s32) (((s64) x * m->_00 + (s64) y * m->_10 + (s64) z * m->_20) >> 12);
    dst->x += m->_30;
    dst->y = (s32) (((s64) x * m->_01 + (s64) y * m->_11 + (s64) z * m->_21) >> 12);
    dst->y += m->_31;
    dst->z = (s32) (((s64) x * m->_02 + (s64) y * m->_12 + (s64) z * m->_22) >> 12);
    dst->z += m->_32;
}
