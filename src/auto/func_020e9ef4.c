/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e9f4c(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_020ea0ac();                            /* extern */
extern M2C_UNK data_02131520;
extern s32 data_02154120;

s32 func_020e9ef4(M2C_UNK arg0, M2C_UNK arg1, s32 arg2) {
    if (data_02154120 == 0) {
        func_020ea0ac();
    }
    func_020e9f4c(&data_02131520, 6, arg0, arg1, arg2);
    return 0;
}
