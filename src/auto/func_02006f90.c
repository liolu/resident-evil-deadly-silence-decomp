#include "engine.h"
#include "m2c.h"

extern void *data_02137298;

void func_02006f90(s32 arg0, s32 arg1) {
    M2C_FIELD(data_02137298, s32 *, 0x3EB0) = arg0;
    M2C_FIELD(data_02137298, s32 *, 0x3EB4) = arg1;
}
