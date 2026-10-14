#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213b890;

void func_020c6164(void) {
    void *temp_r3;

    temp_r3 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0xFC);
    M2C_FIELD(temp_r3, u8 *, 1) = (u8) (M2C_FIELD(temp_r3, u8 *, 1) + 1);
    M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0xFC), s32 *, 4) = 0;
}
