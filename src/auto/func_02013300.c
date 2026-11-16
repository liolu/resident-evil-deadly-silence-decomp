/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_0213ae4c;

s32 func_02013300(s32 arg0, s32 arg1, s32 arg2) {
    u16 hx;
    u16 hy;
    s32 dx;
    s32 dy;

    if (M2C_FIELD(&data_0213ae4c, u16 *, 8) != 1) {
        return 0;
    }
    hx = M2C_FIELD(&data_0213ae4c, u16 *, 4);
    hy = M2C_FIELD(&data_0213ae4c, u16 *, 6);
    dx = hx - arg0;
    dy = hy - arg1;
    if ((u32) ((dx * dx) + (dy * dy)) <= (u32) (arg2 * arg2)) {
        return 1;
    }
    return 0;
}
