#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_02141cc0;

void func_020d757c(s32 arg0) {
    M2C_FIELD(&data_02141cc0, s32 *, 8) = arg0;
}
