/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020166c4 from https://github.com/Yokimitsuro/khdays-decomp libs/nitro/nns/calls/func_020166c4.c (license: CC0-1.0),
 * reused by tools/donor_match.py */
typedef signed long s32;
typedef long long s64;
typedef s32 fx32;
typedef s64 fx64;
typedef s64 fx64c;
typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;
typedef struct MtxFx44 {
    fx32 _00, _01, _02, _03;
    fx32 _10, _11, _12, _13;
    fx32 _20, _21, _22, _23;
    fx32 _30, _31, _32, _33;
} MtxFx44;
extern void func_020f47bc(int *px1, int *py1, int *px2, int *py2);
extern fx32 func_020fec4c(fx32 numerator, fx32 denominator);
extern const MtxFx44 *func_020f4820(void);
extern void func_020feb20(fx32 value);
extern fx64c func_020feb98(void);
static inline fx32 FX_Mul32x64c(fx32 x, fx64c y) {
    return (fx32) ((y * (fx64) x + 0x80000000LL) >> 32);
}
int func_0208af50(int px, int py, VecFx32 *pNear, VecFx32 *pFar) {
    int rval;
    int x1, y1, x2, y2;
    int dx, dy;
    fx32 x, y;
    const MtxFx44 *m;
    VecFx32 vNear, vFar;
    fx64c invWNear, invWFar;
    fx32 wNear, wFar;

    func_020f47bc(&x1, &y1, &x2, &y2);
    dx = x2 - x1;
    dy = y2 - y1;

    x = func_020fec4c((px - x1) << 12, dx << 12);
    y = func_020fec4c((py + y1 - 191) << 12, -dy << 12);

    if (x < 0 || y < 0 || x > 0x1000 || y > 0x1000) {
        rval = -1;
    } else {
        rval = 0;
    }

    x = (x - 0x800) * 2;
    y = (y - 0x800) * 2;

    m = func_020f4820();

    wNear = m->_33 + (fx32) (((fx64) x * m->_03 + (fx64) y * m->_13) >> 12);
    func_020feb20(wNear - m->_23);

    vNear.x = m->_30 + (fx32) (((fx64) x * m->_00 + (fx64) y * m->_10) >> 12);
    vNear.y = m->_31 + (fx32) (((fx64) x * m->_01 + (fx64) y * m->_11) >> 12);
    vNear.z = m->_32 + (fx32) (((fx64) x * m->_02 + (fx64) y * m->_12) >> 12);

    if (pFar) {
        vFar.x = vNear.x + m->_20;
        vFar.y = vNear.y + m->_21;
        vFar.z = vNear.z + m->_22;
        wFar   = wNear + m->_23;
    }

    vNear.x -= m->_20;
    vNear.y -= m->_21;
    vNear.z -= m->_22;

    invWNear = func_020feb98();
    if (pFar) {
        func_020feb20(wFar);
    }

    pNear->x = FX_Mul32x64c(vNear.x, invWNear);
    pNear->y = FX_Mul32x64c(vNear.y, invWNear);
    pNear->z = FX_Mul32x64c(vNear.z, invWNear);

    if (pFar) {
        invWFar = func_020feb98();

        pFar->x = FX_Mul32x64c(vFar.x, invWFar);
        pFar->y = FX_Mul32x64c(vFar.y, invWFar);
        pFar->z = FX_Mul32x64c(vFar.z, invWFar);
    }

    return rval;
}
