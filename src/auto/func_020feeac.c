/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02062fcc from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_vec.c (license: none), reused by
 * tools/donor_match.py */
typedef long long s64;
typedef int s32;
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec;
extern s32 func_020feeac(const Vec *a, const Vec *b);
s32 func_020feeac(const Vec *a, const Vec *b) {
    return (s32) (((s64) a->x * b->x + (s64) a->y * b->y + (s64) a->z * b->z + (1 << 11)) >> 12);
}
