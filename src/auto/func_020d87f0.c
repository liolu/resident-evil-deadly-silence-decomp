#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_02141cc0;

void func_020d87f0(s32 arg0) {
    if ((u32) (M2C_FIELD(&data_02141cc0, s32 *, 0x40) - 9) > 1U) {
        M2C_FIELD(&data_02141cc0, s32 *, 0x54) = arg0;
    }
}
