#include "m2c.h"

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;

M2C_UNK *func_020cb2a8(void) {
    s32 var_r0;

    var_r0 = M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80;
    if (var_r0 == 0) {
        var_r0 = (s32) &data_0213b890;
        M2C_FIELD((s32) &data_0213b890, s8 *, 0x21) = 1;
    }
    return (M2C_UNK *) var_r0;
}
