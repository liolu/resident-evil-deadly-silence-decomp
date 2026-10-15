/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020adcf8(M2C_UNK, s16);                    /* extern */
extern M2C_UNK data_0213ad98;

s32 func_020a9f08(void *arg0) {
    s32 var_r0;

    if ((func_020adcf8(0, M2C_FIELD(arg0, s16 *, 0x16E)) != 0) && (M2C_FIELD(arg0, u8 *, 0x98) == 0)) {
        M2C_FIELD(arg0, u8 *, 0x93) = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
    }
    var_r0 = M2C_FIELD(&data_0213ad98, u16 *, 0x20) & 0x14;
    if (var_r0 != 0) {
        var_r0                      = 5;
        M2C_FIELD(arg0, u8 *, 0x93) = 5U;
    }
    return var_r0;
}
