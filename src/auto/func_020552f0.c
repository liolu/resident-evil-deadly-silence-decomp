#include "m2c.h"
#include "engine.h"

extern void *data_027e000c;

void func_020552f0(s32 arg0) {
    M2C_FIELD(data_027e000c, s16 *, 0xA6) = (s16) arg0;
    if ((u32) (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA2) - 0x15) < 7U) {
        M2C_FIELD(data_027e000c, s16 *, 0xA6) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA6) - 0xD);
    }
    if ((u32) (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA2) - 7) < 7U) {
        M2C_FIELD(data_027e000c, s16 *, 0xA6) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA6) - 0xD);
    }
    if ((u32) (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA2) - 0x17) < 3U) {
        M2C_FIELD(data_027e000c, s16 *, 0xA6) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA6) - 0xE);
    }
    if ((u32) (u8) (M2C_FIELD(data_027e000c, u8 *, 0xA2) - 9) < 3U) {
        M2C_FIELD(data_027e000c, s16 *, 0xA6) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0xA6) - 0xE);
    }
}
