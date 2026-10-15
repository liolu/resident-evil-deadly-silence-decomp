#include "engine.h"
#include "m2c.h"

extern void *data_027e000c;

void func_02052a24(void) {
    M2C_FIELD(data_027e000c, u8 *, 0x91) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
    M2C_FIELD(data_027e000c, s8 *, 0x92) = 0;
}
