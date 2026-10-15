#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021375ac;

void func_02087e38(s32 arg0, s32 arg1) {
    M2C_FIELD(&data_021375ac, s8 *, 1)   = (s8) arg0;
    M2C_FIELD(&data_021375ac, s8 *, 0xB) = (s8) arg1;
}
