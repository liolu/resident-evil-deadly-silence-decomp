#include "m2c.h"
#include "engine.h"

s32 func_020e9998(s32 arg0) {
    if (M2C_FIELD(arg0, s32 *, 0x1A8) == 0xC) {
        return 1;
    }
    return 0;
}
