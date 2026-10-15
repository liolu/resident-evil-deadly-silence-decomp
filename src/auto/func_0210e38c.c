/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0210d814(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void *func_0210d934();                              /* extern */
s32 func_0210d944(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_0210da98(M2C_UNK, M2C_UNK);            /* extern */

s32 func_0210e38c(M2C_UNK arg0, void *arg1) {
    s32 temp_r0;
    s32 var_r0;
    u16 temp_r0_2;
    void *temp_r3;

    temp_r0 = func_0210d814(3, 2, 3, 5);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if (arg1 == NULL) {
        return 6;
    }
    if (M2C_FIELD(arg1, s32 *, 0) == 0) {
        return 6;
    }
    temp_r0_2 = M2C_FIELD(arg1, u16 *, 4);
    if (((u32) temp_r0_2 < 1U) || ((u32) temp_r0_2 > 0xEU)) {
        return 6;
    }
    func_0210da98(0xA, arg0);
    temp_r3                       = M2C_FIELD(func_0210d934(), void **, 0xC);
    M2C_FIELD(temp_r3, s16 *, 0)  = 0xA;
    M2C_FIELD(temp_r3, u16 *, 2)  = (u16) M2C_FIELD(arg1, u16 *, 4);
    M2C_FIELD(temp_r3, s32 *, 4)  = (s32) M2C_FIELD(arg1, s32 *, 0);
    M2C_FIELD(temp_r3, u16 *, 8)  = (u16) M2C_FIELD(arg1, u16 *, 6);
    M2C_FIELD(temp_r3, u8 *, 0xA) = (u8) M2C_FIELD(arg1, u8 *, 8);
    M2C_FIELD(temp_r3, u8 *, 0xB) = (u8) M2C_FIELD(arg1, u8 *, 9);
    M2C_FIELD(temp_r3, u8 *, 0xC) = (u8) M2C_FIELD(arg1, u8 *, 0xA);
    M2C_FIELD(temp_r3, u8 *, 0xD) = (u8) M2C_FIELD(arg1, u8 *, 0xB);
    M2C_FIELD(temp_r3, u8 *, 0xE) = (u8) M2C_FIELD(arg1, u8 *, 0xC);
    M2C_FIELD(temp_r3, u8 *, 0xF) = (u8) M2C_FIELD(arg1, u8 *, 0xD);
    var_r0                        = func_0210d944(0xA, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}
