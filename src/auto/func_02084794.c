/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 *func_02088580(void);

s32 func_02084794(u8 *arg0, u32 arg1) {
    u8 *tbl;
    u8 v;
    s32 res;

    if (arg1 >= 32) {
        return 0;
    }
    tbl = func_02088580() + 0xFC;
    v   = tbl[arg1];
    res = 1;
    if (v != 255) {
        if (arg0[4] != v) {
            res = 0;
        }
    }
    return res;
}
