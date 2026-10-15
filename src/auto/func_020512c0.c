/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0205126c(s32, s32, s32, s32, s32);     /* extern */
M2C_UNK func_020559cc(void *, u32);                 /* extern */
s32 func_0211851c(s32, M2C_UNK);                    /* extern */
extern void *data_027e000c;

void func_020512c0(s32 arg0, s32 arg1, u32 arg2) {
    u32 var_r2;
    u8 temp_r0;
    void *temp_r4;
    void *temp_r4_2;

    var_r2  = arg2;
    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0xA1);
    if ((var_r2 == 2) && (temp_r0 == 1)) {
        var_r2 = 3;
    } else if ((var_r2 == 3) && (temp_r0 == 3)) {
        var_r2 = 2;
    }
    M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
    if (var_r2 > 5U) {
        var_r2 = 1;
    }
    func_020559cc(data_027e000c, var_r2);
    temp_r4 = data_027e000c;
    M2C_FIELD(temp_r4, s32 *, 0x17C) =
        func_0211851c(((M2C_FIELD(temp_r4, s32 *, 0xB0) + arg0) - M2C_FIELD(temp_r4, s32 *, 0x30)) << 0x10, 0xF);
    temp_r4_2 = data_027e000c;
    M2C_FIELD(temp_r4_2, s32 *, 0x180) =
        func_0211851c(((M2C_FIELD(temp_r4_2, s32 *, 0xB8) + arg1) - M2C_FIELD(temp_r4_2, s32 *, 0x38)) << 0x10, 0xF);
    func_0205126c(M2C_FIELD(data_027e000c, s32 *, 0x30), M2C_FIELD(data_027e000c, s32 *, 0x38),
                  M2C_FIELD(data_027e000c, s32 *, 0xB0) + arg0, M2C_FIELD(data_027e000c, s32 *, 0xB8) + arg1, 0xF);
}
