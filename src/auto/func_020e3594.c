/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020e3498(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020e4254();                            /* extern */
M2C_UNK func_020e4260();                            /* extern */

s32 func_020e3594(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s32 temp_r4;

    func_020e4260();
    temp_r4 = func_020e3498(arg0, arg1, arg2, arg3);
    func_020e4254();
    return temp_r4;
}
