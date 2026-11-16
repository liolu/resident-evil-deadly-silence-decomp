/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02008258(s32, s32);

s32 func_02008214(s32 arg0) {
    u32 i;
    s32 r;

    i = 0;
    goto cond;
body:
    r = func_02008258(i, arg0);
    if (r < 0) {
        return r;
    }
    i++;
cond:
    if (i < 4) {
        goto body;
    }
    return 0;
}
