/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02117dac(M2C_UNK);
M2C_UNK func_02117eb0(M2C_UNK, M2C_UNK);

void func_02091590(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x24) = func_02117dac(func_02117eb0(0x45800000, arg1));
    M2C_FIELD(arg0, s32 *, 0x28) = func_02117dac(func_02117eb0(0x45800000, arg2));
}
