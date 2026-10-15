#include "engine.h"
#include "m2c.h"

s32 func_020e8b5c(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return (s32) ((u32) M2C_FIELD(arg0, u32 *, 0xC) >> 1);
}
