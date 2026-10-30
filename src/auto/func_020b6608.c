/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b64fc(s32);                         /* extern */
M2C_UNK func_020b6530(s32);                         /* extern */

void func_020b6608(s32 arg0, s32 arg1) {
    if (arg0 & (1 << (arg1 + 3))) {
        func_020b6530(arg1);
        return;
    }
    func_020b64fc(arg1);
}
