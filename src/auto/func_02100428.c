#include "engine.h"
#include "m2c.h"

s32 func_02100428(void) {
    return (((s32) (*(u16 *) 0x0400100A & 0x3C) >> 2) << 0xE) + 0x06200000;
}
