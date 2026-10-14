/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02092dd4(u8, u16);                     /* extern */
extern void *data_0213daa8;

s32 func_020b3084(void) {
    u16 temp_r1;
    u8 temp_r0;

    temp_r0 = M2C_FIELD(data_0213daa8, u8 *, 1);
    temp_r1 = M2C_FIELD(data_0213daa8, u16 *, 2);
    data_0213daa8 += 4;
    func_02092dd4(temp_r0, temp_r1);
    return 1;
}
