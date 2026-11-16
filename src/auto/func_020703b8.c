/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020702c0(void *, s32, s32);
s32 func_02070324(void *, s32);
s32 func_020704b0(void);
M2C_UNK func_020f3224(void *, s32);
M2C_UNK func_021046d4(s32, s32);
M2C_UNK func_021094a0(void *);
extern M2C_UNK data_0213b3ac;

s32 func_020703b8(s32 arg0) {
    u8 sp0[0x44];
    s32 temp_r0;
    s32 var_r5;

    temp_r0 = func_02070324(sp0, arg0);
    if (temp_r0 <= 0) {
        return 0;
    }
    var_r5 = func_020704b0();
    if (func_020702c0(sp0, var_r5, temp_r0) == 0) {
        func_020f3224(&data_0213b3ac, var_r5);
        var_r5 = 0;
    } else {
        func_021046d4(var_r5, temp_r0);
    }
    func_021094a0(sp0);
    return var_r5;
}
