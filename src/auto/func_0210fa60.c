/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02102a44();                            /* extern */
M2C_UNK func_021054c0(s32);                         /* extern */

void func_0210fa60(s32 arg0, void *arg1) {
    if (M2C_FIELD(arg1, s32 *, 0) == 0) {
        func_02102a44(arg0);
    }
    func_021054c0(M2C_FIELD(arg1, s32 *, 4));
}
