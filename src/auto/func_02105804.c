/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02105528();                            /* extern */

void func_02105804(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r1;
    u32 temp_r0;
    u32 temp_r0_2;

    var_r1 = arg1;
    if (arg0 != 0) {
        return;
    }
    temp_r0 = var_r1 & 0xFF000000;
    switch (arg3) {                                 /* irregular */
    case 0x800000:
        var_r1 -= arg2;
        break;
    case 0x0:
        var_r1 += arg2;
        break;
    }
    if ((temp_r0 != 0x04000000) && (temp_r0 < 0x08000000U)) {
        temp_r0_2 = var_r1 & 0xFF000000;
        if ((temp_r0_2 != 0x04000000) && (temp_r0_2 < 0x08000000U)) {
            return;
        }
    }
    func_02105528();
}
