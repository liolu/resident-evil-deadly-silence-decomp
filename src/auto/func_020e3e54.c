/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020e3de4(M2C_UNK);                         /* extern */
M2C_UNK func_020e4254();                            /* extern */
M2C_UNK func_020e4260();                            /* extern */

s32 func_020e3e54(M2C_UNK arg0) {
    s32 temp_r4;

    func_020e4260();
    temp_r4 = func_020e3de4(arg0);
    func_020e4254();
    return temp_r4;
}
