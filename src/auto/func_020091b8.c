/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_0200e098(s32, u8, s32);
u16 func_02107658(s32);
s32 func_0211851c(s32, s32);
extern s16 data_0212bd68[];

void func_020091b8(s32 arg0, s32 arg1) {
    u32 var_r8;
    u8 *temp_r7;
    u16 temp_r0;
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;

    var_r4 = -1;
    var_r5 = 1;
    var_r6 = 0x7F;
    var_r8 = 0;
    do {
        temp_r7 = (u8 *) arg0 + var_r8;
        if (M2C_FIELD(temp_r7, u8 *, 0xE9) != var_r4) {
            temp_r0 = func_02107658(data_0212bd68[func_0211851c(arg1 * M2C_FIELD(temp_r7, u8 *, 0xEB), var_r6)]);
            func_0200e098(var_r5 << M2C_FIELD(temp_r7, u8 *, 0xE9), (u8) temp_r0, (s32) temp_r0 >> 8);
        }
        var_r8 += 1;
    } while (var_r8 < 2);
}
