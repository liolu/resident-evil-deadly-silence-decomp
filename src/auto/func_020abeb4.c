/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213ad98;

s32 func_020abeb4(void) {
    switch ((s32) M2C_FIELD(&data_0213ad98, u8 *, 1)) { /* irregular */
        case 0:
            return 0x67;
        case 6:
            return 0x3F;
        case 5:
            return 0x67;
        case 13:
            return 0x6E;
        default:
            return 1;
    }
}
