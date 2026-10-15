#include "engine.h"
#include "m2c.h"

s32 func_02110004(s32 arg0) {
    u32 temp_r0;
    u32 temp_r0_2;
    u32 temp_r0_3;
    u32 temp_r1;

    temp_r0_2 = arg0 - (0x55555555 & ((u32) arg0 >> 1));
    temp_r1   = (temp_r0_2 & 0x33333333) + (0x33333333 & (temp_r0_2 >> 2));
    temp_r0_3 = (temp_r1 + (temp_r1 >> 4)) & 0x0F0F0F0F;
    temp_r0   = temp_r0_3 + (temp_r0_3 >> 8);
    return (s32) (u8) (temp_r0 + (temp_r0 >> 0x10));
}
