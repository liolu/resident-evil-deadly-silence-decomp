/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e038c();                            /* extern */
M2C_UNK func_020e0398();                            /* extern */
s32 func_020e0d8c(M2C_UNK, M2C_UNK);                /* extern */

s32 func_020e0da8(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r4;

    func_020e0398();
    temp_r4 = func_020e0d8c(arg0, arg1);
    func_020e038c();
    return temp_r4;
}
