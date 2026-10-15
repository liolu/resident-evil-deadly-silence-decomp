/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_01ff9fd8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_02053c74(M2C_UNK);

void func_02049e50(s32 arg0) {
    s32 temp_r0_2;
    s32 var_r6;
    s32 var_r7;
    u32 var_r5;
    void *temp_r0;

    var_r7 = arg0;
    var_r6 = func_02053c74(arg0);
    var_r5 = 0;
    do {
        temp_r0   = (void *) func_02053c74(var_r6);
        temp_r0_2 = func_01ff9fd8(M2C_FIELD(temp_r0, s32 *, 0x30), M2C_FIELD(temp_r0, s32 *, 0x38),
                                  M2C_FIELD(var_r7, s32 *, 0x30), M2C_FIELD(var_r7, s32 *, 0x38));
        var_r5 += 1;
        var_r7                         = var_r6;
        M2C_FIELD(var_r6, s16 *, 0x44) = (s16) temp_r0_2;
        var_r6                         = (s32) temp_r0;
    } while (var_r5 < 8U);
}
