/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02059b28();                                /* extern */
extern M2C_UNK data_0211d5fc;
extern M2C_UNK data_0211d6f4;
extern M2C_UNK data_0211d790;

u32 func_02059bcc(s32 arg0, u32 arg1) {
    s32 temp_r0;
    s32 temp_r1;
    u16 var_r2;

    temp_r0 = func_02059b28();
    if (temp_r0 == 2) {
        return arg1;
    }
    var_r2 = 0x7FFF;
    if (arg1 & 0x80) {
        temp_r1 = arg1 & ~0x80;
        if (temp_r1 <= 0x7B) {
            var_r2 = *((u16 *) ((s8 *) &data_0211d790 + (temp_r1 * 2)));
        }
    } else if (temp_r0 == 0) {
        if (arg1 <= 0xC0U) {
            var_r2 = *((u16 *) ((s8 *) &data_0211d6f4 + (arg1 * 2)));
        }
    } else if (arg1 <= 0xA7U) {
        var_r2 = *((u16 *) ((s8 *) &data_0211d5fc + (arg1 * 2)));
    }
    if (var_r2 == 0x7FFF) {
        var_r2 = 0x8000;
    }
    return (u32) var_r2;
}
