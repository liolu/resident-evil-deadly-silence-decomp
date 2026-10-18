#include "m2c.h"

extern M2C_UNK data_0211dcfc;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02147cc0;

s32 func_020a9c5c(void) {
    s32 var_r0;

    var_r0 = *((u8 *) ((s8 *) &data_0211dcfc + (M2C_FIELD(&data_02143cc0, u8 *, 0xF4E) * 4))) -
             M2C_FIELD(M2C_FIELD(&data_02147cc0, void **, 0x53C), u8 *, 1);
    if (var_r0 < 0) {
        var_r0 = 0;
    }
    return var_r0;
}
