/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d87f0();                            /* extern */
M2C_UNK func_020d880c(M2C_UNK);                     /* extern */
s32 func_0210e78c(M2C_UNK *);                       /* extern */
extern M2C_UNK func_020d81b4;

s32 func_020d8210(void) {
    func_020d880c(3);
    if (func_0210e78c(&func_020d81b4) == 2) {
        return 1;
    }
    func_020d87f0();
    return 0;
}
