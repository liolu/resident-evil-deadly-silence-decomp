#include "m2c.h"

s32 func_0210e544(void *arg0) {
    u16 temp_r0;
    u16 temp_r1;

    if ((u32) M2C_FIELD(arg0, u16 *, 4) > 0x70U) {
        return 0;
    }
    temp_r1 = M2C_FIELD(arg0, u16 *, 0x18);
    if (((u32) temp_r1 < 0xAU) || ((u32) temp_r1 > 0x3E8U)) {
        return 0;
    }
    temp_r0 = M2C_FIELD(arg0, u16 *, 0x32);
    if (((u32) temp_r0 < 1U) || ((u32) temp_r0 > 0xEU)) {
        return 0;
    }
    return 1;
}
