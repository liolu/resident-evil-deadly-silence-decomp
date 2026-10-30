/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0209f4c8(void *, M2C_UNK, M2C_UNK *, s32, s32); /* extern */
extern M2C_UNK data_02120c4c;
extern void *data_02137ed8;

void *func_02098ddc(void) {
    u32 var_r0;

    var_r0 = (u32) (M2C_FIELD(data_02137ed8, u8 *, 0x24AF) << 0x1D) >> 0x1F;
    if (var_r0 == 0) {
        func_0209f4c8(data_02137ed8 + 0x39C, 2, &data_02120c4c, 0xE740, 0);
        var_r0                         = (u32) (data_02137ed8 + 0x2000);
        M2C_FIELD(var_r0, u8 *, 0x4AF) = (u8) (M2C_FIELD(var_r0, u8 *, 0x4AF) | 4);
    }
    return (void *) var_r0;
}
