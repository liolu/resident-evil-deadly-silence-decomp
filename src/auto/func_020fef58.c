/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* FX_Atan2Idx from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fx/fx_atan.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned short u16;
typedef int s32;
typedef short s16;
typedef s32 BOOL;
extern s32 func_020fec4c(s32 numer, s32 denom);
extern const s16 data_0212bbf4[129];
u16 func_020fef58(s32 y, s32 x) {
    s32 a, b, c;
    BOOL positive;

    if (y > 0) {
        if (x > 0) {
            if (x > y) {
                a        = y;
                b        = x;
                c        = 0;
                positive = 1;
            } else if (x < y) {
                a        = x;
                b        = y;
                c        = 16384;
                positive = 0;
            } else {
                return 8192;
            }
        } else if (x < 0) {
            x = -x;
            if (x < y) {
                a        = x;
                b        = y;
                c        = 16384;
                positive = 1;
            } else if (x > y) {
                a        = y;
                b        = x;
                c        = 32768;
                positive = 0;
            } else {
                return 24576;
            }
        } else {
            return 16384;
        }
    } else if (y < 0) {
        y = -y;
        if (x < 0) {
            x = -x;
            if (x > y) {
                a        = y;
                b        = x;
                c        = -32768;
                positive = 1;
            } else if (x < y) {
                a        = x;
                b        = y;
                c        = -16384;
                positive = 0;
            } else {
                return -24576;
            }
        } else if (x > 0) {
            if (x < y) {
                a        = x;
                b        = y;
                c        = -16384;
                positive = 1;
            } else if (x > y) {
                a        = y;
                b        = x;
                c        = 0;
                positive = 0;
            } else {
                return -8192;
            }
        } else {
            return -16384;
        }
    } else {
        if (x >= 0) {
            return 0;
        } else {
            return 32768;
        }
    }

    if (b == 0) {
        return 0;
    }

    if (positive) {
        return (c + data_0212bbf4[func_020fec4c(a, b) >> 5]);
    } else {
        return (c - data_0212bbf4[func_020fec4c(a, b) >> 5]);
    }
}
