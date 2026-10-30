/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0211851c(s16, M2C_UNK);                    /* extern */
extern M2C_UNK data_02137380;

void func_02047b5c(void *arg0) {
    M2C_UNK var_r1;
    s16 temp_r2;
    s32 var_r1_2;

    temp_r2 = M2C_FIELD(arg0, s16 *, 0x94);
    if ((s32) temp_r2 < 0) {
        M2C_FIELD(&data_02137380, s16 *, 2) = 9;
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 9) == 0x10) {
        var_r1 = 0x42;
    } else {
        var_r1 = 0x18;
    }
    var_r1_2 = func_0211851c(temp_r2, var_r1) + 1;
    if (var_r1_2 > 8) {
        var_r1_2 = 8;
    }
    M2C_FIELD(&data_02137380, s16 *, 2) = (s16) var_r1_2;
}
