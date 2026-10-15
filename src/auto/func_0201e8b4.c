/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s16 func_0201e8b4(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s16 temp_r1;

    temp_r1                      = (arg2 * M2C_FIELD(arg0, u8 *, 0xA0)) + arg1;
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) - temp_r1);
    if ((s32) M2C_FIELD(arg0, s32 *, 0x34) > arg3) {
        M2C_FIELD(arg0, s32 *, 0x34) = arg3;
        return temp_r1;
    }
    M2C_FIELD(arg0, u8 *, 0xA0) = (u8) (M2C_FIELD(arg0, u8 *, 0xA0) + 1);
    return 0;
}
