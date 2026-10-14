/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02144bc0;
extern void *data_027e000c;
extern s32 data_027e0010;

void func_0203f8f0(void) {
    if (((u32) M2C_FIELD(data_027e000c, u16 *, 0x180) < 0x2710U) && !(M2C_FIELD(data_027e000c, s16 *, 0x17C) & 1) && (M2C_FIELD(data_027e000c, s16 *, 0x192) != 0)) {
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 2;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
    }
    if ((((u32) M2C_FIELD(data_027e000c, u16 *, 0x180) < 0x7D0U) && (data_027e0010 == 0)) || (M2C_FIELD(data_027e000c, s16 *, 0x17E) != 0)) {
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 3;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        M2C_FIELD(data_027e000c, s16 *, 0x17E) = 0;
        return;
    }
    if ((u32) M2C_FIELD(data_027e000c, u16 *, 0x186) > 0x3CU) {
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 2;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        M2C_FIELD(data_027e000c, u16 *, 0x186) = 0U;
    }
    if ((s32) M2C_FIELD(&data_02144bc0, s16 *, 0xD8) >= 0) {
        return;
    }
    M2C_FIELD(data_027e000c, s8 *, 0x91) = 1;
    M2C_FIELD(data_027e000c, s8 *, 0x92) = 4;
    M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
}
