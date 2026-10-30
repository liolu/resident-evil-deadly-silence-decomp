/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s8 func_020133a8(M2C_UNK);                          /* extern */
M2C_UNK func_020b8324(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213ad3c;
extern M2C_UNK data_0213ad98;

s32 func_020c0148(void *arg0) {
    s32 var_r5;
    s8 var_r0;
    u8 temp_r1;

    if (M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80) {
        return 0;
    }
    var_r5 = 0;
    var_r0 = func_020133a8(3);
    if (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x20) {
        var_r0 = M2C_FIELD(arg0, s8 *, 1);
    }
    temp_r1 = (u8) M2C_FIELD(arg0, s8 *, 1);
    if ((temp_r1 == var_r0) && (temp_r1 == 1)) {
        var_r5                   = 1;
        M2C_FIELD(arg0, s8 *, 0) = 1;
        func_020b8324(2);
    }
    return var_r5;
}
