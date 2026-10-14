/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020599dc(u8, u8);                      /* extern */
extern void *data_0213daa8;

s32 func_020b2ec8(void) {
    u8 temp_r0;
    u8 temp_r1;

    temp_r0 = M2C_FIELD(data_0213daa8, u8 *, 2);
    temp_r1 = M2C_FIELD(data_0213daa8, u8 *, 3);
    data_0213daa8 += 4;
    func_020599dc(temp_r0, temp_r1);
    return 1;
}
