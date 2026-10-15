/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0210a65c();                            /* extern */
s32 func_0210aa2c(M2C_UNK, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK data_0215a864;
extern M2C_UNK func_0210a674;

s32 func_0210a9e8(M2C_UNK arg0) {
    s32 temp_r0;

    temp_r0                               = func_0210aa2c(arg0, &func_0210a674, 0);
    M2C_FIELD(&data_0215a864, s32 *, 0xC) = temp_r0;
    if (temp_r0 == 0) {
        func_0210a65c();
    }
    return M2C_FIELD(&data_0215a864, s32 *, 0xC);
}
