/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02005648();                            /* extern */
s32 func_02005984();                                /* extern */
M2C_UNK func_02005c9c();                            /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213ad30;
extern M2C_UNK data_0213b890;

void func_020c34ac(void) {
    s32 var_r0;

    var_r0 = func_02005984();
    if (M2C_FIELD(&data_0213ad30, u16 *, 2) & 8) {
        var_r0                             = 1;
        M2C_FIELD(&data_0213b890, s8 *, 7) = 1;
    }
    if (var_r0 != 0) {
        func_02005648();
        func_020c4798(2);
        return;
    }
    func_02005c9c();
}
