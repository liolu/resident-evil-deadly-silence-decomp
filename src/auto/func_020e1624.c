/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020deb88(M2C_UNK *);                   /* extern */
s32 func_020df268(s32);                             /* extern */
M2C_UNK func_020e72d8(s32, s32);                    /* extern */
extern M2C_UNK data_0212ffc8;

void func_020e1624(void *arg0, s16 arg1) {
    s32 var_r2;

    if (arg0 == NULL) {
        func_020deb88(&data_0212ffc8);
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x40) = arg1;
    if (M2C_FIELD(arg0, s8 *, 0xA9) != 1) {
        var_r2 = 0;
    } else {
        var_r2 = func_020df268(M2C_FIELD(arg0, s32 *, 4));
    }
    func_020e72d8(M2C_FIELD(arg0, s32 *, 0xC), M2C_FIELD(arg0, s16 *, 0x40) + var_r2);
}
