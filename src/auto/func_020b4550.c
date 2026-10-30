/* compiler: 1.2/sp2p3 -O2 */
#include "m2c.h"

M2C_UNK func_02017c64(s32);                         /* extern */
extern s32 data_0213daa8;
extern M2C_UNK data_021489a0;
extern M2C_UNK data_0214bcc0;

s32 func_020b4550(void) {
    s32 var_r6;

    var_r6 = 0;
    data_0213daa8 += 2;
    M2C_FIELD(&data_0214bcc0, s8 *, 0x7A0) = 0;
    do {
        func_02017c64((var_r6 * 0xBC) + (s32) &data_021489a0);
        var_r6 += 1;
    } while (var_r6 < 0x50);
    return 1;
}
