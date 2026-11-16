#include "m2c.h"

s32 func_020808a8(u32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return 1;
    }
    switch (arg0) {
        case 3:
        case 4:
            if (arg1 == 8) {
                return 1;
            }
            break;
        case 1:
        case 8:
            if (arg1 == 4) {
                return 1;
            }
            break;
        case 2:
            if (arg1 == 6) {
                return 1;
            }
            break;
        default:
            break;
    }
    return 0;
}
