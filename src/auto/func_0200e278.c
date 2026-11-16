/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_02106728(s32, s32);
extern u32 *data_021372d4;

s32 func_0200e278(s32 arg0) {
    u32 *p;
    u32 v;

    p = data_021372d4;
    if (arg0 & *p) {
        return 0;
    }
    *p = *p | arg0;
    func_02106728(arg0, 0);
    return 1;
}
