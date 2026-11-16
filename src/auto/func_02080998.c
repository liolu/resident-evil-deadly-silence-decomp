/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02080998(s32 arg0) {
    u32 temp_r0;

    if (arg0 > 3) {
        goto big;
    }
    if (arg0 != 3) {
        goto zero;
    }
    goto one;

big:
    temp_r0 = arg0 - 0x13;
    switch (temp_r0) {
        case 0:
        case 9:
        case 12:
        case 14:
            goto one;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
        case 13:
        default:
            goto zero;
    }

one:
    return 1;

zero:
    return 0;
}
