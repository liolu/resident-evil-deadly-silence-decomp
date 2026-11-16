/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02110048(void *, void *, s32);
void func_0210626c(void *, void *, s32);
extern u8 data_0213705c[];

u32 func_0200496c(u8 *arg0) {
    u32 found;
    u32 i;
    u8 *p;
    s32 t;

    found = 0;
    p     = arg0;
    i     = 0;
    while (i < 2) {
        t = func_02110048(data_0213705c, p, 6);
        if (t == *(u16 *) (p + 6)) {
            found = 1;
            func_0210626c(p, arg0, 8);
            break;
        }
        i++;
        p += 8;
    }
    return found;
}
