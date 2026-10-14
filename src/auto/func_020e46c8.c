#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_021525a0;

void func_020e46c8(s32 arg0, s32 arg1) {
    M2C_FIELD(&data_021525a0, volatile s32 *, 0) = arg0;
    M2C_FIELD(&data_021525a0, volatile s32 *, 4) = arg1;
}
