#include "m2c.h"

s32 func_020f476c(u8 *arg0, void *arg1) {
    u8 temp_r0;

    temp_r0 = *arg0;
    switch (temp_r0) {                              /* irregular */
        case 0x4D:
            return ((M2C_FIELD(arg1, u8 *, 0x18) * 2) + 0x1C) & ~3;
        case 0x4A:
        case 0x56:
            return ((M2C_FIELD(arg1, u8 *, 0x17) * 2) + 0x1C) & ~3;
        default:
            return 0;
    }
}
