/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK data_0213ad30;
extern u16 data_0213ad84;
extern M2C_UNK data_0213ae4c;
extern u8 data_0213b2b4;

u8 *func_02077818(u8 *arg0) {
    u8 *var_r0;
    u8 var_r2;

    var_r0 = arg0;
    if (data_0213ad84 == 0) {
        var_r2 = *var_r0;
        var_r0 = (u8 *) M2C_FIELD(&data_0213b2b4, u8 *, 0);
        if ((var_r0 != NULL) && ((var_r0 = (u8 *) (M2C_FIELD(&data_0213ad30, u16 *, 2) & 9), (var_r0 != NULL)) ||
                                 (var_r0 = (u8 *) M2C_FIELD(&data_0213ae4c, u8 *, 2), (var_r0 != NULL)))) {
            var_r2 = 1;
        }
        if (var_r2 == 1) {
            func_0206fcf8(4, 1, 1, 0x100);
            var_r0                                = &data_0213b2b4;
            M2C_FIELD(&data_0213b2b4, s8 *, 0xB4) = 2;
        }
    }
    return var_r0;
}
