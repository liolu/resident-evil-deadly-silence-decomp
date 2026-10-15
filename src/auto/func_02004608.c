#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_02136eb0;

s32 func_02004608(void) {
    return M2C_FIELD(&data_02136eb0, s32 *, 0x1A8);
}
