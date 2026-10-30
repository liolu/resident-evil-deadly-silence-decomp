/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
s8 func_0211851c(s16, M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020c7fdc(void) {
    s32 var_r2;
    void *temp_r4;
    void *temp_r4_2;
    void *temp_r4_3;

    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) =
        (s16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) - 1);
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) & 1) {
        var_r2 = 0x01000000;
    } else {
        var_r2 = 0x41000000;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x120) = var_r2;
    temp_r4                                                           = M2C_FIELD(&data_0213b890, void **, 0x4C);
    M2C_FIELD(temp_r4, s8 *, 0x138)                                   = func_0211851c(M2C_FIELD(temp_r4, s16 *, 0x12), 2);
    temp_r4_2                                                         = M2C_FIELD(&data_0213b890, void **, 0x4C);
    M2C_FIELD(temp_r4_2, s8 *, 0x139)                                 = func_0211851c(M2C_FIELD(temp_r4_2, s16 *, 0x12), 2);
    temp_r4_3                                                         = M2C_FIELD(&data_0213b890, void **, 0x4C);
    M2C_FIELD(temp_r4_3, s8 *, 0x13A)                                 = func_0211851c(M2C_FIELD(temp_r4_3, s16 *, 0x12), 2);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x140) = 0x1000;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x142) = 0x1000;
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) == 0x3C) {
        func_020b82fc(0x82);
    }
    if ((s32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) < 0x1E) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x4C) = 3;
    }
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) == 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x4C) = 1;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x48) = 0;
        M2C_FIELD(&data_0213b890, s8 *, 0x23)                           = 0;
        M2C_FIELD(&data_0213b890, u8 *, 0x22)                           = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x22) + 1);
    }
}
