#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b890;

s32 func_020d234c(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x1C) == 4) {
        return 1;
    }
    return 0;
}
