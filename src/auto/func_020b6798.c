/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK *func_020b79d4(M2C_UNK);                    /* extern */
extern M2C_UNK data_0213bdcc;

M2C_UNK *func_020b6798(void) {
    M2C_UNK *temp_r4;
    s32 var_r0;

    var_r0 = M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & 0x20000;
    if (var_r0 != 0) {
        temp_r4 = func_020b79d4(1);
        var_r0  = (s32) func_020b79d4(0);
        if ((temp_r4 == NULL) && (var_r0 == 0)) {
            var_r0                                       = (s32) &data_0213bdcc;
            M2C_FIELD((s32) &data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD((s32) &data_0213bdcc, s32 *, 0x44) & ~0x20000);
        }
    }
    return (M2C_UNK *) var_r0;
}
