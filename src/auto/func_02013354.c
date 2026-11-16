/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_0213ae4c;

s32 func_02013354(s32 arg0, s32 arg1, u32 arg2, u32 arg3) {
    u16 hx;
    u16 hy;
    u32 dx;
    u32 dy;

    if (M2C_FIELD(&data_0213ae4c, u16 *, 8) != 1) {
        return 0;
    }
    hx = M2C_FIELD(&data_0213ae4c, u16 *, 4);
    hy = M2C_FIELD(&data_0213ae4c, u16 *, 6);
    dx = (u32) (hx - arg0);
    dy = (u32) (hy - arg1);
    if (dx < arg2 && dy < arg3) {
        return 1;
    }
    return 0;
}
