/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e0b88(s32, s32);                    /* extern */
M2C_UNK func_020e0e98(s32);                         /* extern */
M2C_UNK func_020e0f08(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */

void func_020f263c(s32 *arg0, M2C_UNK arg1) {
    func_020e0e98(*arg0);
    func_020e0f08(*arg0, arg1, 0, 0, 0xFFFFF);
    func_020e0b88(*arg0, 0xFFFFF);
}
