/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02075738();          /* extern */
s32 func_02090c30();      /* extern */
M2C_UNK func_02091118();                  /* extern */
M2C_UNK func_020a835c();                      /* extern */
M2C_UNK func_020a840c();                            /* extern */
M2C_UNK func_020adf5c();                     /* extern */
extern void *data_027e000c;

s32 func_02091014(s32 arg0, M2C_UNK arg1, s32 arg2) {
    s32 temp_r3;
    s32 var_r4;

    temp_r3 = arg2 & 7;
    if (temp_r3 != 0) {
        var_r4 = func_02090c30(arg0, arg1, arg2, 1);
    } else {
        var_r4 = func_02075738(arg0, arg1, arg2, temp_r3);
        if ((var_r4 != 0) && (arg0 & 1)) {
            func_02075738(arg0, arg1);
        }
    }
    func_020adf5c(0);
    func_020a840c();
    func_020a835c(data_027e000c);
    if (M2C_FIELD(data_027e000c, u8 *, 0x168) != 0) {
        func_02091118(data_027e000c, M2C_FIELD(data_027e000c, u8 *, 0xC1));
    }
    return var_r4;
}
