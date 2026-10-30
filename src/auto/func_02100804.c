/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02064f40 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/gx/g2.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef short s16;
typedef volatile u32 vu32;
typedef struct {
    s32 _00, _01, _10, _11;
} UnkMtx22;
void func_02100804(vu32 *reg, const UnkMtx22 *mtx, s32 centerX, s32 centerY, s32 x1, s32 y1) {
    s32 dx, dy, x, y;

    reg[0] = (u16) (s16) (mtx->_00 >> 4) | ((u16) (s16) (mtx->_01 >> 4) << 16);
    reg[1] = (u16) (s16) (mtx->_10 >> 4) | ((u16) (s16) (mtx->_11 >> 4) << 16);

    dx     = x1 - centerX;
    dy     = y1 - centerY;
    x      = mtx->_00 * dx + mtx->_01 * dy + (centerX << 12);
    y      = mtx->_10 * dx + mtx->_11 * dy + (centerY << 12);
    reg[2] = x >> 4;
    reg[3] = y >> 4;
}
