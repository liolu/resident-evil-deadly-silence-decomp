#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0214ccc0;

s32 func_02073b2c(void) {
    M2C_FIELD(&data_0214ccc0, s32 *, 0xF6C) = 0;
    return (s32) &data_0214ccc0;
}
