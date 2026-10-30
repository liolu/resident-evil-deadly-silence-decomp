/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020d9650();                                /* extern */
extern s32 data_027e0004;
extern s32 data_027e0014;
extern s32 data_027e0020;

void func_0201c818(void *arg0) {
    s32 temp_r0;
    s32 var_r1;
    s32 var_r2;
    u8 temp_r2;
    void *temp_r3;

    var_r2 = M2C_FIELD(arg0, s16 *, 0x178) - M2C_FIELD(arg0, s32 *, 0x38);
    if (var_r2 < 0) {
        var_r2 = 0 - var_r2;
    }
    var_r1 = M2C_FIELD(arg0, s16 *, 0x176) - M2C_FIELD(arg0, s32 *, 0x30);
    if (var_r1 < 0) {
        var_r1 = 0 - var_r1;
    }
    data_027e0004 = var_r1 + var_r2;
    temp_r2       = M2C_FIELD(arg0, u8 *, 0x92);
    data_027e0020 = (s32) temp_r2;
    if (M2C_FIELD(arg0, s16 *, 0x180) == 0) {
        temp_r0       = func_020d9650();
        data_027e0014 = temp_r0;
        if ((temp_r0 >> 1) == 0) {
            temp_r3                      = arg0 + 0x17C;
            M2C_FIELD(temp_r3, s16 *, 4) = (s16) (M2C_FIELD(temp_r3, s16 *, 4) & 0xFFFE);
            M2C_FIELD(temp_r3, s16 *, 4) = (s16) (M2C_FIELD(temp_r3, s16 *, 4) | (data_027e0014 & 1));
        }
    } else {
        if (temp_r2 != 1) {
            M2C_FIELD(arg0, s8 *, 0x93) = 0;
            M2C_FIELD(arg0, s8 *, 0x98) = 3;
        }
        M2C_FIELD(arg0, u8 *, 0x92) = 1U;
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
    }
}
