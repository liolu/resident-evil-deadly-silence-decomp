/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u32 func_02082348();                                /* extern */

void func_0207ebe8(void *arg0) {
    void *temp_r1;

    if (func_02082348() > 0xAU) {
        M2C_FIELD(arg0, u8 *, 5)       = (u8) (M2C_FIELD(arg0, u8 *, 5) | 8);
        temp_r1                        = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
        M2C_FIELD(arg0, u8 *, 7)       = (u8) (M2C_FIELD(arg0, u8 *, 7) | 2);
    }
}
