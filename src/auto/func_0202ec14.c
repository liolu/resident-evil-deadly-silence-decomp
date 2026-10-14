#include "m2c.h"
#include "engine.h"

extern void *data_027e000c;
extern s32 data_027e0018;

void func_0202ec14(void) {
    M2C_FIELD(data_027e000c, u8 *, 8) = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) & 0x1F);
    if ((s32) data_027e0018 >= 0xFA0) {
        return;
    }
    M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
    M2C_FIELD(data_027e000c, s8 *, 0x92) = 8;
    M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
    M2C_FIELD(data_027e000c, u8 *, 0xA) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA) - 4);
}
