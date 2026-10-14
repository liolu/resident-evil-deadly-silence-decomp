/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020e54e8(s32);                             /* extern */
s32 func_020e5c04();                                /* extern */
M2C_UNK func_02110440(M2C_UNK, M2C_UNK *, s32, M2C_UNK *); /* extern */
M2C_UNK func_02112754(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK data_02130a60;
extern M2C_UNK data_02152ce4;

void func_020e5480(s32 arg0, M2C_UNK arg1) {
    s32 var_r5;

    var_r5 = arg0;
    if (var_r5 == 0) {
        var_r5 = func_020e5c04();
    }
    if (func_020e54e8(var_r5) != 1) {
        return;
    }
    func_02112754(&data_02152ce4, arg1);
    func_02110440(arg1, &data_02130a60, var_r5, &data_02152ce4);
}
