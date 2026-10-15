#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021543a4;

void func_020f4c1c(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    M2C_FIELD(&data_021543a4, s32 *, 0x9C) =
        (s32) (arg5 | (arg0 | (arg1 * 0x10) | (arg2 << 6)) | (arg3 << 0x18) | (arg4 << 0x10));
}
