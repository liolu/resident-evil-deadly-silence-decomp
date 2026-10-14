/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0210d814(M2C_UNK, M2C_UNK);                /* extern */
s32 func_0210d944(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_0210da98(M2C_UNK, M2C_UNK);            /* extern */

s32 func_0210e4e8(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;
    s32 var_r0;

    temp_r0 = func_0210d814(1, 2);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_0210da98(8, arg0);
    var_r0 = func_0210d944(8, 1, arg1);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}
