/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e8798(s32, s32);                    /* extern */

void func_020e73a8(void *arg0, s32 arg1, s32 arg2) {
    s32 var_r2;
    void *temp_r1;

    var_r2 = arg2;
    if (arg0 == NULL) {
        return;
    }
    if (arg1 >= (s32) M2C_FIELD(arg0, s8 *, 2)) {
        return;
    }
    if (var_r2 >= 0xF) {
        var_r2 = 0xF;
    }
    if (var_r2 <= -0xF) {
        var_r2 = -0xF;
    }
    temp_r1 = arg0 + (arg1 * 4);
    M2C_FIELD(temp_r1, s32 *, 0x40) = var_r2;
    func_020e8798(M2C_FIELD(temp_r1, s32 *, 0x48), M2C_FIELD(temp_r1, s32 *, 0x40));
}
