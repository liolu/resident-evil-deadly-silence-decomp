/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_021054ac(void);
void func_021054c0(M2C_UNK);
M2C_UNK func_021054d8(void);
void func_021054ec(M2C_UNK);
M2C_UNK func_021063ac(M2C_UNK, M2C_UNK);

s32 func_02102b98(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r0;
    s32 var_r5;

    if (arg3 != 0) {
        var_r5 = func_021054d8();
    } else {
        var_r5 = func_021054ac();
    }
    temp_r0 = func_021063ac(arg0, arg1);
    if (temp_r0 == 0) {
        if (arg2 != 0) {
            ((M2C_UNK (*)()) arg2)();
        }
        M2C_FIELD(arg1, s16 *, 4) = (s16) arg0;
    }
    if (arg3 != 0) {
        func_021054ec(var_r5);
    } else {
        func_021054c0(var_r5);
    }
    return temp_r0;
}
