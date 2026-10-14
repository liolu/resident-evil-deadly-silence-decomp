/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0210b238(M2C_UNK *, s32 *);                /* extern */
M2C_UNK func_0210b868();                            /* extern */
extern M2C_UNK func_0210b860;

s32 func_0210b1fc(void) {
    s32 sp0;
    s32 temp_r0;

    temp_r0 = func_0210b238(&func_0210b860, &sp0);
    if (temp_r0 != 0) {
        return temp_r0;
    }
    func_0210b868();
    return sp0;
}
