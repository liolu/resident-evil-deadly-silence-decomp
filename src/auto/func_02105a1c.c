/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_01ffdcdc(M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_021028c8(M2C_UNK, M2C_UNK (*)(s32), s32); /* extern */
M2C_UNK func_02105804(M2C_UNK, M2C_UNK, u32, M2C_UNK); /* extern */
M2C_UNK func_021059ac(M2C_UNK);                     /* extern */

void func_02105a1c(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, u32 arg3, M2C_UNK (*arg4)(s32), s32 arg5) {
    func_02105804(arg0, arg1, arg3, 0);
    if (arg3 == 0) {
        if (arg4 == NULL) {
            return;
        }
        arg4(arg5);
        return;
    }
    func_021059ac(arg0);
    if (arg4 != NULL) {
        func_021028c8(arg0, arg4, arg5);
        func_01ffdcdc(arg0, arg1, arg2, (arg3 >> 2) | 0xC4000000);
        return;
    }
    func_01ffdcdc(arg0, arg1, arg2, (arg3 >> 2) | 0x84000000);
}
