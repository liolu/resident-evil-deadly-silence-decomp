/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02047eb0(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02047ff0(void *, u8, M2C_UNK);         /* extern */
M2C_UNK func_02048144(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_02090450(u8);                          /* extern */
M2C_UNK func_020b3864(void *);                      /* extern */
extern u8 data_02137364;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213af7c;
extern void *data_027e000c;

void func_02043a18(void) {
    u8 temp_r1;

    temp_r1 = M2C_FIELD(data_027e000c, u8 *, 0x93);
    switch (temp_r1) {                              /* irregular */
        case 0:
            M2C_FIELD(data_027e000c, u8 *, 8)    = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) | 0xA);
            M2C_FIELD(data_027e000c, u8 *, 0x93) = 1U;
            M2C_FIELD(data_027e000c, u8 *, 0xA2) = 0U;
            M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
            M2C_FIELD(data_027e000c, s8 *, 0x98) = 0xF;
            M2C_FIELD(data_027e000c, u8 *, 0xA1) = 8U;
            if ((s32) M2C_FIELD(data_027e000c, s16 *, 0x94) >= 0) {
                M2C_FIELD(data_027e000c, s16 *, 0x94) = -1;
            }
            func_02047ff0(data_027e000c, M2C_FIELD(data_027e000c, u8 *, 0xA1), 0);
            func_020b3864(data_027e000c);
        /* fallthrough */
        case 1:
            if (func_02047eb0(data_027e000c, 0, 0x100, 5) != 0) {
                M2C_FIELD(data_027e000c, u8 *, 0x93) = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x93) + 1);
                func_02090450(data_02137364);
                data_02137364 = 0;
                if (M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) {
                    M2C_FIELD(&data_0213af7c, s8 *, 0x26) = 0;
                }
            }
            if (M2C_FIELD(data_027e000c, u8 *, 0xA2) == 0x11) {
                func_02048144(6, 0);
            }
            if (M2C_FIELD(data_027e000c, u8 *, 0xA2) == 0x27) {
                func_02048144(6, 0);
                return;
            }
            return;
        case 2:
            M2C_FIELD(data_027e000c, u8 *, 8) = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) | 0xA);
            func_020b3864(data_027e000c);
            break;
    }
}
