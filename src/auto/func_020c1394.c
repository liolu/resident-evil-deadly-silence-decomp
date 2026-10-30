/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02092c04(s32, M2C_UNK, M2C_UNK, M2C_UNK);  /* extern */
s32 func_020c13f8();                                /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;

s32 func_020c1394(void) {
    s32 var_r0;

    if (M2C_FIELD(&data_0213b890, u8 *, 0x21) == 0) {
        M2C_FIELD(&data_0213b890, u8 *, 0x21) = 1U;
        M2C_FIELD(&data_0213ad98, u8 *, 5)    = 0U;
        return func_02092c04(0xE742, 0, 9, 0);
    }
    var_r0 = M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80;
    if (var_r0 == 0) {
        var_r0 = func_020c13f8();
    }
    return var_r0;
}
