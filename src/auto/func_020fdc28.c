/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* MTX_Concat22 from https://github.com/ntrtwl/NitroSDK libraries/fx/src/fx_mtx22.c (license: none), reused by
 * tools/donor_match.py */
typedef signed long s32;
typedef signed long long int s64;
typedef s32 fx32;
typedef s64 fx64;
typedef union {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
    };
    fx32 m[2][2];
    fx32 a[4];
} MtxFx22;
extern void func_020fdc28(const MtxFx22 *a, const MtxFx22 *b, MtxFx22 *ab);
void func_020fdc28(const MtxFx22 *a, const MtxFx22 *b, MtxFx22 *ab) {
    MtxFx22 tmp;
    MtxFx22 *p;

    register fx32 x, y;

    ((void) 0);
    ((void) 0);
    ((void) 0);

    if (ab == b) {
        p = &tmp;
    } else {
        p = ab;
    }

    x = a->_00;
    y = a->_01;

    p->_00 = (fx32) (((fx64) x * b->_00 + (fx64) y * b->_10) >> 12);
    p->_01 = (fx32) (((fx64) x * b->_01 + (fx64) y * b->_11) >> 12);

    x = a->_10;
    y = a->_11;

    p->_10 = (fx32) (((fx64) x * b->_00 + (fx64) y * b->_10) >> 12);
    p->_11 = (fx32) (((fx64) x * b->_01 + (fx64) y * b->_11) >> 12);

    if (p == &tmp) {
        *ab = tmp;
    }
}
