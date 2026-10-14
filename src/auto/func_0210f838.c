/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0210d814(M2C_UNK, M2C_UNK);                /* extern */
void *func_0210d934();                              /* extern */
s32 func_0210d944(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_0210da98(M2C_UNK, M2C_UNK);            /* extern */

s32 func_0210f838(M2C_UNK arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4) {
    s32 temp_r0;
    s32 var_r0;
    void *temp_r3;
    void *temp_r4;

    temp_r4 = func_0210d934();
    temp_r0 = func_0210d814(1, 2);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_0210da98(0x1E, arg0);
    temp_r3 = M2C_FIELD(temp_r4, void **, 0xC);
    M2C_FIELD(temp_r3, s16 *, 0) = 0x1E;
    M2C_FIELD(temp_r3, s16 *, 2) = arg1;
    M2C_FIELD(temp_r3, s16 *, 4) = arg2;
    M2C_FIELD(temp_r3, s16 *, 6) = arg3;
    M2C_FIELD(temp_r3, u16 *, 8) = arg4;
    var_r0 = func_0210d944(0x1E, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}
