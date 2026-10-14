/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020e3bac(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_020e4254();                            /* extern */
M2C_UNK func_020e4260();                            /* extern */

s32 func_020e3c60(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r4;

    func_020e4260();
    temp_r4 = func_020e3bac(arg0, arg1);
    func_020e4254();
    return temp_r4;
}
