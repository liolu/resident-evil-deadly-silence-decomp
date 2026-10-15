#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0211fdd4;

s32 func_0208e11c(s32 arg0) {
    if ((u32) M2C_FIELD(&data_0211fdd4, u32 *, 0x164) > (u32) arg0) {
        return 0;
    }
    if ((u32) M2C_FIELD(&data_0211fdd4, u32 *, 0x160) > (u32) arg0) {
        return 1;
    }
    if ((u32) M2C_FIELD(&data_0211fdd4, u32 *, 0x15C) > (u32) arg0) {
        return 2;
    }
    return 3;
}
