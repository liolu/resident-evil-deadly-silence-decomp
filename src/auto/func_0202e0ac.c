#include "m2c.h"
#include "engine.h"

extern void *data_02137338;
extern void *data_027e000c;

void func_0202e0ac(void) {
    M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
    M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x92) = 1;
    M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
    M2C_FIELD(data_02137338, s16 *, 0xE) = 0;
}
