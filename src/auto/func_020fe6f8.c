/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02061fb4 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_mtx43.c (license: none), reused by
 * tools/donor_match.py */
typedef int s32;
typedef struct {
    s32 _00, _01, _02;
    s32 _10, _11, _12;
    s32 _20, _21, _22;
} Mtx33;
typedef struct {
    s32 _00, _01, _02;
    s32 _10, _11, _12;
    s32 _20, _21, _22;
    s32 _30, _31, _32;
} Mtx43;
extern void func_020fdf70(const Mtx33 *src, Mtx33 *dst, s32 x, s32 y, s32 z);
extern void func_020fe6f8(const Mtx43 *src, Mtx43 *dst, s32 x, s32 y, s32 z);
void func_020fe6f8(const Mtx43 *src, Mtx43 *dst, s32 x, s32 y, s32 z) {
    func_020fdf70((const Mtx33 *) src, (Mtx33 *) dst, x, y, z);
    dst->_30 = src->_30;
    dst->_31 = src->_31;
    dst->_32 = src->_32;
}
