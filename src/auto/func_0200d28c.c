/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02109344(void *a, void *b, s32 c);
s32 func_021093b0(void *a, s32 b, s32 c);

s32 func_0200d28c(void *arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 pos;
    s32 left;
    s32 chunk;
    s32 got;

    pos  = arg1;
    left = arg2 & 0xFFFFF;
    if (func_02109344(arg0, arg3, 0) == 0) {
        return -3;
    }
    goto check;
body:
    chunk = (left > 0x100) ? 0x100 : left;
    got   = func_021093b0(arg0, pos, chunk);
    if (got != chunk) {
        return -2;
    }
    pos += got;
    left -= got;
check:
    if (left > 0) {
        goto body;
    }
    return arg2;
}
