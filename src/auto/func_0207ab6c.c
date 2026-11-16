/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_020feda8(s32 *);
void func_020feef0(void *, void *, s32 *);
s32 func_0207ab6c(void *arg0, void *arg1) {
    s32 loc[3];
    s32 t0;
    s32 t1;
    s32 sum;
    s32 r;

    func_020feef0(arg0, arg1, loc);
    r   = func_020feda8(loc);
    t0  = *(s32 *) ((u8 *) arg0 + 12);
    t1  = *(s32 *) ((u8 *) arg1 + 12);
    sum = t0 + t1;
    if (r > sum) {
        return -1;
    }
    return sum - r;
}
