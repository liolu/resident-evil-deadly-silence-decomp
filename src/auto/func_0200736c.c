#include "m2c.h"
#include "engine.h"

extern void *data_02137298;

void func_0200736c(s32 arg0) {
    if (arg0 != 0) {
        return;
    }
    M2C_FIELD(data_02137298, u8 *, 0x3EAA) = (u8) (M2C_FIELD(data_02137298, u8 *, 0x3EAA) & ~2);
    M2C_FIELD(data_02137298, u8 *, 0x3EAA) = (u8) (M2C_FIELD(data_02137298, u8 *, 0x3EAA) & 4);
}
