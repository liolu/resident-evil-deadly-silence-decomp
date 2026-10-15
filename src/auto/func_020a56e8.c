/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

s32 func_020a56e8(s32 arg0) {
    u8 temp_r0;
    u8 temp_r2;

    if ((s32) M2C_FIELD(arg0, s16 *, 0x94) < 0) {
        return 0;
    }
    temp_r2 = M2C_FIELD(arg0, u8 *, 0xA);
    if (temp_r2 & 0xC0) {
        return 0;
    }
    temp_r0 = M2C_FIELD(arg0, u8 *, 9);
    if (temp_r0 == 0x13) {
        return 0;
    }
    if (temp_r0 == 0x17) {
        return 0;
    }
    if (temp_r0 == 0x18) {
        return 0;
    }
    if ((u32) temp_r0 >= 0x20U) {
        return 0;
    }
    if (((temp_r0 == 0xD) || (temp_r0 == 0x12)) && (temp_r2 & 1)) {
        return 0;
    }
    return 1;
}
