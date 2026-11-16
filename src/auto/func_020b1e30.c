/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 *data_021225c0[];

u8 func_020b1e30(s32 arg0, u32 arg1) {
    u8 *p;

    p = data_021225c0[arg0];
    goto cond;
body:
    if (p[0] == arg1) {
        return p[1];
    }
    p += 2;
cond:
    if (p[0] <= arg1) {
        goto body;
    }
    return 0;
}
