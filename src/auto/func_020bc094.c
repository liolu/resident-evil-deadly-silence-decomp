/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020bb780(M2C_UNK, M2C_UNK);            /* extern */
extern void *data_027e000c;

void func_020bc094(void) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(data_027e000c, u8 *, 0x93);
    switch (temp_r1) {                              /* irregular */
        case 0:
            M2C_FIELD(data_027e000c, u8 *, 0x93) = 1U;
            M2C_FIELD(data_027e000c, s8 *, 0xA1) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 0;
        /* fallthrough */
        case 1:
            func_020bb780(1, 0x400);
            if (M2C_FIELD(data_027e000c, u8 *, 9) == 0x26) {
                *M2C_FIELD(M2C_FIELD(data_027e000c, void **, 0), s32 **, 0x10) = 0;
            }
            return;
    }
}
