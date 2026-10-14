/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e038c();                            /* extern */
M2C_UNK func_020e0398();                            /* extern */
s32 func_020e03f8(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */

s32 func_020e0408(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_r4;

    func_020e0398();
    temp_r4 = func_020e03f8(arg0, arg1, arg2);
    func_020e038c();
    return temp_r4;
}
