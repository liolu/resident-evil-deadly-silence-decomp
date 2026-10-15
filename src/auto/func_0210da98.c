#include "engine.h"
#include "m2c.h"

extern s32 data_0215b1ac;

void func_0210da98(s32 arg0, s32 arg1) {
    M2C_FIELD((data_0215b1ac + (arg0 * 4)), s32 *, 0x18) = arg1;
}
