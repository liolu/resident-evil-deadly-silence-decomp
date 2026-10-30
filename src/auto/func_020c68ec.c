/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c5d34(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_0213b890;

void func_020c68ec(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x23) == 0) {
        M2C_FIELD(&data_0213b890, u8 *, 0x23) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x23) + 1);
        func_020c5d34(0, -0x38, -0x40, 5);
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x54)  = 1;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) = 0x96;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) =
        (s16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) - 1);
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12) != 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x12E) = 1;
        return;
    }
    M2C_FIELD(&data_0213b890, s32 *, 0x20)                          = 0x201;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x54) = 0;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x4B) = 0;
}
