#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_02141cc0;

void func_020d7568(s32 arg0, s32 arg1) {
    M2C_FIELD(&data_02141cc0, s32 *, 0) = arg0;
    M2C_FIELD(&data_02141cc0, s16 *, 4) = (s16) arg1;
}
