/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02058af4(void *arg0) {
    void *temp_r3;

    temp_r3                                                                          = M2C_FIELD(arg0, void **, 8);
    M2C_FIELD((M2C_FIELD(arg0, s32 *, 4) + M2C_FIELD(temp_r3, u8 *, 1)), u8 *, 0x90) = (u8) M2C_FIELD(temp_r3, u8 *, 2);
    return 3;
}
