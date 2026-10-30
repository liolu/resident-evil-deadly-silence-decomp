/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b3a24(M2C_UNK *, u8);               /* extern */
s32 func_020bb780(M2C_UNK, M2C_UNK);                /* extern */
extern M2C_UNK data_0213db04;
extern void *data_027e000c;

void func_020540c8(void) {
    u8 temp_r0;
    void *temp_r1;

    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0x93);
    switch (temp_r0) {                              /* irregular */
        case 0:
            M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
            M2C_FIELD(data_027e000c, u8 *, 0x93) = 1U;
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 3;
            temp_r1                              = M2C_FIELD(M2C_FIELD(data_027e000c, void **, 0), void **, 0x10);
            M2C_FIELD(temp_r1, s32 *, 0)         = (s32) (M2C_FIELD(M2C_FIELD(temp_r1, void **, 8), u16 *, 4) << 0xC);
        /* fallthrough */
        case 1:
            if (func_020bb780(2, 0x400) != 0) {
                M2C_FIELD(data_027e000c, u8 *, 0x93) = 2U;
            }
            return;
        case 2:
            M2C_FIELD(data_027e000c, s8 *, 0x92) = 0;
            M2C_FIELD(data_027e000c, u8 *, 0x93) = 0U;
            func_020b3a24(&data_0213db04, M2C_FIELD(data_027e000c, u8 *, 0xBF));
            return;
    }
}
