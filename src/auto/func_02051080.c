#include "engine.h"
#include "m2c.h"

extern void *data_027e000c;

void func_02051080(void) {
    M2C_FIELD(data_027e000c, u8 *, 8) = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) & 0x1F);
    M2C_FIELD(data_027e000c, u8 *, 8) = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) | 0x40);
}
