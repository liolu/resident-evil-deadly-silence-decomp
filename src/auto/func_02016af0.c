#include "engine.h"
#include "m2c.h"

void func_02016af0(s32 arg0) {
    M2C_FIELD(arg0, s32 *, 0x90) = (s32) (M2C_FIELD(arg0, s32 *, 0x90) + 4);
    M2C_FIELD(arg0, s8 *, 0x1E)  = 0;
}
