#include "m2c.h"

M2C_UNK func_021066c8(M2C_UNK, s32);                /* extern */

void func_0200e098(M2C_UNK arg0, s32 arg1) {
    s32 var_r1;

    if (arg1 < 0) {
        var_r1 = 0;
    } else {
        var_r1 = arg1 & 0x7F;
    }
    func_021066c8(arg0, var_r1);
}
