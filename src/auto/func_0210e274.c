/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_021046b8(u16 *, s32);                  /* extern */
M2C_UNK func_021061d8(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_0210626c(s32, void *, M2C_UNK);        /* extern */
s32 func_0210d814(M2C_UNK, M2C_UNK);                /* extern */
void *func_0210d934();                              /* extern */
s32 func_0210d944(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_0210da98(M2C_UNK, M2C_UNK);            /* extern */

s32 func_0210e274(M2C_UNK arg0, u16 *arg1, s32 arg2, s32 arg3, u16 arg4) {
    s32 temp_r0;
    s32 var_r0;
    void *temp_r4;

    temp_r0 = func_0210d814(1, 2);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    if (arg1 == NULL) {
        return 6;
    }
    func_021046b8(arg1, *arg1 * 2);
    func_0210da98(0xC, arg0);
    temp_r4                       = M2C_FIELD(func_0210d934(), void **, 0xC);
    M2C_FIELD(temp_r4, s16 *, 0)  = 0xC;
    M2C_FIELD(temp_r4, u16 **, 4) = arg1;
    if (arg2 != 0) {
        func_0210626c(arg2, temp_r4 + 8, 0x18);
    } else {
        func_021061d8(temp_r4 + 8, 0, 0x18);
    }
    M2C_FIELD(temp_r4, s32 *, 0x20) = arg3;
    M2C_FIELD(temp_r4, u16 *, 0x26) = arg4;
    var_r0                          = func_0210d944(0xC, 0);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}
