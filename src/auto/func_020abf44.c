/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213ad98;

s32 func_020abf44(void) {
    switch ((s32) M2C_FIELD(&data_0213ad98, u8 *, 1)) { /* irregular */
        case 2:
            return 0x34;
        case 5:
            return 0x36;
        case 10:
            return 0x3A;
        case 15:
            return 0x3F;
        case 21:
            return 0x43;
        case 22:
            return 0x3F;
        case 23:
            return 0x67;
        default:
            return 1;
    }
}
