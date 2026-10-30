/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d87f0();                            /* extern */
s32 func_0210e490(M2C_UNK *);                       /* extern */
extern M2C_UNK func_020d8150;

s32 func_020d8180(void) {
    if (func_0210e490(&func_020d8150) == 2) {
        return 1;
    }
    func_020d87f0();
    return 0;
}
