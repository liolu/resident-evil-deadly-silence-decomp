#include "engine.h"
#include "m2c.h"

extern void *data_027e000c;

void func_0204e99c(void) {
    M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
    M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x96) = 0;
}
