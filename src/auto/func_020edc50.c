#include "engine.h"
#include "m2c.h"

void func_020edc50(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, volatile s32 *, 0xC208) = arg1;
    M2C_FIELD(arg0, volatile s32 *, 0xC20C) = arg2;
    M2C_FIELD(arg0, volatile s32 *, 0xC210) =
        (s32) (M2C_FIELD(arg0, volatile s32 *, 0xC208) * M2C_FIELD(arg0, volatile s32 *, 0xC20C));
}
