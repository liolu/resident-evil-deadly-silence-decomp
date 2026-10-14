/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020fd118(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_020fd178(s32);                         /* extern */

s32 func_020e8808(s32 arg0, s32 arg1) {
    func_020fd178(arg0 + 0x24);
    func_020fd118(arg0 + 0x24, 0, 0);
    return arg1;
}
