#include "m2c.h"
#include "engine.h"

void func_0208a4c0(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg2, s16 *, 0) = (s16) (M2C_FIELD(arg0, s16 *, 0) + M2C_FIELD(arg1, s16 *, 0));
    M2C_FIELD(arg2, s16 *, 2) = (s16) (M2C_FIELD(arg0, s16 *, 2) + M2C_FIELD(arg1, s16 *, 2));
}
