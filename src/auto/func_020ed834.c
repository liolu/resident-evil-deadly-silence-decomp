#include "m2c.h"
#include "engine.h"

void func_020ed834(s32 arg0) {
    M2C_FIELD(arg0, volatile s32 *, 4) = (s32) (M2C_FIELD(arg0, volatile s32 *, 4) - M2C_FIELD(arg0, volatile s32 *, 0));
}
