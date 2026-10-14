/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e66c4();                            /* extern */
M2C_UNK func_020e66c8();                            /* extern */
s32 func_020e6a4c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */

s32 func_020e6b98(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3, s32 arg4) {
    s32 temp_r4;

    func_020e66c8();
    temp_r4 = func_020e6a4c(arg0, arg1, arg2, arg3, arg4);
    func_020e66c4();
    return temp_r4;
}
