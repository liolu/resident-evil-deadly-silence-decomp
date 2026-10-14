/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0200464c(M2C_UNK, M2C_UNK, M2C_UNK *);     /* extern */
M2C_UNK func_0210c0bc(u16);                         /* extern */
M2C_UNK func_0210c0cc(u16);                         /* extern */
extern M2C_UNK data_02136eb0;
extern M2C_UNK data_02136fb0;

s32 func_020046ac(void) {
    M2C_UNK sp0;
    s32 var_r4;

    var_r4 = 0;
    if (M2C_FIELD(&data_02136eb0, u8 *, 0x1A5) != 1) {
        func_0210c0cc(M2C_FIELD(&data_02136fb0, u16 *, 0xA6));
        var_r4 = func_0200464c(0, 1, &sp0);
        func_0210c0bc(M2C_FIELD(&data_02136fb0, u16 *, 0xA6));
    }
    return var_r4;
}
