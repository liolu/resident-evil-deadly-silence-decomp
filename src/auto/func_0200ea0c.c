/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_01ff881c();                                /* extern */
extern M2C_UNK data_02143cc0;

s32 func_0200ea0c(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r2;

    var_r2 = arg2;
    if ((u32) (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xF) + 0xFF) > 1U) {
        var_r2 = func_01ff881c(arg0, arg1);
    }
    return var_r2;
}
