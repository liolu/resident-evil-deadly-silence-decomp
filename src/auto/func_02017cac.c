/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_02017d38(s32, s32);
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_021489a0;
extern M2C_UNK data_0214bcc0;

s32 func_02017cac(void) {
    s32 var_r0;
    s32 var_r4;
    u8 *base;

    base   = (u8 *) &data_0214bcc0;
    var_r0 = *(s8 *) (base + 0x700 + 0xA0);
    if (var_r0 == 0) {
        return -1;
    }
    *(s8 *) (base + 0x7A0) = var_r0 - 1;
    var_r4                 = 0x4F;
    goto check;
loop:
    if (*(u8 *) ((u8 *) &data_02143cc0 + (var_r4 * 0xBC) + 0x4CE0) == 0) {
        goto done;
    }
    var_r4 -= 1;
check:
    if (var_r4 >= 0) {
        goto loop;
    }
done:
    var_r0 = -1;
    if (var_r4 != var_r0) {
        func_02017d38((s32) ((u8 *) &data_021489a0 + (var_r4 * 0xBC)), 1);
        var_r0 = var_r4;
    }
    return var_r0;
}
