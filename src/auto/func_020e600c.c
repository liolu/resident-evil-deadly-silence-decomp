#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_02153054;

s32 func_020e600c(void) {
    return M2C_FIELD(&data_02153054, s32 *, 0xC);
}
