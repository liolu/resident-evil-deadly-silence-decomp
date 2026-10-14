/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_0211851c(M2C_UNK, M2C_UNK);

void func_02012b30(s32 arg0, s32 arg1) {
    M2C_FIELD(arg1, s32 *, 0) = (s32) (M2C_FIELD(arg1, s32 *, 0) + func_0211851c((s32) M2C_FIELD(arg1, s16 *, 0x12), 0x64));
    M2C_FIELD(arg1, s16 *, 0x12) = (s16) (M2C_FIELD(arg1, s16 *, 0x12) - 0x14);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (M2C_FIELD(arg1, u8 *, 0xE4) - 1);
    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0) {
        M2C_FIELD(arg1, u8 *, 0xE4) = 0x1EU;
        M2C_FIELD(arg0, s8 *, 5) = 1;
        M2C_FIELD(arg1, s8 *, 0xEB) = 1;
    }
}
