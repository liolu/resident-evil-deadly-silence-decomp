/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_021020b8(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_02102120(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_021046d4(M2C_UNK, M2C_UNK);            /* extern */

void func_02005de8(s32 arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    func_021046d4(arg1, arg3);
    if (arg0 == 0) {
        func_02102120(arg1, arg2, arg3);
        return;
    }
    func_021020b8(arg1, arg2, arg3);
}
