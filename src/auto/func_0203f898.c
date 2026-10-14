#include "m2c.h"
#include "engine.h"

extern void *data_027e000c;

void func_0203f898(void) {
    M2C_FIELD(data_027e000c, s8 *, 0x92) = 5;
    M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
    if ((u32) M2C_FIELD(data_027e000c, u16 *, 0x180) >= 0xBB8U) {
        return;
    }
    M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
    M2C_FIELD(data_027e000c, s8 *, 0x92) = 1;
    M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
}
