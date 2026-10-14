/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020b6530(u8);                          /* extern */
extern void *data_0213daa8;

s32 func_020b2e94(void) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(data_0213daa8, u8 *, 1);
    data_0213daa8 += 2;
    func_020b6530(temp_r0);
    return 1;
}
