#include "m2c.h"
#include "engine.h"

void func_020c3bd0(M2C_UNK, M2C_UNK);

void func_020c3c0c(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(arg0, s32 *, 0x28) = arg1;
    M2C_FIELD(arg0, s32 *, 0x2C) = arg2;
    func_020c3bd0(arg0, arg3);
}
