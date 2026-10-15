#include "engine.h"
#include "m2c.h"

s32 func_020539a8(s32 arg0) {
    if (M2C_FIELD(arg0, s8 *, 6) != 0) {
        return 1;
    }
    return 0;
}
