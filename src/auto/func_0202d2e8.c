/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0203035c(void *, u8, M2C_UNK);         /* extern */
s32 func_0209109c(M2C_UNK, M2C_UNK, M2C_UNK);       /* extern */
extern void *data_027e000c;
extern s32 data_027e0018;

void func_0202d2e8(void) {
    s32 temp_r0;
    u8 temp_r1;

    M2C_FIELD(data_027e000c, u8 *, 8) = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) & 0x1F);
    temp_r1                           = M2C_FIELD(data_027e000c, u8 *, 0x93);
    switch (temp_r1) {                              /* irregular */
        case 0:
            M2C_FIELD(data_027e000c, u8 *, 0x93) = (u8) (temp_r1 + 1);
            M2C_FIELD(data_027e000c, s8 *, 0xA3) = 1;
            M2C_FIELD(data_027e000c, s8 *, 0xA0) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 3;
            M2C_FIELD(data_027e000c, u8 *, 0xA1) = 0x14U;
            func_0203035c(data_027e000c, M2C_FIELD(data_027e000c, u8 *, 0xA1), 0xA);
        /* fallthrough */
        case 1:
            temp_r0       = func_0209109c(2, 0x400, 5);
            data_027e0018 = temp_r0;
            if (((u32) M2C_FIELD(data_027e000c, u8 *, 0xA2) >= 0x10U) || (temp_r0 != 0)) {
                M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
                M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
                M2C_FIELD(data_027e000c, s8 *, 0x92) = 2;
                M2C_FIELD(data_027e000c, u8 *, 0x93) = 0U;
            }
            return;
    }
}
