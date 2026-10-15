#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_02056204(s32 arg0, s32 arg1) {
    M2C_FIELD(&data_0213b890, s8 *, 0x21)  = (s8) arg0;
    M2C_FIELD(&data_0213b890, s16 *, 0x26) = (s16) arg1;
    M2C_FIELD(&data_0213b890, s8 *, 0x24)  = 0;
}
