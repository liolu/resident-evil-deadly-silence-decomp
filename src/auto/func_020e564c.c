/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e5e0c(M2C_UNK);

extern M2C_UNK data_02130afc;
extern M2C_UNK data_02130b18;

s32 func_020e564c(s32 arg0) {
    s32 (*temp_r1)(s32);
    s32 var_r4;

    var_r4 = 3;
    if (arg0 == 0) {
        func_020e5e0c((s32) &data_02130afc);
        return 3;
    }
    temp_r1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 (**)(s32), 0x2C);
    if (temp_r1 != NULL) {
        var_r4 = temp_r1(M2C_FIELD(arg0, s32 *, 4));
    } else {
        func_020e5e0c((s32) &data_02130b18);
    }
    return var_r4;
}
