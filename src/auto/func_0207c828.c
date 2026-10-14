/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02053c54(s32 *);                       /* extern */
M2C_UNK func_020f4384(s32);                         /* extern */
M2C_UNK func_021061d8(s32 **, M2C_UNK, M2C_UNK);    /* extern */

void func_0207c828(s32 **arg0) {
    s32 temp_r0;

    temp_r0 = **arg0;
    if (temp_r0 != 0) {
        func_020f4384(temp_r0 + 0x20);
    }
    func_02053c54(*arg0);
    func_021061d8(arg0, 0, 0x1E8);
}
