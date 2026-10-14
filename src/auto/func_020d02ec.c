#include "m2c.h"
#include "engine.h"

void func_020d02ec(s32 arg0, s32 arg1) {
    M2C_FIELD(arg0, s8 *, 2) = (s8) arg1;
    M2C_FIELD(arg0, s8 *, 3) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
}
