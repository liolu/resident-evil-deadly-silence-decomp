/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02033540();                            /* extern */
M2C_UNK func_0205590c(void *, M2C_UNK);             /* extern */
M2C_UNK func_020755b4(M2C_UNK, M2C_UNK);            /* extern */
extern void *data_027e000c;

void func_02036798(void) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(data_027e000c, u8 *, 0x93);
    switch (temp_r1) {                              /* irregular */
        case 0:
            M2C_FIELD(data_027e000c, u8 *, 0x93) = 1U;
            M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0xA1) = 0xE;
            func_0205590c(data_027e000c, 6);
        /* fallthrough */
        case 1:
            func_020755b4(1, 0x400);
            func_02033540();
            return;
    }
}
