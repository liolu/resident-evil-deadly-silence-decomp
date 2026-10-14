/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02013444(M2C_UNK);
M2C_UNK func_020134a0(M2C_UNK);

extern M2C_UNK data_0213ae4c;

void func_020134fc(s32 arg0) {
    s8 temp_r0;
    s8 var_r2;

    temp_r0 = M2C_FIELD(arg0, s8 *, 7);
    var_r2 = -1;
    if (temp_r0 == 0) {
        var_r2 = (s8) func_020134a0(M2C_FIELD(arg0, s32 *, 8));
    } else if (temp_r0 == 1) {
        var_r2 = (s8) func_02013444(M2C_FIELD(arg0, s32 *, 8));
    }
    M2C_FIELD(arg0, s8 *, 0) = var_r2;
    M2C_FIELD(arg0, s8 *, 1) = -1;
    M2C_FIELD(arg0, s8 *, 2) = -1;
    if (M2C_FIELD(&data_0213ae4c, u8 *, 2) != 0) {
        if (var_r2 != -1) {
            M2C_FIELD(arg0, s8 *, 1) = var_r2;
            if (M2C_FIELD(arg0, s8 *, 4) == var_r2) {
                M2C_FIELD(arg0, s8 *, 2) = var_r2;
                M2C_FIELD(arg0, u8 *, 5) = 0xFAU;
            } else {
                M2C_FIELD(arg0, s8 *, 4) = var_r2;
                M2C_FIELD(arg0, u8 *, 5) = 0U;
            }
        } else {
            M2C_FIELD(arg0, s8 *, 4) = -1;
        }
    }
    M2C_FIELD(arg0, u8 *, 5) = (u8) (M2C_FIELD(arg0, u8 *, 5) + 1);
    if ((u32) M2C_FIELD(&data_0213ae4c, u8 *, 3) < (u32) M2C_FIELD(arg0, u8 *, 5)) {
        M2C_FIELD(arg0, u8 *, 5) = 0xFAU;
        M2C_FIELD(arg0, s8 *, 4) = -1;
    }
}
