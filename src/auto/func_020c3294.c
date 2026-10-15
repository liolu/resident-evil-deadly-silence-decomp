#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c3294(s32 arg0) {
    M2C_FIELD(&data_0213b890, s8 *, 0x54) = (s8) arg0;
    M2C_FIELD(&data_0213b890, s8 *, 0x55) = 0;
    M2C_FIELD(&data_0213b890, s8 *, 0x56) = 0;
    M2C_FIELD(&data_0213b890, s8 *, 0x57) = 0;
}
