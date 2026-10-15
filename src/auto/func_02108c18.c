#include "m2c.h"

extern M2C_UNK func_0210928c;
extern M2C_UNK func_021092b8;

s32 func_02108c18(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, M2C_UNK *arg6, M2C_UNK *arg7) {
    M2C_UNK *var_r1;
    M2C_UNK *var_r2;

    M2C_FIELD(arg0, volatile s32 *, 0x1C) = arg1;
    M2C_FIELD(arg0, volatile s32 *, 0x24) = arg3;
    M2C_FIELD(arg0, volatile s32 *, 0x30) = arg2;
    M2C_FIELD(arg0, volatile s32 *, 0x20) = (s32) M2C_FIELD(arg0, volatile s32 *, 0x30);
    M2C_FIELD(arg0, volatile s32 *, 0x2C) = arg5;
    var_r2                                = arg6;
    M2C_FIELD(arg0, volatile s32 *, 0x34) = arg4;
    M2C_FIELD(arg0, volatile s32 *, 0x28) = (s32) M2C_FIELD(arg0, volatile s32 *, 0x34);
    if (var_r2 == NULL) {
        var_r2 = &func_021092b8;
    }
    var_r1                            = arg7;
    M2C_FIELD(arg0, M2C_UNK **, 0x3C) = var_r2;
    if (var_r1 == NULL) {
        var_r1 = &func_0210928c;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x40)     = var_r1;
    M2C_FIELD(arg0, M2C_UNK **, 0x44)     = (M2C_UNK *) M2C_FIELD(arg0, M2C_UNK **, 0x3C);
    M2C_FIELD(arg0, volatile s32 *, 0x38) = 0;
    M2C_FIELD(arg0, volatile s32 *, 0x10) = (s32) (M2C_FIELD(arg0, volatile s32 *, 0x10) | 2);
    return 1;
}
