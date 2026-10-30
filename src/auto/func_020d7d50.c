/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d87f0();                            /* extern */
s32 func_0210e344(M2C_UNK *);                       /* extern */
extern M2C_UNK func_020d7cac;

s32 func_020d7d50(void) {
    if (func_0210e344(&func_020d7cac) == 2) {
        return 1;
    }
    func_020d87f0();
    return 0;
}
