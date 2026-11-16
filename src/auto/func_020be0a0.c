/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02074ef0();
extern M2C_UNK data_0213bdcc;

s32 func_020be0a0(s32 arg0) {
    s32 var_r4;
    u32 var_r2;

    var_r4 = 1;
    if (func_02074ef0() < 0) {
        var_r2 = 0;
        goto cond_4;
    body_4:
        if (arg0 == *(u8 *) ((u8 *) &data_0213bdcc + (var_r2 * 2) + 0x100)) {
            goto end_4;
        }
        var_r2 += 1;
    cond_4:
        if (var_r2 < 0x30U) {
            goto body_4;
        }
        var_r4 = 0;
    }
end_4:
    return var_r4;
}
