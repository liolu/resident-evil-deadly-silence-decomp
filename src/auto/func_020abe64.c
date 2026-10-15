/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02144cc0;

s32 func_020abe64(void) {
    s32 var_r0;

    switch (M2C_FIELD(&data_0213ad98, u8 *, 1)) {   /* irregular */
        case 7:
            if (M2C_FIELD(M2C_FIELD(&data_02144cc0, void **, 0xD8), u8 *, 9) & 0x40) {
                var_r0 = 0x2E;
            } else {
                var_r0 = 0x86;
            }
            return var_r0;
        case 10:
            return 0xAB;
        default:
            return 1;
    }
}
