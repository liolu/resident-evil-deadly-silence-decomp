/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02075330(M2C_UNK);                         /* extern */
M2C_UNK func_02075608(M2C_UNK);                     /* extern */
extern void *data_027e000c;

s32 func_020755b4(M2C_UNK arg0, M2C_UNK arg1) {
    u8 temp_r0;

    if (M2C_FIELD(M2C_FIELD(data_027e000c, void **, 0), s32 *, 0x10) != 0) {
        temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0xA3);
        if (temp_r0 != 0) {
            M2C_FIELD(data_027e000c, u8 *, 0xA3) = (u8) (temp_r0 - 1);
        }
        func_02075608(arg1);
        return func_02075330(arg0);
    }
    return 0;
}
