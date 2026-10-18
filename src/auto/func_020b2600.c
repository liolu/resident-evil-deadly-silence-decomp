/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern void *data_0213daa8;
extern M2C_UNK data_0213db26;

s32 func_020b2600(void) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(data_0213daa8, u8 *, 1) * 0x38;
    data_0213daa8 += 2;
    ((s8 *) &data_0213db26)[temp_r0] = 0;
    return 1;
}
