/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_0211851c(M2C_UNK, M2C_UNK);

s32 func_02075874(s32 arg0, s32 arg1) {
    s32 temp_r4;
    s32 temp_r5;

    temp_r5 = func_0211851c((s32) (arg0 & 0x7C00) >> 0xA, arg1);
    temp_r4 = func_0211851c(arg0 & 0x1F, arg1);
    return (s32) (u16) ((u8) temp_r4 | ((u8) func_0211851c((s32) (arg0 & 0x3E0) >> 5, arg1) << 5) | ((u8) temp_r5 << 0xA));
}
