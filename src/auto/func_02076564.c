/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_0213b4cc[];

s32 func_02076564(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
    u8 *b;
    u8 *e;
    s32 cnt;
    s32 h;

    b = data_0213b4cc;
    if (b[0] >= 0x10) {
        return 0;
    }
    h                = b[1];
    e                = b + 4 + h * 20;
    *(s32 *) e       = arg0;
    *(s32 *) (e + 4) = arg1;
    *(s32 *) (e + 8) = arg2;
    *(s8 *) (e + 12) = arg3;
    cnt              = b[0];
    b[0]             = cnt + 1;
    h                = b[1];
    b[1]             = (h + 1) & 0xF;
    return 1;
}
