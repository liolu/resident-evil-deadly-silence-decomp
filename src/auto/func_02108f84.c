/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02107e90(void *, s32);                     /* extern */
M2C_UNK func_0210800c(void *, s32);                 /* extern */
M2C_UNK func_02108fcc();                            /* extern */
s32 func_02109070(s32);                             /* extern */

s32 func_02108f84(void *arg0) {
    func_0210800c(arg0, func_02107e90(arg0, M2C_FIELD(arg0, s32 *, 0x10)));
    if (func_02109070(M2C_FIELD(arg0, s32 *, 8)) != 0) {
        func_02108fcc();
    }
    if (M2C_FIELD(arg0, s32 *, 0x14) == 0) {
        return 1;
    }
    return 0;
}
