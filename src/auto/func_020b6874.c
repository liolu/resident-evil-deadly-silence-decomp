/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02073e4c(s16, s16);                        /* extern */
M2C_UNK func_020b82fc(u8);                          /* extern */
extern M2C_UNK data_0213bdcc;
extern void *data_027e000c;

void func_020b6874(s32 arg0) {
    s32 var_r4;

    if (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 1) {
        var_r4 = -3;
    } else {
        var_r4 = 0;
    }
    func_020b82fc((u8) (arg0 + (var_r4 + func_02073e4c((s16) M2C_FIELD(data_027e000c, s32 *, 0x30),
                                                       (s16) M2C_FIELD(data_027e000c, s32 *, 0x38)))));
}
