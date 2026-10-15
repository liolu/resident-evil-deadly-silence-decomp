#include "engine.h"
#include "m2c.h"

void func_020e74e0(s32 arg0, s32 arg1) {
    if (arg0 != 0) {
        M2C_FIELD(arg0, s8 *, 3) = (s8) arg1;
    }
}
