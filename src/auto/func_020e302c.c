#include "engine.h"
#include "m2c.h"

void func_020e302c(s32 arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 3) {
        M2C_FIELD(arg0, s32 *, 0xC) = 0;
    }
}
