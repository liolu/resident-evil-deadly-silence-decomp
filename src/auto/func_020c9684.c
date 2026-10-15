#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c9684(void) {
    void *temp_r2;
    void *temp_r3;

    temp_r2 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
    if (M2C_FIELD(temp_r2, u16 *, 0x2C) != 0) {
        return;
    }
    M2C_FIELD(temp_r2, s16 *, 0x14) = (s16) (M2C_FIELD(temp_r2, s16 *, 0x14) - 1);
    temp_r3                         = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
    if (M2C_FIELD(temp_r3, s16 *, 0x14) != 0) {
        return;
    }
    M2C_FIELD(temp_r3, u8 *, 2) = (u8) (M2C_FIELD(temp_r3, u8 *, 2) + 1);
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s16 *, 0x16) = 1;
}
