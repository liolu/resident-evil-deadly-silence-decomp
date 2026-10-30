/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0211851c(u16, M2C_UNK);                    /* extern */
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213ba90;

void func_020cb5fc(void) {
    s32 temp_r0;
    s32 temp_r3;

    M2C_FIELD(&data_0213ba90, s16 *, 0x6C) =
        (s16) ((s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x20) >> 0x10);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x14) = 0;
    temp_r0 = func_0211851c(M2C_FIELD(&data_0213b890, u16 *, 0x26), 0x3C);
    if (temp_r0 == 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x14) = 0;
    } else {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x14) =
            (s16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x14) - ((u32) (temp_r0 * 0x15554000) >> 0x10));
    }
    temp_r3 = M2C_FIELD(&data_0213b890, u16 *, 0x26) - (temp_r0 * 0x3C);
    if (temp_r3 != 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x14) =
            (s16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x14) - ((u32) (temp_r3 * 0x5B5555) >> 0x10));
    }
}
