#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c44c4(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(&data_0213b890, s32 *, 0x84) = arg0;
    M2C_FIELD(&data_0213b890, s32 *, 0x88) = arg1;
    M2C_FIELD(&data_0213b890, s32 *, 0x8C) = arg2;
}
