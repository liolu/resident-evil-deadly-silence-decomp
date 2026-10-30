/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02117970(s32, s32);                        /* extern */
s32 func_02117e20(s32);                             /* extern */
s32 func_02117e68(s32);                             /* extern */

s32 func_02007628(void *arg0, s32 arg1, u8 arg2, s32 arg3, s32 arg4) {
    s32 temp_r6;

    if (M2C_FIELD(arg0, s32 *, 0x14) != 3) {
        return -7;
    }
    M2C_FIELD(arg0, s32 *, 0)    = arg4;
    M2C_FIELD(arg0, u8 *, 0xC)   = arg2;
    M2C_FIELD(arg0, s32 *, 4)    = func_02117e68(arg1);
    temp_r6                      = func_02117e68(M2C_FIELD(arg0, u8 *, 0xC) - arg1);
    M2C_FIELD(arg0, s32 *, 8)    = func_02117970(temp_r6, func_02117e20(M2C_FIELD(arg0, s32 *, 0)));
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) (arg4 & 0xFF000000);
    M2C_FIELD(arg0, s32 *, 0x14) = arg3;
    M2C_FIELD(arg0, s8 *, 0xD)   = 7;
    return 0;
}
