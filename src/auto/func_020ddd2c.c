/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020ddd2c(u8 *arg0, s32 arg1, s16 *arg2) {
    s32 idx;
    s32 ip;
    s32 lim;
    lim = arg1 - 1;
    ip  = 0x7FFFFFFF;
    idx = 0;
    if (lim > 0) {
    loop_1:
        if (*(u16 *) (arg0 + idx) == 0x80) {
            if (idx >= 0x7FFFFFFF) {
                idx = 0x7FFFFFFF;
            }
            ip = idx;
        } else {
            idx += 2;
            if (idx < lim) {
                goto loop_1;
            }
        }
    }
    if (ip != 0x7FFFFFFF) {
        *arg2 = (s16) ip;
        return 0;
    }
    *arg2 = 0;
    return -1;
}
