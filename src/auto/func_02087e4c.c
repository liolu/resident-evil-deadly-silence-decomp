#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_021375ac;

void func_02087e4c(s32 arg0) {
    M2C_FIELD(&data_021375ac, s16 *, 0x2E) = (s16) arg0;
    M2C_FIELD(&data_021375ac, s8 *, 4) = 0;
}
