#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_021375ac;

void func_020884e0(s32 arg0) {
    M2C_FIELD(&data_021375ac, s8 *, 0x10) = (s8) arg0;
}
