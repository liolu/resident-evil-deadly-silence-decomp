/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e5e0c(M2C_UNK);

extern M2C_UNK data_02130b9c;
extern M2C_UNK data_02130bb8;

s32 func_020e57b4(s32 arg0) {
    s32 (*temp_r1)(s32);
    s32 var_r4;

    if (arg0 == 0) {
        func_020e5e0c((s32) &data_02130b9c);
        return 0;
    }
    temp_r1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0), s32 (**)(s32), 0x1C);
    if (temp_r1 != NULL) {
        var_r4 = temp_r1(M2C_FIELD(arg0, s32 *, 4));
    } else {
        var_r4 = 0;
        func_020e5e0c((s32) &data_02130bb8);
    }
    return var_r4;
}
