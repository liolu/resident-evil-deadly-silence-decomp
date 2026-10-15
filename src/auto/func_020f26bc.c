#include "engine.h"
#include "m2c.h"

void func_020f26bc(s32 arg0) {
    M2C_FIELD(arg0, volatile s32 *, 0x1000) = 0;
    M2C_FIELD(arg0, volatile s32 *, 0x1004) = (s32) M2C_FIELD(arg0, volatile s32 *, 0x1000);
}
