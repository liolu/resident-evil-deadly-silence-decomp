#include "m2c.h"

M2C_UNK func_0210694c(M2C_UNK, s16);                /* extern */
extern M2C_UNK data_0212bd68;

void func_0200e14c(M2C_UNK arg0, s32 arg1) {
    s32 var_r2;

    if (arg1 < 0) {
        var_r2 = 0;
    } else {
        var_r2 = arg1 & 0x7F;
    }
    func_0210694c(arg0, *((u16 *) ((s8 *) &data_0212bd68 + (var_r2 * 2))));
}
