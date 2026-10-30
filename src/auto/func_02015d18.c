/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffb948(M2C_UNK *, M2C_UNK *, M2C_UNK);   /* extern */
s32 func_02001404(M2C_UNK);                         /* extern */
M2C_UNK func_02014e98(void *);                      /* extern */
M2C_UNK func_02016b08();                            /* extern */
M2C_UNK func_02017f68(M2C_UNK, u8, u8, u8, s32);    /* extern */
M2C_UNK func_020b81b8(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK data_0213bb18;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_027e0028;
extern M2C_UNK data_027e0054;

void func_02015d18(void *arg0) {
    s16 temp_r1;
    s16 temp_r1_2;
    u8 temp_r4;

    func_02016b08();
    M2C_FIELD(&data_027e0028, s16 *, 0) = 0;
    M2C_FIELD(&data_027e0028, s16 *, 2) = 0;
    M2C_FIELD(&data_027e0028, s16 *, 4) = 0;
    temp_r1                             = M2C_FIELD(arg0, s16 *, 0x20);
    M2C_FIELD(&data_027e0054, s32 *, 0) = (s32) temp_r1;
    M2C_FIELD(&data_027e0054, s32 *, 4) = (s32) M2C_FIELD(arg0, s16 *, 0x22);
    temp_r1_2                           = M2C_FIELD(arg0, s16 *, 0x24);
    M2C_FIELD(&data_027e0054, s32 *, 8) = (s32) temp_r1_2;
    if ((temp_r1 & 0x80000000) || (temp_r1_2 & 0x80000000)) {
        func_02017f68(7, M2C_FIELD(arg0, u8 *, 0x26), M2C_FIELD(arg0, u8 *, 0x27), M2C_FIELD(arg0, u8 *, 6), 0);
        M2C_FIELD(&data_0213bb18, u8 *, 0x1D4) = (u8) (M2C_FIELD(&data_0213bb18, u8 *, 0x1D4) & ~8);
    }
    if (func_01ffb948(&data_027e0054, &data_027e0028, 4) == 1) {
        M2C_FIELD(&data_027e0054, s32 *, 0) = (s32) M2C_FIELD(arg0, s16 *, 0x20);
        M2C_FIELD(&data_027e0054, s32 *, 4) = (s32) M2C_FIELD(arg0, s16 *, 0x22);
        M2C_FIELD(&data_027e0054, s32 *, 8) = (s32) M2C_FIELD(arg0, s16 *, 0x24);
        func_02014e98(arg0);
        M2C_FIELD(&data_0213bb18, u8 *, 0x1D4) = (u8) (M2C_FIELD(&data_0213bb18, u8 *, 0x1D4) & ~8);
        return;
    }
    temp_r4                                = M2C_FIELD(&data_02143cc0, u8 *, 0xF4C);
    M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = (u8) (temp_r4 & 0x1F);
    M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) | 0x40);
    if (func_02001404(0xA) == 0) {
        M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = temp_r4;
        return;
    }
    M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = temp_r4;
    M2C_FIELD(&data_027e0054, s32 *, 0)    = (s32) M2C_FIELD(arg0, s16 *, 0x20);
    M2C_FIELD(&data_027e0054, s32 *, 4)    = (s32) M2C_FIELD(arg0, s16 *, 0x22);
    M2C_FIELD(&data_027e0054, s32 *, 8)    = (s32) M2C_FIELD(arg0, s16 *, 0x24);
    func_020b81b8(0x1E, &data_027e0054, 0);
    func_020b81b8(0x1E, &data_027e0054, 0);
    func_02017f68(7, M2C_FIELD(arg0, u8 *, 0x26), M2C_FIELD(arg0, u8 *, 0x27), M2C_FIELD(arg0, u8 *, 6), 0);
}
