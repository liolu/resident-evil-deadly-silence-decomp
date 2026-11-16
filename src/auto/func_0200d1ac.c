/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_0200d22c(s32, u32, s32 *, s32, s32);

s32 func_0200d1ac(s32 arg0, s32 *arg1) {
    s32 buf[15];
    s32 r;

    r = func_0200d22c(arg0, (u32) (*arg1 << 8) >> 8, buf, 0x3C, 0);
    if ((u32) (r + 3) > 1U) {
        r = buf[14] * 8 + 0x3C;
    }
    return r;
}
