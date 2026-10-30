/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020627a0 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_mtx44.c (license: none), reused by
 * tools/donor_match.py */
typedef long long s64;
typedef int s32;
typedef struct {
    s32 _00, _01, _02, _03;
    s32 _10, _11, _12, _13;
    s32 _20, _21, _22, _23;
    s32 _30, _31, _32, _33;
} Mtx44;
extern void func_020fe798(const Mtx44 *a, const Mtx44 *b, Mtx44 *ab);
void func_020fe798(const Mtx44 *a, const Mtx44 *b, Mtx44 *ab) {
    Mtx44 tmp;
    Mtx44 *m;
    s32 xa, ya, za, wa;
    s32 xb, yb, zb, wb;

    if (ab == b) {
        m = &tmp;
    } else {
        m = ab;
    }

    xa = a->_00;
    ya = a->_01;
    za = a->_02;
    wa = a->_03;

    m->_00 = (s32) (((s64) xa * b->_00 + (s64) ya * b->_10 + (s64) za * b->_20 + (s64) wa * b->_30) >> 12);
    m->_01 = (s32) (((s64) xa * b->_01 + (s64) ya * b->_11 + (s64) za * b->_21 + (s64) wa * b->_31) >> 12);
    m->_03 = (s32) (((s64) xa * b->_03 + (s64) ya * b->_13 + (s64) za * b->_23 + (s64) wa * b->_33) >> 12);

    xb = b->_02;
    yb = b->_12;
    zb = b->_22;
    wb = b->_32;

    m->_02 = (s32) (((s64) xa * xb + (s64) ya * yb + (s64) za * zb + (s64) wa * wb) >> 12);

    xa = a->_10;
    ya = a->_11;
    za = a->_12;
    wa = a->_13;

    m->_12 = (s32) (((s64) xa * xb + (s64) ya * yb + (s64) za * zb + (s64) wa * wb) >> 12);
    m->_11 = (s32) (((s64) xa * b->_01 + (s64) ya * b->_11 + (s64) za * b->_21 + (s64) wa * b->_31) >> 12);
    m->_13 = (s32) (((s64) xa * b->_03 + (s64) ya * b->_13 + (s64) za * b->_23 + (s64) wa * b->_33) >> 12);

    xb = b->_00;
    yb = b->_10;
    zb = b->_20;
    wb = b->_30;

    m->_10 = (s32) (((s64) xa * xb + (s64) ya * yb + (s64) za * zb + (s64) wa * wb) >> 12);

    xa = a->_20;
    ya = a->_21;
    za = a->_22;
    wa = a->_23;

    m->_20 = (s32) (((s64) xa * xb + (s64) ya * yb + (s64) za * zb + (s64) wa * wb) >> 12);
    m->_21 = (s32) (((s64) xa * b->_01 + (s64) ya * b->_11 + (s64) za * b->_21 + (s64) wa * b->_31) >> 12);
    m->_23 = (s32) (((s64) xa * b->_03 + (s64) ya * b->_13 + (s64) za * b->_23 + (s64) wa * b->_33) >> 12);

    xb = b->_02;
    yb = b->_12;
    zb = b->_22;
    wb = b->_32;

    m->_22 = (s32) (((s64) xa * xb + (s64) ya * yb + (s64) za * zb + (s64) wa * wb) >> 12);

    xa = a->_30;
    ya = a->_31;
    za = a->_32;
    wa = a->_33;

    m->_32 = (s32) (((s64) xa * xb + (s64) ya * yb + (s64) za * zb + (s64) wa * wb) >> 12);
    m->_31 = (s32) (((s64) xa * b->_01 + (s64) ya * b->_11 + (s64) za * b->_21 + (s64) wa * b->_31) >> 12);
    m->_30 = (s32) (((s64) xa * b->_00 + (s64) ya * b->_10 + (s64) za * b->_20 + (s64) wa * b->_30) >> 12);
    m->_33 = (s32) (((s64) xa * b->_03 + (s64) ya * b->_13 + (s64) za * b->_23 + (s64) wa * b->_33) >> 12);

    if (m == &tmp) {
        *ab = tmp;
    }
}
