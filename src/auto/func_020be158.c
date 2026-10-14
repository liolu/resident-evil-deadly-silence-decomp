/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213be00;

s32 func_020be158(void) {
    s32 var_r4;

    var_r4 = 0;
    if (func_020b39e4(&data_0213be00, 0x7E) == 0) {
        if ((u32) M2C_FIELD(&data_0213bdcc, u32 *, 0x10) <= 0x9E340U) {
            var_r4 = 1;
        }
        if ((u32) M2C_FIELD(&data_0213bdcc, u32 *, 0x10) >= 0x62E080U) {
            var_r4 = 1;
        }
    }
    if (var_r4 != 0) {
        M2C_FIELD(&data_0213b890, u8 *, 0x1E) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x1E) | 1);
    }
    return var_r4;
}
