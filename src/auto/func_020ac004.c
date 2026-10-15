/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02144cc0;

s32 func_020ac004(void) {
    s32 var_r0;
    s32 var_r0_2;
    s32 var_r0_3;

    switch ((s32) M2C_FIELD(&data_0213ad98, u8 *, 1)) { /* irregular */
        case 7:
            if (M2C_FIELD(M2C_FIELD(&data_02144cc0, void **, 0xD8), u8 *, 9) & 0x40) {
                var_r0 = 0x13;
            } else {
                var_r0 = 0x12;
            }
            return var_r0;
        case 8:
            if (M2C_FIELD(&data_0213ad98, u8 *, 0) == 5) {
                var_r0_2 = 0xA5;
            } else {
                var_r0_2 = 0x14;
            }
            return var_r0_2;
        case 15:
            if (M2C_FIELD(&data_0213ad98, u8 *, 0) == 5) {
                var_r0_3 = 0x3F;
            } else {
                var_r0_3 = 0x1E;
            }
            return var_r0_3;
        case 22:
            return 0x3F;
        case 23:
            return 0x67;
        case 27:
            return 0x2E;
        default:
            return 1;
    }
}
