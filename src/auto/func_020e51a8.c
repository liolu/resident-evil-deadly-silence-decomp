/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020e543c(s32, void *);
void func_020e531c(void *, void *);
s32 func_020e4bac(void *);

extern u8 data_02130a00;

s32 func_020e51a8(void *arg0) {
    u8 loc[0x204];
    s32 r;

    if (arg0 == NULL) {
        func_020e543c(0, &data_02130a00);
        return 0;
    }
    func_020e531c(loc, arg0);
    r = func_020e4bac(loc);
    if (r < 0) {
        return (s32) 0x7FFFF800;
    }
    return r;
}
