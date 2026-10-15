/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020ad928(M2C_UNK);                     /* extern */
s32 func_020ad9a8();                                /* extern */
M2C_UNK func_020adad0(s32);                         /* extern */
M2C_UNK func_020adcf8(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c04;
extern M2C_UNK data_02144cc0;
extern M2C_UNK *data_027e000c;

void func_020c3dc8(void) {
    s32 var_r0;

    data_027e000c = &data_02144c04;
    func_020ad928(1);
    if ((u32) (u8) (M2C_FIELD(&data_0213b890, u8 *, 6) + 0xE3) <= 1U) {
        M2C_FIELD(data_027e000c, s8 *, 0x90) = 8;
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 1;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        if (func_020ad9a8() == 0) {
            var_r0 = 0xB3;
        } else {
            var_r0 = 0x95;
        }
        func_020adad0(var_r0);
        M2C_FIELD(&data_02143cc0, s8 *, 0xF4E) = 0;
        M2C_FIELD(&data_02144cc0, s16 *, 0x30) = 0x20;
        M2C_FIELD(&data_02144cc0, s8 *, 3)     = 0x20;
        if (M2C_FIELD(&data_0213daa8, u16 *, 0x78) != 0) {
            M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) M2C_FIELD(&data_0213daa8, u16 *, 0x78);
            M2C_FIELD(&data_0213daa8, u16 *, 0x78) = 0U;
        }
    } else {
        M2C_FIELD(data_027e000c, s8 *, 0x90) = 1;
        M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        func_020adad0(0x8017);
    }
    M2C_FIELD(data_027e000c, s8 *, 0x98) = 0;
    func_020adcf8(0, 0x400);
}
