/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020b9e18(s32 arg0, s32 arg1) {
    u16 temp_r3;

    temp_r3 = M2C_FIELD(arg0, u8 *, 1) + M2C_FIELD(arg1, u8 *, 1);
    if ((u32) temp_r3 > 0xFAU) {
        M2C_FIELD(arg0, u8 *, 1) = 0xFAU;
        M2C_FIELD(arg1, u8 *, 1) = (u8) (temp_r3 - 0xFA);
        return;
    }
    M2C_FIELD(arg0, u8 *, 1) = (u8) temp_r3;
    M2C_FIELD(arg1, s8 *, 0) = 0;
}
