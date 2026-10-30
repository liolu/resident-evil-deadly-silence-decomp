/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207729c(s32);                         /* extern */

void func_02083b48(s32 arg0) {
    s32 temp_r8;
    s32 var_r7;

    var_r7 = 0;
    do {
        temp_r8 = (var_r7 * 0xC) + (arg0 + 8);
        if (M2C_FIELD(temp_r8, u8 *, 8) != 0) {
            func_0207729c(M2C_FIELD(temp_r8, s32 *, 0) + 4);
            M2C_FIELD(temp_r8, u8 *, 8) = 0U;
        }
        var_r7 += 1;
    } while (var_r7 < 0x11);
}
