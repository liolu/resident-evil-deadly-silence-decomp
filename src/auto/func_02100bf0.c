/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020652c0 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/gx/g3x.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef int s32;
typedef volatile u32 vu32;
extern void func_02100bf0(void);
extern s32 func_021009f8(s32 *level);
extern s32 func_021009cc(s32 *level);
void func_02100bf0(void) {
    s32 pvLevel, pjLevel;

    (*(vu32 *) 0x04000600) |= 0x8000;
    while (func_021009f8(&pvLevel)) {
    }
    while (func_021009cc(&pjLevel)) {
    }
    (*(vu32 *) 0x04000440) = 3;
    (*(vu32 *) 0x04000454) = 0;
    (*(vu32 *) 0x04000440) = 0;
    if (pjLevel != 0) {
        (*(vu32 *) 0x04000448) = pjLevel;
    }
    (*(vu32 *) 0x04000440) = 2;
    (*(vu32 *) 0x04000448) = pvLevel;
    (*(vu32 *) 0x04000454) = 0;
}
s32 func_021009f8(s32 *level);
s32 func_021009cc(s32 *level);
