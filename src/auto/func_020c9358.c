#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c9358(void) {
    void *temp_r3;
    void *temp_r2;

    temp_r3                         = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
    temp_r2                         = M2C_FIELD(temp_r3, void **, 0x18);
    M2C_FIELD(temp_r3, u16 *, 0x2C) = (u16) (M2C_FIELD(temp_r3, u16 *, 0x2C) - 0x800);
    if (M2C_FIELD(temp_r2, s16 *, 0x16) != 2) {
        return;
    }
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s16 *, 0x16) = 2;
    *(u8 *) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8)                 = 0;
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), u8 *, 2)     = 0;
}
