/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* FX_Sqrt from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_division.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned long long u64;
typedef unsigned short u16;
typedef int s32;
typedef volatile u16 vu16;
extern s32 func_020febc0(s32 value);
extern s32 func_020feaf4(void);
s32 func_020febc0(s32 value) {
    if (value > 0) {
        (*(vu16 *) 0x040002B0) = 1;
        (*(u64 *) 0x040002B8)  = (u64) value << 32;
        return func_020feaf4();
    }
    return 0;
}
s32 func_020feaf4(void);
