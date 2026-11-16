/* compiler: 1.2/sp2p3 */
#include "m2c.h"

s32 func_01ffb5d4(s32 *, u8);
extern void *data_027e000c;

s32 func_02002e14(void *arg0) {
    s32 vec[3];
    void *base;
    u8 temp_r5;
    s32 var_r4;
    u8 var_r5;

    base   = data_027e000c;
    var_r4 = 0;
    var_r5 = 3;
    vec[0] = M2C_FIELD(arg0, s32 *, 0) - M2C_FIELD(base, s32 *, 0x30);
    vec[1] = M2C_FIELD(arg0, s32 *, 4) - M2C_FIELD(base, s32 *, 0x34);
    vec[2] = M2C_FIELD(arg0, s32 *, 8) - M2C_FIELD(base, s32 *, 0x38);
    do {
        temp_r5 = var_r5;
        var_r4 |= func_01ffb5d4(vec, temp_r5);
        var_r5 = temp_r5 - 1;
    } while (temp_r5 != 0);
    return var_r4;
}
