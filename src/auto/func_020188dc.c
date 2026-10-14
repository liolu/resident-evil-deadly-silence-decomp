/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0209109c(M2C_UNK, M2C_UNK, s32);       /* extern */
extern M2C_UNK data_0213ad48;

void func_020188dc(void *arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    s32 var_r3;

    var_r3 = arg3;
    if ((M2C_FIELD(arg0, u8 *, 0x90) == 1) && (((M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) && (M2C_FIELD(arg0, u8 *, 0x169) & 1)) || (M2C_FIELD(arg0, u8 *, 0x16B) == 2))) {
        var_r3 |= 0x10;
    }
    func_0209109c(arg1, arg2, var_r3);
}
