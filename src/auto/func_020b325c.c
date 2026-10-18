/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213ad98;
extern void *data_0213daa8;

s32 func_020b325c(void) {
    u8 temp_ip;
    u8 temp_lr;

    temp_lr = M2C_FIELD(data_0213daa8, u8 *, 1);
    temp_ip = M2C_FIELD(data_0213daa8, u8 *, 2);
    data_0213daa8 += 4;
    ((s8 *) &data_0213ad98)[temp_lr] = temp_ip;
    return 1;
}
