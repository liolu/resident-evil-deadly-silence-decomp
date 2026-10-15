#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021375ac;

void func_02087e64(s32 arg0) {
    M2C_FIELD(&data_021375ac, s16 *, 0x2C) = (s16) arg0;
}
