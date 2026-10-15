#include "engine.h"
#include "m2c.h"

void func_020e739c(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        M2C_FIELD(arg0, s32 *, 0xC) = arg1;
    }
}
