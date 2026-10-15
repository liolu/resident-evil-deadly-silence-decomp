/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02110374(s32, M2C_UNK, s32);           /* extern */

s32 func_02110500(void *arg0, M2C_UNK arg1, s32 arg2) {
    s32 temp_r3;
    s32 var_r5;
    u32 temp_r2;

    temp_r3 = M2C_FIELD(arg0, s32 *, 8);
    var_r5  = arg2;
    temp_r2 = M2C_FIELD(arg0, u32 *, 4);
    if ((u32) (temp_r3 + var_r5) > temp_r2) {
        var_r5 = temp_r2 - temp_r3;
    }
    func_02110374(M2C_FIELD(arg0, s32 *, 0) + temp_r3, arg1, var_r5);
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) + var_r5);
    return 1;
}
