/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02061bac from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_mtx33.c (license: none), reused by
 * tools/donor_match.py */
typedef long long s64;
typedef int s32;
typedef struct {
    s32 _00, _01, _02;
    s32 _10, _11, _12;
    s32 _20, _21, _22;
} Mtx33;
extern void func_020fdf70(const Mtx33 *src, Mtx33 *dst, s32 x, s32 y, s32 z);
void func_020fdf70(const Mtx33 *src, Mtx33 *dst, s32 x, s32 y, s32 z) {
    dst->_00 = (s32) (((s64) x * src->_00) >> 12);
    dst->_01 = (s32) (((s64) x * src->_01) >> 12);
    dst->_02 = (s32) (((s64) x * src->_02) >> 12);

    dst->_10 = (s32) (((s64) y * src->_10) >> 12);
    dst->_11 = (s32) (((s64) y * src->_11) >> 12);
    dst->_12 = (s32) (((s64) y * src->_12) >> 12);

    dst->_20 = (s32) (((s64) z * src->_20) >> 12);
    dst->_21 = (s32) (((s64) z * src->_21) >> 12);
    dst->_22 = (s32) (((s64) z * src->_22) >> 12);
}
