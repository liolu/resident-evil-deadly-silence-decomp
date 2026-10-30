/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020559cc(void *, u8);                  /* extern */
M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
extern void *data_027e000c;

void func_0203cab8(void) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(data_027e000c, u8 *, 0x93);
    switch (temp_r1) {                              /* irregular */
        case 0:
            M2C_FIELD(data_027e000c, u8 *, 0x93) = 1U;
            M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
            func_020559cc(data_027e000c, M2C_FIELD(data_027e000c, u8 *, 0xA));
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 3;
        /* fallthrough */
        case 1:
            func_02075738(1, 0x14);
            return;
    }
}
