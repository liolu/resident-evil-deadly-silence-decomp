/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020623cc from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_mtx43.c (license: none), reused by
 * tools/donor_match.py */
typedef long long s64;
typedef int s32;
typedef struct {
    s32 _00, _01, _02;
    s32 _10, _11, _12;
    s32 _20, _21, _22;
    s32 _30, _31, _32;
} Mtx43;
extern void func_020fe144(const Mtx43 *a, const Mtx43 *b, Mtx43 *ab);
void func_020fe144(const Mtx43 *a, const Mtx43 *b, Mtx43 *ab) {
    Mtx43 tmp;
    Mtx43 *m;
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

    xb = b->_02;
    yb = b->_12;
    zb = b->_22;

    m->_22 = (s32) (((s64) xa * xb + (s64) ya * yb + (s64) za * zb) >> 12);

    xa = a->_30;
    ya = a->_31;
    za = a->_32;

    m->_32 = (s32) ((((s64) xa * xb + (s64) ya * yb + (s64) za * zb) >> 12) + b->_32);
    m->_31 = (s32) ((((s64) xa * b->_01 + (s64) ya * b->_11 + (s64) za * b->_21) >> 12) + b->_31);
    m->_30 = (s32) ((((s64) xa * b->_00 + (s64) ya * b->_10 + (s64) za * b->_20) >> 12) + b->_30);

    if (m == &tmp) {
        *ab = tmp;
    }
}
