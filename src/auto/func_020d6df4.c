#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02141cc0;

void func_020d6df4(s32 arg0) {
    M2C_FIELD(&data_02141cc0, s32 *, 0x4C) = arg0;
}
