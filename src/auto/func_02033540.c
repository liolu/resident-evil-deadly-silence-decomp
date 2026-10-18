/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void *func_01ff9190();            /* extern */
s32 func_0201df30();                        /* extern */
M2C_UNK func_0209fbf0();                     /* extern */
M2C_UNK func_020fdd1c();         /* extern */
M2C_UNK func_020fdd50(); /* extern */
M2C_UNK func_02116dac();                    /* extern */
s32 func_02117970();                        /* extern */
s32 func_02117dac();                                /* extern */
s32 func_02117e68();                             /* extern */
M2C_UNK func_02117eb0();                    /* extern */
M2C_UNK func_0211809c();                    /* extern */
extern M2C_UNK data_0211c840;
extern M2C_UNK data_02127bf4;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_02144c04;
extern void *data_027e000c;
extern M2C_UNK data_027e003c;
extern M2C_UNK data_027e009c;
extern M2C_UNK data_027e0148;

void func_02033540(void) {
    s32 temp_r1;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r4_4;
    s32 temp_r5;
    s32 temp_r5_2;
    s32 temp_r5_3;
    s32 var_r2;
    void *temp_r0;

    M2C_FIELD(&data_02143cc0, u8 *, 0xF4F) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xF4F) | 0x80);
    temp_r4 = func_0201df30(M2C_FIELD(&data_02143cc0, s32 *, 0xF74), M2C_FIELD(&data_02143cc0, s32 *, 0xF7C));
    if ((M2C_FIELD(data_027e000c, u8 *, 0xA) & 0x40) && !(M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) & 1)) {
        M2C_FIELD(&data_02144bc0, s16 *, 0x88) = (s16) (temp_r4 - 0x180);
    }
    func_0209fbf0(0xF);
    temp_r1 = ((s32) (0x10000 - (0xFFFF & ((temp_r4 ^ 0x800) * 0x10))) >> 4) * 2;
    func_020fdd1c(&data_027e0148, *((s16 *) ((s8 *) &data_02127bf4 + (temp_r1 * 2))),
                  *((s16 *) ((s8 *) &data_02127bf4 + ((temp_r1 + 1) * 2))));
    temp_r0 = func_01ff9190(&data_02144c04, 9);
    func_02117eb0(0x40B00000, func_02117e68(M2C_FIELD(temp_r0, s32 *, 0x4C) * 0x12));
    M2C_FIELD(&data_027e003c, s32 *, 0) = func_02117dac();
    func_02117eb0(0x40B00000, func_02117e68(M2C_FIELD(temp_r0, s32 *, 0x50) * 0x12));
    M2C_FIELD(&data_027e003c, s32 *, 4) = func_02117dac();
    func_02117eb0(0x40B00000, func_02117e68(M2C_FIELD(temp_r0, s32 *, 0x54) * 0x12));
    M2C_FIELD(&data_027e003c, s32 *, 8) = func_02117dac();
    func_020fdd50(&data_027e003c, &data_027e0148);
    temp_r5 = func_02117e68(M2C_FIELD(&data_027e009c, s32 *, 0x14));
    func_0211809c(temp_r5, func_02117970(func_02117e68(M2C_FIELD(&data_027e003c, s32 *, 0)), 0x45800000));
    M2C_FIELD(&data_027e009c, s32 *, 0x14) = func_02117dac();
    temp_r5_2                              = func_02117e68(M2C_FIELD(&data_027e009c, s32 *, 0x18));
    func_02116dac(temp_r5_2, func_02117970(func_02117e68(M2C_FIELD(&data_027e003c, s32 *, 4)), 0x45800000));
    M2C_FIELD(&data_027e009c, s32 *, 0x18) = func_02117dac();
    temp_r5_3                              = func_02117e68(M2C_FIELD(&data_027e009c, s32 *, 0x1C));
    func_02116dac(temp_r5_3, func_02117970(func_02117e68(M2C_FIELD(&data_027e003c, s32 *, 8)), 0x45800000));
    M2C_FIELD(&data_027e009c, s32 *, 0x1C) = func_02117dac();
    if (M2C_FIELD(data_027e000c, u8 *, 0xA) & 0x40) {
        var_r2 = 1;
    } else {
        var_r2 = 0;
    }
    func_020fdd50((M2C_UNK *) ((var_r2 * 0xC) + (s32) &data_0211c840), temp_r0 + 0x28, &data_027e003c);
    func_020fdd50(&data_027e003c, &data_027e0148, &data_027e003c);
    temp_r4_2 = func_02117e68(M2C_FIELD(&data_027e009c, s32 *, 0x14));
    func_02116dac(temp_r4_2, func_02117970(func_02117e68(M2C_FIELD(&data_027e003c, s32 *, 0)), 0x45800000));
    M2C_FIELD(&data_02143cc0, s32 *, 0xF74) = func_02117dac();
    temp_r4_3                               = func_02117e68(M2C_FIELD(&data_027e009c, s32 *, 0x18));
    func_0211809c(temp_r4_3, func_02117970(func_02117e68(M2C_FIELD(&data_027e003c, s32 *, 4)), 0x45800000));
    M2C_FIELD(&data_02143cc0, s32 *, 0xF78) = func_02117dac();
    temp_r4_4                               = func_02117e68(M2C_FIELD(&data_027e009c, s32 *, 0x1C));
    func_0211809c(temp_r4_4, func_02117970(func_02117e68(M2C_FIELD(&data_027e003c, s32 *, 8)), 0x45800000));
    M2C_FIELD(&data_02143cc0, s32 *, 0xF7C) = func_02117dac();
}
