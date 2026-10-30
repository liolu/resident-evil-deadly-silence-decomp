/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02051218();                            /* extern */
s32 func_02075738(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_020b82fc(M2C_UNK);                     /* extern */
extern void *data_027e000c;

void func_020519b0(void) {
    u8 temp_r4;

    temp_r4 = M2C_FIELD(data_027e000c, u8 *, 0xA2);
    if ((u32) temp_r4 < 0x12U) {
        func_02051218();
    }
    if ((temp_r4 == 0xC) || (temp_r4 == 0x19)) {
        func_020b82fc(0x83);
    }
    if (func_02075738(1, 0x200) != 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x92)  = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x92) + 1);
        M2C_FIELD(data_027e000c, s16 *, 0xA8) = 4;
    }
}
