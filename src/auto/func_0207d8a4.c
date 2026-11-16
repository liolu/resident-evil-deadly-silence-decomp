/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u32 func_02084b48(void *, M2C_UNK *);               /* extern */
s32 func_02087f48();                                /* extern */
M2C_UNK func_02118e7c(M2C_UNK *, M2C_UNK);          /* extern */

void func_0207d8a4(void *arg0) {
    s32 sp0[4];
    u8 var_r0;

    func_02118e7c(sp0, 0x10);
    if (func_02084b48(arg0, sp0) < 0x1600U) {
        M2C_FIELD(arg0, u8 *, 7) = (u8) (M2C_FIELD(arg0, u8 *, 7) & ~4);
        return;
    }
    if ((u32) (func_02087f48() & 0x1F) < (u32) M2C_FIELD(arg0, u8 *, 0x16)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    M2C_FIELD(arg0, u8 *, 7) = (u8) ((M2C_FIELD(arg0, u8 *, 7) & ~4) | ((var_r0 & 1) * 4));
}
