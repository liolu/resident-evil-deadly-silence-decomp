/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 *func_020d8e0c(u32);
extern M2C_UNK data_0213caa0;
extern M2C_UNK data_0213d1a0;

u32 func_020d8d84(s32 arg0) {
    u32 var_r6;
    u32 var_r5;
    u8 *temp_r0;

    var_r5 = 0;
    if (M2C_FIELD(&data_0213caa0, u8 *, 0x704) == 0) {
        var_r6 = var_r5;
        goto cond;
    loop:
        temp_r0 = func_020d8e0c(var_r6);
        if (temp_r0 != NULL) {
            if (*temp_r0 != arg0) {
                return 0U;
            }
            var_r5 = 1;
            goto next;
        }
        if (M2C_FIELD(&data_0213d1a0, u16 *, 0x18) & (1 << var_r6)) {
            return 0U;
        }
    next:
        var_r6 += 1;
    cond:
        if (var_r6 < 4U) {
            goto loop;
        }
    }
    return var_r5;
}
