/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d6d4c();                            /* extern */
M2C_UNK func_020d87f0();                            /* extern */
M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
s32 func_0210e16c(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK func_020d7634;

s32 func_020d7664(void) {
    func_020d880c(3);
    if (func_0210e16c(&func_020d7634, 0) == 2) {
        return 1;
    }
    func_020d87f0();
    func_020d6d4c();
    return 0;
}
