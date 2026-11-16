/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02109838(u32 *);
s32 func_021094e8(u32 *, void *);
void func_021094a0(u32 *);

s32 func_020e4bac(void *arg0) {
    u32 loc[18];
    s32 r4;

    func_02109838(loc);
    if (func_021094e8(loc, arg0) != 0) {
        r4 = loc[9] - loc[8];
        func_021094a0(loc);
        return r4;
    }
    return 0;
}
