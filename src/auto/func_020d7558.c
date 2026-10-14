#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02141cc0;

s32 func_020d7558(void) {
    return (s32) M2C_FIELD(&data_02141cc0, u16 *, 0x50);
}
