/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02101f34(M2C_UNK, s32, M2C_UNK);       /* extern */
M2C_UNK func_02101f94(M2C_UNK, s32, M2C_UNK);       /* extern */
M2C_UNK func_021046d4(M2C_UNK, M2C_UNK);            /* extern */

void func_02005e44(s32 arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    s32 temp_r4;

    temp_r4 = arg2 << 5;
    func_021046d4(arg1, arg3);
    if (arg0 == 0) {
        *(s32 *) 0x04000000 = (*(s32 *) 0x04000000 & 0xFFCFFFEF) | 0x10;
        func_02101f94(arg1, temp_r4, arg3);
        return;
    }
    *(s32 *) 0x04001000 = (*(s32 *) 0x04001000 & 0xFFCFFFEF) | 0x10;
    func_02101f34(arg1, temp_r4, arg3);
}
