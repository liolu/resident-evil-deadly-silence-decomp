/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern s32 data_0215400c;

u16 func_020e8a7c(void *arg0, s32 arg1) {
    u16 temp_lr;
    u16 temp_r0;

    temp_lr = *(u16 *)0x04000208;
    *(u16 *)0x04000208 = 0;
    data_0215400c = 1;
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) - arg1);
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) + arg1);
    data_0215400c = 0;
    temp_r0 = *(u16 *)0x04000208;
    *(u16 *)0x04000208 = temp_lr;
    return temp_r0;
}
