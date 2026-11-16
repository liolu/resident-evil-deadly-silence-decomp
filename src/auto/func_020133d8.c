/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_0213ae4c;

s16 func_020133d8(void) {
    s32 i;
    u8 *base;
    u8 *p;
    s8 v;

    i = 0;
    goto check;
body:
    p = (u8 *) &data_0213ae4c + i * 12;
    if (M2C_FIELD(p, s32 *, 0x1C) != 0) {
        v = M2C_FIELD(p, s8 *, 0x14);
        if (v > -1) {
            return (s16) (v | (i << 8));
        }
    }
    i = (s8) (i + 1);
check:
    if (i < 4) {
        goto body;
    }
    return -1;
}
