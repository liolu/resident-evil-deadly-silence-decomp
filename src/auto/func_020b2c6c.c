/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02074ef0(u8);                              /* extern */
extern void *data_0213daa8;

s32 func_020b2c6c(void) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(data_0213daa8, u8 *, 1);
    data_0213daa8 += 2;
    if (func_02074ef0(temp_r0) != -1) {
        return 1;
    }
    return 0;
}
