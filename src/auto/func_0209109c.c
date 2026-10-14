/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_0207544c(M2C_UNK, M2C_UNK);
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);
M2C_UNK func_02090c30(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

s32 func_0209109c(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_r4;

    if (arg2 & 7) {
        var_r4 = func_02090c30(arg0, arg1, arg2, 0);
    } else if (arg2 & 0x10) {
        var_r4 = func_0207544c(arg0, arg1);
        if ((var_r4 != 0) && (arg0 & 1)) {
            func_0207544c(arg0, arg1);
        }
    } else {
        var_r4 = func_02075738(arg0, arg1);
        if ((var_r4 != 0) && (arg0 & 1)) {
            func_02075738(arg0, arg1);
        }
    }
    return var_r4;
}
