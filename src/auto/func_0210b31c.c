/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0210b358(M2C_UNK, M2C_UNK *, s32 *);       /* extern */
M2C_UNK func_0210b868();                            /* extern */
extern M2C_UNK func_0210b860;

s32 func_0210b31c(M2C_UNK arg0) {
    s32 sp0;
    s32 temp_r0;

    temp_r0 = func_0210b358(arg0, &func_0210b860, &sp0);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_0210b868();
    return sp0;
}
