/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0213b890;

s32 func_020c5ec8(void) {
    s8 temp_r0;

    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xA8) =
        (u8) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0xA8) & ~0x80);
    temp_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x20);
    if (((s32) temp_r0 > 0) && ((s32) temp_r0 < 0x1B)) {
        return temp_r0;
    }
    if (temp_r0 == 0x1E) {
        return -1;
    }
    if (temp_r0 == 0x1D) {
        return -3;
    }
    if (temp_r0 == 0) {
        return -2;
    }
    if (temp_r0 == 0x1B) {
        return -4;
    }
    if (temp_r0 == 0x1C) {
        return -5;
    }
    return 0;
}
