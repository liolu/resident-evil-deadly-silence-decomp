/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_02158820[];
extern s32 data_027e0248[];

void func_021029a0(u32 arg0, s32 arg1) {
    s32 var_r8;
    u8 *var_r7;
    u32 var_r0;

    var_r0 = arg0;
    var_r8 = 0;
    do {
        if (var_r0 & 1) {
            var_r7 = NULL;
            if (var_r8 >= 8 && var_r8 <= 0xB) {
                var_r7 = data_02158820 + (var_r8 - 8) * 0xC;
            } else if (var_r8 >= 3 && var_r8 <= 6) {
                var_r7 = data_02158820 + (var_r8 + 1) * 0xC;
            } else {
                data_027e0248[var_r8] = arg1;
            }
            if (var_r7 != NULL) {
                *(s32 *) (var_r7 + 0) = arg1;
                *(s32 *) (var_r7 + 8) = 0;
                *(s32 *) (var_r7 + 4) = 1;
            }
        }
        var_r8 += 1;
        var_r0 = var_r0 >> 1;
    } while (var_r8 < 0x16);
}
