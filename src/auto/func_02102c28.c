/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_021054ac();                                /* extern */
M2C_UNK func_021054c0(s32);                         /* extern */
s32 func_021054d8();                                /* extern */
M2C_UNK func_021054ec(s32);                         /* extern */

s32 func_02102c28(s32 arg0, void *arg1, M2C_UNK (*arg2)(), s32 arg3) {
    s32 var_r4;

    if (arg0 != M2C_FIELD(arg1, u16 *, 4)) {
        return -2;
    }
    if (arg3 != 0) {
        var_r4 = func_021054d8();
    } else {
        var_r4 = func_021054ac();
    }
    M2C_FIELD(arg1, u16 *, 4) = 0U;
    if (arg2 != NULL) {
        arg2();
    }
    M2C_FIELD(arg1, s32 *, 0) = 0;
    if (arg3 != 0) {
        func_021054ec(var_r4);
    } else {
        func_021054c0(var_r4);
    }
    return 0;
}
