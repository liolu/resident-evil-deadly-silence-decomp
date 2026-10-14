/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e038c();                            /* extern */
M2C_UNK func_020e0398();                            /* extern */
s32 func_020e0cb8(M2C_UNK);                         /* extern */

s32 func_020e0ce8(M2C_UNK arg0) {
    s32 temp_r4;

    func_020e0398();
    temp_r4 = func_020e0cb8(arg0);
    func_020e038c();
    return temp_r4;
}
