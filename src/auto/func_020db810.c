/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020dd470();                            /* extern */
M2C_UNK func_020dd47c();                            /* extern */
M2C_UNK func_0211035c(s32, M2C_UNK, M2C_UNK);       /* extern */

void func_020db810(s32 arg0) {
    if (arg0 == 0) {
        return;
    }
    func_020dd47c();
    func_0211035c(arg0, 0, 0x30);
    func_020dd470();
}
