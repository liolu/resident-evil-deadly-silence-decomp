/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020feda8(void *);
void func_020feef0(s32, void *, void *);

s32 func_0207ab34(s32 arg0, void *arg1) {
    s32 buf[4];
    s32 r;
    s32 lim;

    func_020feef0(arg0, arg1, buf);
    r   = func_020feda8(buf);
    lim = M2C_FIELD(arg1, s32 *, 0xC);
    if (r > lim) {
        return -1;
    }
    return lim - r;
}
