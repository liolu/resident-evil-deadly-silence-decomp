/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
s32 func_020ad804();                                /* extern */
extern M2C_UNK data_02144c34;

void func_02050404(void *arg0) {
    s16 temp_r1;
    s32 var_r1;

    temp_r1 = M2C_FIELD(arg0, s16 *, 0x180);
    if (temp_r1 != 0) {
        M2C_FIELD(arg0, s16 *, 0x180) = (s16) (temp_r1 - 1);
        return;
    }
    if (M2C_FIELD(arg0, u16 *, 0x18C) != 0) {
        var_r1 = 0xBB8;
    } else {
        var_r1 = 0x9C4;
    }
    if (((s32) M2C_FIELD(arg0, s32 *, 0x17C) <= var_r1) && (func_020ad804() != 0) &&
        (func_01ffd2c4(&data_02144c34, 0x400) == 0)) {
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
        M2C_FIELD(arg0, s8 *, 0xA)  = 4;
    }
}
