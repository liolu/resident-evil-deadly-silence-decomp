/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef int s32;
typedef volatile u32 vu32;
extern s32 func_021009f8(s32 *level);

/* func_020654e4 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/gx/g3x.c (license: none), reused by
 * tools/donor_match.py */
s32 func_021009f8(s32 *level) {
    if ((*(vu32 *) 0x04000600) & 0x4000) {
        return -1;
    }
    *level = ((*(vu32 *) 0x04000600) & 0x1f00) >> 8;
    return 0;
}
