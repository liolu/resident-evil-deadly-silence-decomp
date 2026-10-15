#include "m2c.h"

M2C_UNK func_020b8164(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_0213ad98;

void func_020ac19c(M2C_UNK arg0) {
    M2C_UNK var_r0;

    var_r0 = arg0;
    switch (M2C_FIELD(&data_0213ad98, u8 *, 0)) {
        default:
            break;
        case 0:
        case 5:
            if (M2C_FIELD(&data_0213ad98, u8 *, 1) == 6) {
                var_r0 = 0x32;
            } else {
                var_r0 = 0x33;
            }
            break;
        case 1:
        case 6:
            if (M2C_FIELD(&data_0213ad98, u8 *, 1) == 3) {
                var_r0 = 0x32;
            } else {
                var_r0 = 0x33;
            }
            break;
        case 2:
            var_r0 = 0x34;
            break;
        case 4:
            var_r0 = 0x35;
            break;
    }
    func_020b8164(var_r0, 0);
}
