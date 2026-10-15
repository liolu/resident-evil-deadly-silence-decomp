#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;
extern M2C_UNK data_027e01ac;

void func_020bca78(void) {
    s32 temp_r2;
    u8 var_r0;

    if ((u32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x40) >
        (u32) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x24)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    temp_r2                                = (var_r0 * 0x1C) + (s32) M2C_FIELD(&data_0213b890, void **, 0x4C);
    M2C_FIELD(&data_027e01ac, s16 *, 0x20) = (s16) (((s32) M2C_FIELD(temp_r2, s32 *, 0xC) >> 0xC) - 0x10);
    M2C_FIELD(&data_027e01ac, s16 *, 0x22) = (s16) (((s32) M2C_FIELD(temp_r2, s32 *, 0x10) >> 0xC) - 8);
}
