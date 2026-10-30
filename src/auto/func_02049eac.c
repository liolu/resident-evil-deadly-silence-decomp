/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 Sqrt(s32);                                      /* extern */
s16 func_01ff9fd8(s32, s32, s32, s32);              /* extern */
M2C_UNK func_01ffd504(M2C_UNK);                     /* extern */

void func_02049eac(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r0;
    s32 temp_r1;
    s32 temp_r2;

    temp_r2 = arg2 - M2C_FIELD(arg0, s32 *, 0x38);
    temp_r1 = arg1 - M2C_FIELD(arg0, s32 *, 0x30);
    temp_r0 = Sqrt((temp_r1 * temp_r1) + (temp_r2 * temp_r2)) - arg3;
    if (temp_r0 > 0) {
        M2C_FIELD(arg0, s16 *, 0xA6) = (s16) temp_r0;
        M2C_FIELD(arg0, s16 *, 0x44) = func_01ff9fd8(M2C_FIELD(arg0, s32 *, 0x30), M2C_FIELD(arg0, s32 *, 0x38), arg1, arg2);
        func_01ffd504(0);
    }
}
