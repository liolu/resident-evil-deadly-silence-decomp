/* compiler: 1.2/sp2p3 -O2 */
#include "m2c.h"

M2C_UNK func_020e7384();                            /* extern */
M2C_UNK func_020e7390();                            /* extern */
s32 func_020e78cc();                                /* extern */
M2C_UNK func_020e7dc8(M2C_UNK *);                   /* extern */
M2C_UNK func_020e8840(s32);                         /* extern */
extern M2C_UNK data_02131064;

void func_020e78ec(void *arg0, s32 arg1) {
    s32 var_r5;

    if (arg0 == NULL) {
        return;
    }
    if (arg1 == func_020e78cc()) {
        return;
    }
    if (arg1 == 1) {
        func_020e7390();
        var_r5 = 0;
        if ((s32) M2C_FIELD(arg0, s8 *, 2) > 0) {
            do {
                func_020e8840(M2C_FIELD((arg0 + (var_r5 * 4)), s32 *, 0x48));
                var_r5 += 1;
            } while (var_r5 < (s32) M2C_FIELD(arg0, s8 *, 2));
        }
        M2C_FIELD(arg0, s32 *, 0x38) = 0;
        M2C_FIELD(arg0, s8 *, 1)     = (s8) (M2C_FIELD(arg0, s8 *, 1) | 1);
        func_020e7384();
        return;
    }
    if (arg1 == 0) {
        M2C_FIELD(arg0, s8 *, 1) = (s8) (M2C_FIELD(arg0, s8 *, 1) ^ 1);
        return;
    }
    func_020e7dc8(&data_02131064);
}
