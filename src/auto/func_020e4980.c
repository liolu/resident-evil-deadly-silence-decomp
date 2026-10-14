/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020e48d0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020e4a9c();                            /* extern */
M2C_UNK func_020e4aac();                            /* extern */

s32 func_020e4980(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_r4;

    func_020e4aac();
    temp_r4 = func_020e48d0(arg0, arg1, arg2, arg3);
    func_020e4a9c();
    return temp_r4;
}
