/* compiler: 2.0/sp1p5 -O1 */
#include "m2c.h"

extern M2C_UNK data_0213ad98;

s32 func_020abf20(void) {
    if (M2C_FIELD(&data_0213ad98, u8 *, 1) == 6) {
        return 0x50;
    } else {
        return 1;
    }
}
