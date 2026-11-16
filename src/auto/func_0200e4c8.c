/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s16 func_0200e408(u16, s32, s32);

void func_0200e4c8(u16 *arg0, s32 arg1, s16 *arg2, s32 arg3, s32 arg4) {
    u16 *src;
    s16 *dst;
    s32 n;

    src = arg0;
    dst = arg2;
    n   = arg4;
    goto cond;
body:
    *dst = func_0200e408(*src, arg1, arg3);
    src += 1;
    dst += 1;
cond:
    if (n-- != 0) {
        goto body;
    }
}
