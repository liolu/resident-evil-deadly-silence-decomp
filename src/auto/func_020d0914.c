#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020d0914(void) {
    u16 temp_r0;

    temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0xF0);
    if ((u32) temp_r0 >= 0x320U) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xFA) = 5;
    } else if ((u32) temp_r0 >= 0x1F4U) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xFA) = 4;
    } else {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xFA) = -1;
    }
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x40) == 4) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xFA) = 6;
    }
}
