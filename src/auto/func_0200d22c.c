/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0200d28c(void *, M2C_UNK, u32, s32);       /* extern */

s32 func_0200d22c(void *arg0, u32 arg1, M2C_UNK arg2, u32 arg3, s32 arg4) {
    u32 temp_r1;
    u32 var_r3;
    void *temp_lr;
    void *temp_lr_2;

    var_r3    = arg3;
    temp_lr_2 = M2C_FIELD(arg0, void **, 0x80);
    if (arg1 >= (u32) M2C_FIELD(temp_lr_2, u32 *, 8)) {
        return -0xA;
    }
    temp_lr = temp_lr_2 + 0xC + (arg1 * 0x10);
    temp_r1 = M2C_FIELD(temp_lr, s32 *, 4) - arg4;
    if (var_r3 > temp_r1) {
        var_r3 = temp_r1;
    }
    return func_0200d28c(arg0 + 0x34, arg2, var_r3, M2C_FIELD(temp_lr, s32 *, 0) + arg4);
}
