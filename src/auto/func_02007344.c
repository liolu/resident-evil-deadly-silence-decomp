#include "engine.h"
#include "m2c.h"

extern void *data_02137298;

void func_02007344(s32 arg0) {
    if (arg0 != 0) {
        return;
    }
    M2C_FIELD(data_02137298, u8 *, 0x3EAA) = (u8) (M2C_FIELD(data_02137298, u8 *, 0x3EAA) | 1);
}
