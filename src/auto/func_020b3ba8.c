/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern u16 data_0213ad24;
extern void *data_0213daa8;

s32 func_020b3ba8(void) {
    u8 temp_r3;

    temp_r3 = M2C_FIELD(data_0213daa8, u8 *, 1);
    data_0213daa8 += 2;
    if (temp_r3 == 0xFF) {
        data_0213ad24 = 0;
    } else {
        data_0213ad24 |= 1 << temp_r3;
    }
    return 1;
}
