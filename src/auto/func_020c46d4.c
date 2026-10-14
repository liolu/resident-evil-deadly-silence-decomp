#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b890;

void func_020c46d4(s32 arg0, s32 arg1) {
    M2C_FIELD(&data_0213b890, s8 *, 0x38) = (s8) arg0;
    M2C_FIELD(&data_0213b890, s32 *, 0x3C) = arg1;
}
