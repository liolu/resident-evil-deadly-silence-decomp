/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02091a5c(M2C_UNK, M2C_UNK *);          /* extern */
s32 func_02117970(s32, s32);                        /* extern */
s32 func_02117e68(s32);                             /* extern */
extern M2C_UNK data_02137300;

void func_0201407c(M2C_UNK arg0, M2C_UNK arg1) {
    u8 sp0[4];
    u8 sp4[4];
    s32 temp_r0;
    s32 var_r5;
    s32 *out;
    void *temp_r1;

    func_02091a5c(arg0, (M2C_UNK *) sp0);
    func_02091a5c(arg1, (M2C_UNK *) sp4);
    var_r5 = 1;
    do {
        temp_r0 = func_02117970(func_02117e68(sp4[var_r5] - sp0[var_r5]), 0x40C00000);
        temp_r1 = (u8 *) &data_02137300 + (var_r5 * 4);
        var_r5 += 1;
        M2C_FIELD(temp_r1, s32 *, -4) = temp_r0;
    } while (var_r5 < 4);
}
