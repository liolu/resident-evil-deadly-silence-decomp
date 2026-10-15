#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

s32 func_020caf9c(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x1E) == 0x1F) {
        return 1;
    }
    return 0;
}
