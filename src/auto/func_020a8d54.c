/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020ac214(M2C_UNK);                         /* extern */
extern M2C_UNK data_0213bdcc;

s32 func_020a8d54(void *arg0) {
    s32 var_r0;

    M2C_FIELD(arg0, s8 *, 0x92) = 0x15;
    M2C_FIELD(arg0, s8 *, 0x93) = 0;
    var_r0                      = M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 1;
    if (var_r0 != 0) {
        var_r0 = func_020ac214(0);
    }
    return var_r0;
}
