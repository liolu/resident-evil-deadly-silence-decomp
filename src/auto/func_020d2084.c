/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020d2084(void) {
    s32 *temp_r1;
    s32 temp_r0;

    temp_r1 = M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2C), s32 **, 0x10);
    temp_r0 = *temp_r1;
    if (temp_r0 < 0xF0000) {
        *temp_r1 = temp_r0 + 0x1000;
    } else {
        *temp_r1 = 0;
    }
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE4) != 1) {
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE6) =
        (u8) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE6) - 1);
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE6) != 0) {
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x38) =
        (s32) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x38) + 1);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE5) =
        (u8) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE5) + 1);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xE6) = 3U;
}
