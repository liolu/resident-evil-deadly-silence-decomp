#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213e394;

void func_02092de8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(&data_0213e394, s16 *, 0x22) = (s16) arg0;
    M2C_FIELD(&data_0213e394, s16 *, 0x24) = (s16) arg1;
    M2C_FIELD(&data_0213e394, s16 *, 0x26) = (s16) arg2;
    M2C_FIELD(&data_0213e394, s16 *, 0x28) = (s16) arg3;
}
