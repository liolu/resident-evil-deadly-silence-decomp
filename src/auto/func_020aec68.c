#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213aaf0;

void func_020aec68(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    M2C_FIELD(&data_0213aaf0, s16 *, 8)  = (s16) (arg0 | (arg1 << 5) | (arg2 << 0xA));
    M2C_FIELD(&data_0213aaf0, s8 *, 0xA) = (s8) arg3;
}
