/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e8c0c(void *);                      /* extern */
M2C_UNK func_02116dac(M2C_UNK, s32);                /* extern */
s32 func_02117970(s32, s32);                        /* extern */
s32 func_02117dac();                                /* extern */
s32 func_02117e68(M2C_UNK);                         /* extern */

void func_020e8b80(void *arg0, M2C_UNK arg1) {
    if (arg0 == NULL) {
        return;
    }
    func_02116dac(0x3F000000, func_02117970(0x48FFB0E0, func_02117e68(arg1)));
    M2C_FIELD(arg0, s32 *, 0x10) = func_02117dac();
    func_020e8c0c(arg0);
}
