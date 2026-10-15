#include "engine.h"
#include "m2c.h"

void func_020fc418(s32 arg0) {
    M2C_FIELD(arg0, s32 *, 0)    = 0x1000;
    M2C_FIELD(arg0, s32 *, 4)    = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0x1000;
    M2C_FIELD(arg0, s32 *, 0x30) = 0;
    M2C_FIELD(arg0, s32 *, 0x34) = 0;
}
