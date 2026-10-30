/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0200e068(s32, s32, s32, M2C_UNK);          /* extern */
extern void *data_02137298;

s32 func_02007be8(void) {
    s32 temp_r1;
    s32 var_r0;
    s32 var_r1;
    s32 var_r2;
    void *temp_r3;

    temp_r3 = data_02137298 + 0x3E48;
    if (M2C_FIELD(data_02137298, s32 *, 0x3E48) == 0) {
        var_r1 = 1;
    } else {
        var_r1 = 0;
    }
    var_r0 = var_r1 & 2;
    if ((var_r0 == 0) && (var_r1 == 0)) {
        temp_r1 = M2C_FIELD(temp_r3, s32 *, 0x34);
        if (temp_r1 >= 0) {
            var_r2 = 1 << temp_r1;
        } else {
            var_r2 = 0;
        }
        var_r0 = func_0200e068(M2C_FIELD(temp_r3, s32 *, 0x2C), M2C_FIELD(temp_r3, s32 *, 0x30), var_r2, 0);
    }
    return var_r0;
}
