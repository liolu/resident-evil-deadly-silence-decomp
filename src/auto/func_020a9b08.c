/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020a9a40(M2C_UNK);                     /* extern */
s32 func_020adcf8(M2C_UNK, M2C_UNK);                /* extern */

s32 func_020a9b08(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_r4;

    temp_r4 = func_020adcf8(arg1, arg2);
    func_020a9a40(arg0);
    return temp_r4;
}
