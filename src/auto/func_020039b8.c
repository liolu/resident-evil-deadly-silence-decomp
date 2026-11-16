/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_020035e4(M2C_UNK, s32, M2C_UNK, s32);
M2C_UNK func_021060e8(s32, s32, s32);
extern M2C_UNK data_0213b2b4;

void func_020039b8(M2C_UNK arg0, s32 arg1) {
    volatile s32 sp0;
    s32 temp_r4;

    temp_r4 = arg1 << 5;
    sp0     = 0;
    func_021060e8(sp0, M2C_FIELD(&data_0213b2b4, s32 *, 0xC8), temp_r4);
    func_020035e4(arg0, M2C_FIELD(&data_0213b2b4, s32 *, 0xC8), 0, temp_r4);
}
