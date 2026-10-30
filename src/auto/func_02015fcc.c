/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffb948(M2C_UNK *, M2C_UNK *, M2C_UNK);   /* extern */
s32 func_02001404(u8);                              /* extern */
M2C_UNK func_02014fe4(void *, M2C_UNK);             /* extern */
extern M2C_UNK data_0213bb18;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_027e0028;
extern M2C_UNK data_027e0054;

void func_02015fcc(void *arg0) {
    s32 temp_r3;
    u8 temp_r1;
    u8 temp_r4;

    M2C_FIELD(&data_027e0028, s16 *, 0) = 0;
    M2C_FIELD(&data_027e0028, s16 *, 2) = 0;
    M2C_FIELD(&data_027e0028, s16 *, 4) = 0;
    M2C_FIELD(&data_027e0054, s32 *, 0) = (s32) M2C_FIELD(arg0, s16 *, 0x20);
    M2C_FIELD(&data_027e0054, s32 *, 4) = (s32) M2C_FIELD(arg0, s16 *, 0x22);
    M2C_FIELD(&data_027e0054, s32 *, 8) = (s32) M2C_FIELD(arg0, s16 *, 0x24);
    if ((s32) (M2C_FIELD(arg0, s16 *, 0x22) + M2C_FIELD(arg0, s16 *, 0x12)) > (s32) M2C_FIELD(&data_02143cc0, s32 *, 0xF78)) {
        func_02014fe4(arg0, 1);
        M2C_FIELD(&data_0213bb18, u8 *, 0x1D4) = (u8) (M2C_FIELD(&data_0213bb18, u8 *, 0x1D4) & ~8);
        return;
    }
    temp_r4                                = M2C_FIELD(&data_02143cc0, u8 *, 0xF4C);
    M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = (u8) (temp_r4 & 0x1F);
    temp_r3                                = M2C_FIELD(arg0, s16 *, 0x22) + M2C_FIELD(arg0, s16 *, 0x12);
    if (temp_r3 > (s32) (M2C_FIELD(&data_02144bc0, s16 *, 0xDE) - 0xAF0)) {
        if (temp_r3 > (s32) (M2C_FIELD(&data_02144bc0, s16 *, 0xDE) - 0x1F4)) {
            M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) | 0x20);
        } else {
            M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) | 0x40);
        }
    } else {
        M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) | 0x80);
    }
    if (func_01ffb948(&data_027e0054, &data_027e0028, 4) == 1) {
        M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = temp_r4;
        func_02014fe4(arg0, 1);
        M2C_FIELD(&data_0213bb18, u8 *, 0x1D4) = (u8) (M2C_FIELD(&data_0213bb18, u8 *, 0x1D4) & ~8);
        return;
    }
    if (func_02001404(M2C_FIELD(arg0, u8 *, 5)) != 0) {
        M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = temp_r4;
        func_02014fe4(arg0, 0);
        return;
    }
    M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = temp_r4;
    temp_r1                                = M2C_FIELD(arg0, u8 *, 6);
    M2C_FIELD(arg0, u8 *, 6)               = (u8) (temp_r1 + 1);
    if ((u32) temp_r1 > 8U) {
        M2C_FIELD(arg0, s32 *, 0x90) = (s32) M2C_FIELD(arg0, s32 *, 0x8C);
    }
}
