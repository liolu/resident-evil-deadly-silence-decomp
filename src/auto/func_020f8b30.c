#include "engine.h"
#include "m2c.h"

s32 func_020f8b30(s32 arg0, s32 arg1) {
    return arg0 + M2C_FIELD(arg0, u16 *, 8) + (arg1 * 0x10);
}
