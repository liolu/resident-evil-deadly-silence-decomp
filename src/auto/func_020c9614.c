#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b890;

void func_020c9614(void) {
    s32 temp_r2;
    void *temp_r1;
    void *temp_r2_2;
    void *temp_r3;

    temp_r3 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
    temp_r2 = M2C_FIELD(temp_r3, s32 *, 8);
    if (temp_r2 <= -0x28) {
        M2C_FIELD(temp_r3, u8 *, 2) = (u8) (M2C_FIELD(temp_r3, u8 *, 2) + 1);
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s32 *, 8) = -0x28;
        return;
    }
    M2C_FIELD(temp_r3, s32 *, 8) = (s32) (temp_r2 - 2);
    temp_r2_2 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
    M2C_FIELD(temp_r2_2, s16 *, 0x28) = (s16) (M2C_FIELD(temp_r2_2, s16 *, 0x28) - 0x9E);
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
    M2C_FIELD(temp_r1, s16 *, 0x2A) = (s16) (M2C_FIELD(temp_r1, s16 *, 0x2A) - 0x9E);
}
