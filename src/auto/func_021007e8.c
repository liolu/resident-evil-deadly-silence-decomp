#include "engine.h"
#include "m2c.h"

void func_021007e8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    *(M2C_UNK *) arg0 = (s32) (arg1 | 0x40 | (arg2 << 8) | ((arg3 | (arg4 << 8)) << 0x10));
}
