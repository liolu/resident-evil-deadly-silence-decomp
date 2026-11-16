/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_0200e408();

void func_0200e478(u16 *arg0, u16 *arg1, u16 *arg2, s32 arg3, s32 arg4) {
    s32 n;

    n = arg4;
    goto cond;
body:
    *arg2 = (u16) func_0200e408(*arg0, *arg1, arg3);
    arg0++;
    arg1++;
    arg2++;
cond:
    if (n-- != 0) {
        goto body;
    }
}
