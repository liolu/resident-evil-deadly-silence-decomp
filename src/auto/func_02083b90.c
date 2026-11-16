/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_02083ae0(void *, s32);
void func_020a0518(void *, u8, s32, s32);
extern u8 data_0211f2ac[];

void func_02083b90(u8 *arg0) {
    s32 var_r9;
    u8 *temp_r0;

    var_r9 = 0;
    do {
        temp_r0    = arg0 + 8 + var_r9 * 0xC;
        temp_r0[8] = 0;
        if (*(u16 *) (*(u8 **) (arg0 + 0xD4) + 0xA) & (1 << var_r9)) {
            temp_r0[8] = 1;
            temp_r0[9] = data_0211f2ac[var_r9 * 3];
            func_020a0518(temp_r0, data_0211f2ac[var_r9 * 3 + 1], 0, 0);
            func_02083ae0(arg0, var_r9);
        }
        var_r9 += 1;
    } while (var_r9 < 8);
}
