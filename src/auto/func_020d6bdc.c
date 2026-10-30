/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
M2C_UNK func_02105528();                            /* extern */
s32 func_0210e69c(M2C_UNK *);                       /* extern */
extern M2C_UNK data_02141cc0;
extern M2C_UNK func_020d758c;

s32 func_020d6bdc(void) {
    if (M2C_FIELD(&data_02141cc0, s32 *, 0x40) != 1) {
        func_02105528();
    }
    func_020d880c(3);
    if (func_0210e69c(&func_020d758c) == 2) {
        return 1;
    }
    func_020d880c(9);
    return 0;
}
