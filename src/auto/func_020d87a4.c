/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d87f0();                            /* extern */
M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
s32 func_0210e594(M2C_UNK *, M2C_UNK *);            /* extern */
extern M2C_UNK data_02141cc0;
extern M2C_UNK func_020d8734;

s32 func_020d87a4(void) {
    func_020d880c(3);
    if (func_0210e594(&func_020d8734, &data_02141cc0) == 2) {
        return 1;
    }
    func_020d87f0();
    func_020d880c(9);
    return 0;
}
