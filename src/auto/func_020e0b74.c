#include "engine.h"
#include "m2c.h"

void func_020e0b74(s32 arg0, s32 arg1) {
    if (arg1 >= 0) {
        M2C_FIELD(arg0, volatile s32 *, 0x30) = arg1;
        return;
    }
    M2C_FIELD(arg0, volatile s32 *, 0x30) = (s32) M2C_FIELD(arg0, volatile s32 *, 0x14);
}
