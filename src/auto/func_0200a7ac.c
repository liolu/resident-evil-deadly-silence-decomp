/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_0200d1f4(void *, s32, s32);              /* extern */
extern void *data_02137298;

s32 func_0200a7ac(void) {
    s32 var_r6;
    s32 var_r5;
    void *temp_r0;
    void *temp_r0_2;
    u8 *temp_r4;

    var_r5 = 0;
    var_r6 = var_r5;
    do {
        temp_r0   = M2C_FIELD(data_02137298, void **, 0x1414);
        temp_r4   = (u8 *) data_02137298 + 0x1840 + (var_r6 * 8);
        temp_r0_2 = func_0200d1f4(temp_r0, var_r6, M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x88), s32 *, 0x18));
        if (temp_r0_2 != NULL) {
            var_r5 += 1;
            M2C_FIELD(temp_r4, u8 *, 2)  = (u8) M2C_FIELD(temp_r0_2, u8 *, 0);
            M2C_FIELD(temp_r4, u16 *, 4) = (u16) M2C_FIELD(temp_r0_2, u16 *, 2);
            M2C_FIELD(temp_r4, u8 *, 6)  = 0x7F;
        }
        var_r6 += 1;
    } while (var_r6 < 0x20);
    return var_r5;
}
