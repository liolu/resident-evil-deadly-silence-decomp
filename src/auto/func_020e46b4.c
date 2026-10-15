#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_02152590;

void func_020e46b4(s32 arg0, s32 arg1) {
    M2C_FIELD(&data_02152590, volatile s32 *, 0) = arg0;
    M2C_FIELD(&data_02152590, volatile s32 *, 4) = arg1;
}
