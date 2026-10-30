/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK *func_0207a3d8();                           /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213daa8;

M2C_UNK *func_020a2150(void) {
    s32 var_r0;

    var_r0 = M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80;
    if (var_r0 == 0) {
        var_r0 = (s32) &data_0213daa8;
        if (M2C_FIELD((s32) &data_0213daa8, u8 *, 0x249) == 1) {
            M2C_FIELD((s32) &data_0213daa8, u8 *, 0x249) = 0U;
            var_r0                                       = (s32) func_0207a3d8();
        }
    }
    return (M2C_UNK *) var_r0;
}
