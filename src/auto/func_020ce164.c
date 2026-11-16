/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020ce164(void) {
    u32 var_r1;
    s32 temp_r0;

    var_r1 = 0;
    do {
        temp_r0 = var_r1 * 0x3C;
        if (M2C_FIELD(M2C_FIELD(&data_0213b890, u8 **, 0x4C) + temp_r0, s16 *, 0x26) < 0x10) {
            M2C_FIELD(M2C_FIELD(&data_0213b890, u8 **, 0x4C) + temp_r0, s16 *, 0x26) = 0x10;
        }
        if (M2C_FIELD(M2C_FIELD(&data_0213b890, u8 **, 0x4C) + temp_r0, s16 *, 0x26) > 0xF0) {
            M2C_FIELD(M2C_FIELD(&data_0213b890, u8 **, 0x4C) + temp_r0, s16 *, 0x26) = 0xF0;
        }
        if (var_r1 == M2C_FIELD(M2C_FIELD(&data_0213b890, u8 **, 0x4C), u8 *, 0x142)) {
            if (M2C_FIELD(M2C_FIELD(&data_0213b890, u8 **, 0x4C) + temp_r0, s16 *, 0x2A) > 0x98) {
                M2C_FIELD(M2C_FIELD(&data_0213b890, u8 **, 0x4C) + temp_r0, s16 *, 0x2A) = 0x98;
            }
        }
        var_r1 += 1;
    } while (var_r1 < 5);
}
