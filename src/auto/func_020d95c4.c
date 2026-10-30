/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02117970(s32, s32);                    /* extern */
s32 func_02117dac();                                /* extern */
s32 func_02117e68(s32);                             /* extern */

u8 func_020d95c4(void *arg0, s32 arg1, void *arg2) {
    u32 temp_r4;
    u8 var_r0;

    temp_r4 = arg1 * 2;
    func_02117970(func_02117e68(M2C_FIELD(arg0, s32 *, 0)), 0x45800000);
    if (temp_r4 < (u32) (u16) (arg1 + (M2C_FIELD(arg2, s32 *, 0) - func_02117dac()))) {
        return 0U;
    }
    func_02117970(func_02117e68(M2C_FIELD(arg0, s32 *, 8)), 0x45800000);
    if (temp_r4 >= (u32) (u16) (arg1 + (M2C_FIELD(arg2, s32 *, 8) - func_02117dac()))) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return var_r0;
}
