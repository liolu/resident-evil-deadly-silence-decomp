/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0210469c(void *, M2C_UNK);             /* extern */
M2C_UNK func_021046b8(s32, s32);                    /* extern */
s32 func_0210d814(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
void *func_0210d934();                              /* extern */
s32 func_0210d944(M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, s32); /* extern */

s32 func_0210e818(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4, u16 arg5, u16 arg6) {
    s32 temp_r0;
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r7;
    u16 temp_r6;
    u16 var_r5;
    void *temp_r4;

    var_r5  = 1;
    temp_r4 = M2C_FIELD(func_0210d934(), void **, 4);
    temp_r0 = func_0210d814(2, 9, 0xA);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_0210469c(temp_r4 + 0x18E, 2);
    temp_r6 = M2C_FIELD(temp_r4, u16 *, 0x18E);
    func_0210469c(temp_r4 + 0x184, 2);
    if (M2C_FIELD(temp_r4, u16 *, 0x184) == 0) {
        var_r7 = 1;
    } else {
        var_r7 = 0;
    }
    if (var_r7 == 1) {
        func_0210469c(temp_r4 + 0x17E, 2);
        var_r5 = M2C_FIELD(temp_r4, u16 *, 0x17E);
        func_0210469c(temp_r4 + 0x86, 2);
    }
    if (arg2 == 0) {
        return 6;
    }
    if (var_r5 == 0) {
        return 7;
    }
    func_0210469c(temp_r4 + 0x50, 2);
    if (arg2 == M2C_FIELD(temp_r4, s32 *, 0x50)) {
        return 6;
    }
    if (var_r7 != 0) {
        var_r0_2 = 4;
    } else {
        var_r0_2 = 2;
    }
    if ((s32) (arg3 + var_r0_2) > (s32) temp_r6) {
        return 6;
    }
    if (arg3 == 0) {
        return 6;
    }
    func_021046b8(arg2, arg3);
    var_r0 = func_0210d944(0xF, 7, arg2, arg3, (s32) arg4, (s32) arg5, (s32) arg6, arg0, arg1);
    if (var_r0 == 0) {
        var_r0 = 2;
    }
    return var_r0;
}
