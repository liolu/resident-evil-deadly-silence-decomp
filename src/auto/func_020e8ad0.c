/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern s32 data_0215400c;

u16 func_020e8ad0(void *arg0, s32 *arg1, s32 *arg2) {
    u16 temp_r0;
    u16 temp_r4;

    temp_r4 = *(u16 *)0x04000208;
    *(u16 *)0x04000208 = 0;
    data_0215400c = 1;
    *arg1 = M2C_FIELD(arg0, s32 *, 0x1C);
    *arg2 = M2C_FIELD(arg0, s32 *, 0x18);
    data_0215400c = 0;
    temp_r0 = *(u16 *)0x04000208;
    *(u16 *)0x04000208 = temp_r4;
    return temp_r0;
}
