/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02143cc0;

s32 func_0205587c(void *arg0) {
    if (((M2C_FIELD(&data_02143cc0, u8 *, 0xF) == 0) && (M2C_FIELD(&data_0213daa8, u16 *, 0x74) & 4)) ||
        (M2C_FIELD(arg0, u8 *, 0x90) == 0)) {
        return 1;
    }
    return 0;
}
