#include "m2c.h"
#include "engine.h"

s32 func_020f4370(s32 arg0) {
    return M2C_FIELD(arg0, u16 *, 0xC) * 8;
}
