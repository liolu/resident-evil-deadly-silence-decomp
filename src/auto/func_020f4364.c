#include "m2c.h"
#include "engine.h"

s32 func_020f4364(s32 arg0) {
    return M2C_FIELD(arg0, u16 *, 0x1C) * 8;
}
