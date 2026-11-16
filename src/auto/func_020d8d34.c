/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d8e0c(s32);

s32 func_020d8d34(s32 arg0) {
    s32 i;
    u8 *p;

    i = 0;
    goto cond;
body:
    p = (u8 *) func_020d8e0c(i);
    if (p != 0) {
        if (*p == arg0) {
            return 1;
        }
    }
    i++;
cond:
    if ((u32) i < 4U) {
        goto body;
    }
    return 0;
}
