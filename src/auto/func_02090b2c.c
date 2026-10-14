#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02144bc0;

s32 func_02090b2c(void) {
    return (s32) (u16) ((M2C_FIELD(&data_02144bc0, s16 *, 0x88) + 0x800) & 0xFFF);
}
