/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02023a2c();                            /* extern */
M2C_UNK func_020559cc(void *, M2C_UNK);             /* extern */
extern void *data_027e000c;

void func_02025734(void) {
    s32 temp_r1_2;
    u8 temp_r1;

    temp_r1 = M2C_FIELD(data_027e000c, u8 *, 0x92);
    switch (temp_r1) {                              /* irregular */
        case 0:
            M2C_FIELD(data_027e000c, u8 *, 0x92) = (u8) (temp_r1 + 1);
            temp_r1_2                            = (s32) M2C_FIELD(data_027e000c, u8 *, 0x96) >> 3;
            if (((u8) temp_r1_2 == 6) || ((u8) temp_r1_2 == 9)) {
                func_020559cc(data_027e000c, 0xD);
            } else {
                func_020559cc(data_027e000c, 1);
            }
        /* fallthrough */
        case 1:
            func_02023a2c();
            return;
    }
}
