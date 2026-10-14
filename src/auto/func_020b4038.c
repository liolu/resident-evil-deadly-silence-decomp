/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void *func_02053e90(u8);                            /* extern */
extern M2C_UNK data_0213ad98;
extern void *data_0213daa8;

s32 func_020b4038(void) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(data_0213daa8, u8 *, 1);
    data_0213daa8 += 2;
    M2C_FIELD(&data_0213ad98, u8 *, 0xA) = (u8) M2C_FIELD(func_02053e90(temp_r0), u8 *, 0xA);
    return 1;
}
