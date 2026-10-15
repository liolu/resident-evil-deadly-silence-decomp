/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02052114(s32, s32, s32, s32, s32);     /* extern */
M2C_UNK func_020559cc(void *, u32);                 /* extern */
extern void *data_027e000c;

void func_02052188(s32 arg0, s32 arg1, u32 arg2) {
    u32 var_r1;
    u32 var_r4;
    u8 temp_r1;

    var_r4  = arg2;
    temp_r1 = M2C_FIELD(data_027e000c, u8 *, 0xA1);
    if ((var_r4 == 2) && (temp_r1 == 1)) {
        var_r4 = 3;
    } else if ((var_r4 == 3) && (temp_r1 == 3)) {
        var_r4 = 2;
    }
    var_r1 = var_r4;
    if (var_r4 > 6U) {
        var_r1 = 3;
    }
    func_020559cc(data_027e000c, var_r1);
    M2C_FIELD(data_027e000c, u8 *, 0xA1) = (u8) var_r4;
    M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
    func_02052114(M2C_FIELD(data_027e000c, s32 *, 0x30), M2C_FIELD(data_027e000c, s32 *, 0x38),
                  M2C_FIELD(data_027e000c, s32 *, 0xB0) + arg0, M2C_FIELD(data_027e000c, s32 *, 0xB8) + arg1, 0xF);
}
