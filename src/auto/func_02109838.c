#include "m2c.h"
#include "engine.h"

void func_02109838(s32 arg0) {
    M2C_FIELD(arg0, volatile s32 *, 0) = 0;
    M2C_FIELD(arg0, volatile s32 *, 4) = (s32) M2C_FIELD(arg0, volatile s32 *, 0);
    M2C_FIELD(arg0, volatile s16 *, 0x18) = 0;
    M2C_FIELD(arg0, volatile s32 *, 8) = 0;
    M2C_FIELD(arg0, volatile s32 *, 0x10) = 0xE;
    M2C_FIELD(arg0, volatile s32 *, 0xC) = 0;
}
