/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern void *data_02137298;

void func_020074d8(void) {
    s32 var_r3;
    s8 var_r3_2;
    u8 *base;

    var_r3 = 0;
    base   = (u8 *) data_02137298;
    if (base[0x3EAA] & 2) {
        if (((volatile u8 *) base)[0x3EAA] & 4) {
            var_r3 = 1;
        }
    }
    if (var_r3 != 0) {
        var_r3_2 = 1;
    } else {
        var_r3_2 = 0;
    }
    M2C_FIELD(data_02137298, s8 *, 0x3EA9) = var_r3_2;
    M2C_FIELD(data_02137298, u8 *, 0x3EAA) = (u8) (M2C_FIELD(data_02137298, u8 *, 0x3EAA) & ~2);
    M2C_FIELD(data_02137298, u8 *, 0x3EAA) = (u8) (M2C_FIELD(data_02137298, u8 *, 0x3EAA) & ~4);
}
