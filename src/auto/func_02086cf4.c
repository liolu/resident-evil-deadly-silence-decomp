/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020fef24(M2C_UNK, M2C_UNK, M2C_UNK);

void func_02086cf4(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    s32 var_r2;

    func_020fef24(arg1, arg2, arg0);
    var_r2  = M2C_FIELD(arg1, s32 *, 0) - M2C_FIELD(arg1, s32 *, 0xC);
    temp_r0 = M2C_FIELD(arg2, s32 *, 0) - M2C_FIELD(arg2, s32 *, 0xC);
    if (var_r2 > temp_r0) {
        var_r2 = temp_r0;
    }
    M2C_FIELD(arg0, s32 *, 0) = var_r2;
    M2C_FIELD(arg0, s32 *, 4) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 4) >> 1);
    M2C_FIELD(arg0, s32 *, 8) = (s32) ((s32) M2C_FIELD(arg0, s32 *, 8) >> 1);
}
