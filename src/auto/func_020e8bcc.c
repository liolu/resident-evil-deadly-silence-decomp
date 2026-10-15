/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e8bcc(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg5, s32 *, 0x18);
    if (temp_r0 != 0) {
        M2C_FIELD(arg5, s32 *, 0x18) = (s32) (temp_r0 - arg3);
        M2C_FIELD(arg5, s32 *, 0x20) = (s32) (M2C_FIELD(arg5, s32 *, 0x20) + ((u32) arg3 >> 1));
    }
    M2C_FIELD(arg5, u32 *, 0x1C) = (u32) (M2C_FIELD(arg5, u32 *, 0x1C) + arg3);
    if ((u32) M2C_FIELD(arg5, u32 *, 0x1C) > 0x4000U) {
        M2C_FIELD(arg5, u32 *, 0x1C) = 0x4000U;
    }
}
