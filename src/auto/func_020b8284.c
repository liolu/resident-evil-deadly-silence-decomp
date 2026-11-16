/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_0200d6d0(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */

void func_020b8284(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s16 arg4) {
    s32 var_r4;

    var_r4 = 0;
    if (arg2 > -1) {
        var_r4 |= 4;
    }
    if (arg3 > -1) {
        var_r4 |= 0x1000;
    }
    if (arg4 != 0) {
        var_r4 |= 0x10000;
    }
    func_0200d6d0(arg0, arg1, 0, var_r4, 0, 0, arg2, 0, arg3, (s32) arg4, 0);
}
