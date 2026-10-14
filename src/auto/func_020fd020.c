/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020f27c8(M2C_UNK, M2C_UNK);
void func_020fca88(M2C_UNK);

extern M2C_UNK data_02157c24;

void func_020fd020(s32 arg0) {
    func_020fca88(M2C_FIELD(arg0, s32 *, 0x40));
    func_020f27c8((s32) &data_02157c24, arg0);
    M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) & ~1);
}
