#include "engine.h"
#include "m2c.h"

extern void **data_027e000c;

s32 func_02090c10(void) {
    return (s32) *M2C_FIELD(*data_027e000c, s32 **, 0x10) >> 0xC;
}
