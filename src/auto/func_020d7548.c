#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02141cc0;

s32 func_020d7548(void) {
    return M2C_FIELD(&data_02141cc0, s32 *, 0x40);
}
