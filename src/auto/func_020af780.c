/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02091c78(M2C_UNK);
void func_0210626c(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213b2b4;

s32 func_020af780(s32 arg0, s32 arg1) {
    s32 temp_r0;

    temp_r0 = func_02091c78(arg0);
    func_0210626c(M2C_FIELD(&data_0213b2b4, s32 *, 0xC8), arg1, temp_r0);
    return temp_r0;
}
