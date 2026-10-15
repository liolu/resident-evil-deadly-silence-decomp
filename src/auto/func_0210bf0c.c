/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0210b8d0();                            /* extern */
s32 func_0210bf50(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK data_0215a8e0;
extern M2C_UNK func_0210b8e8;

s32 func_0210bf0c(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r0;

    temp_r0                                = func_0210bf50(arg0, arg1, &func_0210b8e8, 0);
    M2C_FIELD(&data_0215a8e0, s32 *, 0x20) = temp_r0;
    if (temp_r0 == 0) {
        func_0210b8d0();
    }
    return M2C_FIELD(&data_0215a8e0, s32 *, 0x20);
}
