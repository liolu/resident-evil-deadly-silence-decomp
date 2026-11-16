#include "m2c.h"

s32 func_020c4d64(u8 *arg0, u8 *arg1) {
    u32 i;
    u8 c;

    i = 0;
    goto cond;
body:
    c = arg0[i];
    if (c != arg1[i]) {
        return 1;
    }
    if (c == 0) {
        return 0;
    }
    i = (u8) (i + 1);
cond:
    if (i < 12) {
        goto body;
    }
    return 1;
}
