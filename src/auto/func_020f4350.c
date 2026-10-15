#include "engine.h"
#include "m2c.h"

void func_020f4350(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0) {
        M2C_FIELD(arg0, s32 *, 8) = arg1;
    }
    if (arg2 != 0) {
        M2C_FIELD(arg0, s32 *, 0x18) = arg2;
    }
}
