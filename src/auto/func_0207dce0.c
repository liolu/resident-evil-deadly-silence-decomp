/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02082348(M2C_UNK);
void func_020834dc(M2C_UNK);
void func_02084a1c(M2C_UNK, M2C_UNK, M2C_UNK);

void func_0207dce0(s32 arg0) {
    u32 temp_r0;

    temp_r0 = (u32) func_02082348(arg0);
    if ((temp_r0 >= 0xBU) && (temp_r0 < 0x22U)) {
        func_02084a1c(arg0, (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u16 *, 0x44), M2C_FIELD(arg0, s32 *, 0x1CC) + M2C_FIELD(arg0, s32 *, 0x1D0));
        M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) (M2C_FIELD(arg0, s32 *, 0x1D0) - 3);
        M2C_FIELD(arg0, u8 *, 5) = (u8) (M2C_FIELD(arg0, u8 *, 5) | 8);
    } else {
        M2C_FIELD(arg0, u8 *, 5) = (u8) (M2C_FIELD(arg0, u8 *, 5) & ~8);
    }
    func_020834dc(arg0);
}
