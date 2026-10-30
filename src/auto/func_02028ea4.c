/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020277c8();                            /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
M2C_UNK func_02095764();                            /* extern */
extern void *data_027e000c;

void func_02028ea4(void) {
    s32 temp_r1;
    u8 temp_r0;

    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0x92);
    switch (temp_r0) {                              /* irregular */
        case 0:
            func_02095764();
            M2C_FIELD(data_027e000c, u8 *, 0x92) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x92) + 1);
            temp_r1                              = (s32) M2C_FIELD(data_027e000c, u8 *, 0x96) >> 3;
            if (((u8) temp_r1 == 6) || ((u8) temp_r1 == 9)) {
                func_020559cc(data_027e000c, 0x10);
            } else {
                func_020559cc(data_027e000c, 1);
            }
        /* fallthrough */
        case 1:
            func_020277c8();
            return;
    }
}
