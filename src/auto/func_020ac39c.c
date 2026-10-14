/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02059ab0(M2C_UNK *);                       /* extern */
s32 func_02075738(M2C_UNK, M2C_UNK);                /* extern */
s32 func_02090fc4(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_020adf5c(M2C_UNK);                     /* extern */
extern M2C_UNK data_02144c04;

s32 func_020ac39c(M2C_UNK arg0, M2C_UNK arg1) {
    s32 var_r4;

    if (func_02059ab0(&data_02144c04) != 0) {
        var_r4 = func_02090fc4(arg0, arg1, 7);
    } else {
        var_r4 = func_02075738(arg0, arg1);
    }
    func_020adf5c(0);
    return var_r4;
}
