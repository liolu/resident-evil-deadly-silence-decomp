#include "m2c.h"
#include "engine.h"

s32 func_020ed96c(s32 arg0, s32 arg1) {
    return M2C_FIELD((arg0 + (arg1 * 4)), s32 *, 0xC);
}
