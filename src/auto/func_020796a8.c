/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020b39e4(M2C_UNK *, s32);                  /* extern */
extern M2C_UNK data_0211e778;
extern M2C_UNK data_0213be84;

u8 func_020796a8(void) {
    u32 var_r8;
    u8 var_r7;

    var_r7 = 0;
    var_r8 = 0;
    do {
        if (func_020b39e4(&data_0213be84, var_r8 + 0x10) != 0) {
            var_r7 |= 1 << ((u8 *) &data_0211e778)[var_r8];
        }
        var_r8 += 1;
    } while (var_r8 < 0xBU);
    return var_r7;
}
