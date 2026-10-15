/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020558c0(void *, M2C_UNK);             /* extern */
M2C_UNK func_02091624(void *, s32, s32);            /* extern */
M2C_UNK func_020d95b4(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_0211ce10;
extern void *data_027e000c;

void func_0204eedc(void) {
    func_020558c0(data_027e000c, 0x15);
    M2C_FIELD(data_027e000c, s8 *, 0x90)      = 1;
    M2C_FIELD(data_027e000c, s8 *, 0x91)      = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x92)      = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x93)      = 0;
    M2C_FIELD(data_027e000c, s16 *, 0x94)     = 1;
    M2C_FIELD(data_027e000c, M2C_UNK **, 0xC) = &data_0211ce10;
    M2C_FIELD(data_027e000c, u8 *, 8)         = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) & 0x1F);
    M2C_FIELD(data_027e000c, u8 *, 8)         = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) | 4);
    M2C_FIELD(data_027e000c, s8 *, 0xA1)      = 0;
    M2C_FIELD(data_027e000c, s8 *, 0xA2)      = 0;
    M2C_FIELD(data_027e000c, s8 *, 0xA3)      = 0;
    M2C_FIELD(data_027e000c, s8 *, 0x98)      = 0;
    M2C_FIELD(data_027e000c, s16 *, 0xAE)     = 0x1000;
    M2C_FIELD(data_027e000c, s8 *, 0x96)      = 1;
    M2C_FIELD(data_027e000c, s32 *, 0x184)    = (s32) M2C_FIELD(data_027e000c, s32 *, 0x30);
    M2C_FIELD(data_027e000c, s32 *, 0x188)    = (s32) M2C_FIELD(data_027e000c, s32 *, 0x38);
    M2C_FIELD(data_027e000c, s16 *, 0x182)    = 0;
    M2C_FIELD(data_027e000c, s16 *, 0x18E)    = 2;
    M2C_FIELD(data_027e000c, s16 *, 0x18C)    = 0x28;
    func_02091624(data_027e000c + 0x54, 0x40FFAE14, 0x40C00000);
    func_020d95b4(data_027e000c, 0x10, 0x14, 0x10);
}
