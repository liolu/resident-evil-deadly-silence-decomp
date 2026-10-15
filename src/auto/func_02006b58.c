/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0210a9e8(void *);                          /* extern */
s32 func_0210aa2c(void *, M2C_UNK *, M2C_UNK);      /* extern */
extern void *data_02137298;
extern M2C_UNK func_02007344;

s32 func_02006b58(s32 arg0) {
    s32 var_r0;
    s32 var_r0_2;

    var_r0_2 = arg0;
    switch (var_r0_2) {                             /* irregular */
        case 0:
            var_r0_2 = func_0210a9e8(data_02137298 + 0x3EEC);
            if (var_r0_2 == 0) {
                M2C_FIELD(data_02137298, u8 *, 0x3EAA) = (u8) (M2C_FIELD(data_02137298, u8 *, 0x3EAA) | 1);
            } else {
                M2C_FIELD(data_02137298, u8 *, 0x3EAA) = (u8) (M2C_FIELD(data_02137298, u8 *, 0x3EAA) & ~1);
            }
            break;
        case 1:
            M2C_FIELD(data_02137298, u8 *, 0x3EAA) = (u8) (M2C_FIELD(data_02137298, u8 *, 0x3EAA) & ~1);
            var_r0_2                               = func_0210aa2c(data_02137298 + 0x3EEC, &func_02007344, 0);
            break;
    }
    if (var_r0_2 != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    return 0 - var_r0;
}
