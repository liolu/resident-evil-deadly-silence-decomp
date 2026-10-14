/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void func_020ff1bc(s16 *arg0, s32 arg1) {
    if (arg1 == 0) {
        *arg0 = 0;
        return;
    }
    if (arg1 > 0) {
        *arg0 = arg1 | 0x4000;
        return;
    }
    *arg0 = (0 - arg1) | 0x8000;
}
