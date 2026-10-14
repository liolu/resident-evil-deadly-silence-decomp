/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020b7318(u8);                          /* extern */
M2C_UNK func_020b7410();                            /* extern */
s32 func_020b74e8();                                /* extern */
extern M2C_UNK data_0213ad48;

s32 func_020b72ec(void) {
    s32 temp_r4;

    temp_r4 = func_020b74e8();
    func_020b7318(M2C_FIELD(&data_0213ad48, u8 *, 0xA));
    func_020b7410();
    return temp_r4;
}
