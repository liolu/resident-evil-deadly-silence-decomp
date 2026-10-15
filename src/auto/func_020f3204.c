#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_02127a84;

void func_020f3204(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, M2C_UNK **, 0)       = &data_02127a84;
    M2C_FIELD(arg0, volatile s32 *, 4)   = arg1;
    M2C_FIELD(arg0, volatile s32 *, 8)   = arg2;
    M2C_FIELD(arg0, volatile s32 *, 0xC) = 0;
}
