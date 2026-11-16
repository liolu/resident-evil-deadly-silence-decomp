#include "m2c.h"

s32 func_020824b0(void **arg0) {
    u8 temp_r0;

    temp_r0 = M2C_FIELD(*arg0, u8 *, 9);
    switch (temp_r0) {
        case 0:
        case 5:
        case 6:
        case 7:
            return 1;
        case 1:
            return 7;
        case 2:
            return 3;
        case 3:
            return 6;
        case 4:
            return 0x10;
        default:
            return 0x29;
    }
}
