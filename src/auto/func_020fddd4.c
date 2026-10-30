/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* MTX_Concat33 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_mtx33.c (license: none), reused by
 * tools/donor_match.py */
typedef long long s64;
typedef int s32;
typedef struct {
    s32 _00, _01, _02;
    s32 _10, _11, _12;
    s32 _20, _21, _22;
} Mtx33;
extern void func_020fddd4(const Mtx33 *a, const Mtx33 *b, Mtx33 *ab);
#pragma thumb off
void func_020fddd4(const Mtx33 *a, const Mtx33 *b, Mtx33 *ab) {
    Mtx33 tmp;
    Mtx33 *m;
    s32 xa, ya, za;
    s32 xb, yb, zb;

    if (ab == b) {
        m = &tmp;
    } else {
        m = ab;
    }

    xa = a->_00;
    ya = a->_01;
    za = a->_02;

    m->_00 = (s32) (((s64) xa * b->_00 + (s64) ya * b->_10 + (s64) za * b->_20) >> 12);
    m->_01 = (s32) (((s64) xa * b->_01 + (s64) ya * b->_11 + (s64) za * b->_21) >> 12);

    xb = b->_02;
    yb = b->_12;
    zb = b->_22;

    m->_02 = (s32) (((s64) xa * xb + (s64) ya * yb + (s64) za * zb) >> 12);

    xa = a->_10;
    ya = a->_11;
    za = a->_12;

    m->_12 = (s32) (((s64) xa * xb + (s64) ya * yb + (s64) za * zb) >> 12);
    m->_11 = (s32) (((s64) xa * b->_01 + (s64) ya * b->_11 + (s64) za * b->_21) >> 12);

    xb = b->_00;
    yb = b->_10;
    zb = b->_20;

    m->_10 = (s32) (((s64) xa * xb + (s64) ya * yb + (s64) za * zb) >> 12);

    xa = a->_20;
    ya = a->_21;
    za = a->_22;

    m->_20 = (s32) (((s64) xa * xb + (s64) ya * yb + (s64) za * zb) >> 12);
    m->_21 = (s32) (((s64) xa * b->_01 + (s64) ya * b->_11 + (s64) za * b->_21) >> 12);
    m->_22 = (s32) (((s64) xa * b->_02 + (s64) ya * b->_12 + (s64) za * b->_22) >> 12);

    if (m == &tmp) {
        *ab = tmp;
    }
}
