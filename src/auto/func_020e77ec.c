/* compiler: 1.2/sp2p3 -O2 */
#include "m2c.h"

s32 func_020e77cc();                                /* extern */
M2C_UNK func_020e7dc8(M2C_UNK *);                   /* extern */
M2C_UNK func_020e8b24(s32);                         /* extern */
M2C_UNK func_020e8b40(s32);                         /* extern */
extern M2C_UNK data_02131040;

void func_020e77ec(void *arg0, s32 arg1) {
    s32 var_r5;
    s32 var_r5_2;

    if (arg0 == NULL) {
        return;
    }
    if (arg1 == func_020e77cc()) {
        return;
    }
    if (arg1 == 1) {
        var_r5 = 0;
        if ((s32) M2C_FIELD(arg0, s8 *, 3) > 0) {
            do {
                func_020e8b40(M2C_FIELD((arg0 + (var_r5 * 4)), s32 *, 0x48));
                var_r5 += 1;
            } while (var_r5 < (s32) M2C_FIELD(arg0, s8 *, 3));
        }
        M2C_FIELD(arg0, s8 *, 1) = (s8) (M2C_FIELD(arg0, s8 *, 1) | 2);
        return;
    }
    if (arg1 == 0) {
        var_r5_2 = 0;
        if ((s32) M2C_FIELD(arg0, s8 *, 3) > 0) {
            do {
                func_020e8b24(M2C_FIELD((arg0 + (var_r5_2 * 4)), s32 *, 0x48));
                var_r5_2 += 1;
            } while (var_r5_2 < (s32) M2C_FIELD(arg0, s8 *, 3));
        }
        M2C_FIELD(arg0, s8 *, 1) = (s8) (M2C_FIELD(arg0, s8 *, 1) ^ 2);
        return;
    }
    func_020e7dc8(&data_02131040);
}
