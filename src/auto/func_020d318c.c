/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020d311c();                                /* extern */
extern M2C_UNK data_0213b890;

s32 func_020d318c(void) {
    s32 var_r0;

    var_r0 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u16 *, 0x4E) & 0xFF00;
    if (var_r0 != 0) {
        var_r0 = func_020d311c();
    }
    return var_r0;
}
