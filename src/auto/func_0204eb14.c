/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02075e90(void *, s32, s32);            /* extern */
M2C_UNK func_020d9538(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_02117dac();                                /* extern */
s32 func_02117e20(u16);                             /* extern */
M2C_UNK func_02117eb0(s32, s32);                    /* extern */
extern void *data_027e000c;

void func_0204eb14(void) {
    s16 temp_r1;
    s32 temp_r4;
    u16 temp_r2;
    u16 temp_r6;
    void *temp_r5;

    temp_r2 = M2C_FIELD(data_027e000c, u16 *, 0xAE);
    if ((u32) temp_r2 <= 0x9C4U) {
        M2C_FIELD(data_027e000c, u8 *, 0x91)   = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
        M2C_FIELD(data_027e000c, s16 *, 0xA8)  = 1;
        M2C_FIELD(data_027e000c, s16 *, 0x180) = 1;
        return;
    }
    M2C_FIELD(data_027e000c, u16 *, 0xAE) = (u16) (temp_r2 - 8);
    temp_r5                               = data_027e000c;
    temp_r6                               = M2C_FIELD(temp_r5, u16 *, 0xAE);
    func_02117eb0(0x40FFAE14, func_02117e20(temp_r6));
    temp_r4 = func_02117dac();
    func_02117eb0(0x40C00000, func_02117e20(temp_r6));
    func_02075e90(temp_r5 + 0x54, temp_r4, func_02117dac());
    temp_r1                               = M2C_FIELD(data_027e000c, s16 *, 0xA8);
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = (s16) (temp_r1 - 1);
    if ((temp_r1 == 0) && (M2C_FIELD(data_027e000c, s16 *, 0x180) != 0)) {
        func_020d9538(data_027e000c, 0, -1, -2);
        M2C_FIELD(data_027e000c, s16 *, 0xA8)  = 8;
        M2C_FIELD(data_027e000c, s16 *, 0x180) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x180) - 1);
    }
}
