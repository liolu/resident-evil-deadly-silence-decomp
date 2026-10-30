/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0200176c(M2C_UNK);                     /* extern */
M2C_UNK func_020017cc(M2C_UNK);                     /* extern */
M2C_UNK func_02046c9c();                            /* extern */
M2C_UNK func_02046de0();                            /* extern */
extern M2C_UNK data_0213ad48;
extern void *data_027e000c;

void func_0204702c(void) {
    u8 temp_r0;

    M2C_FIELD(data_027e000c, u8 *, 8) = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) & 0x1F);
    M2C_FIELD(data_027e000c, u8 *, 8) = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) | 0x40);
    func_020017cc(0xFA0);
    func_0200176c(0xFA0);
    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0x91);
    switch (temp_r0) {                              /* irregular */
        case 0:
            func_02046c9c();
        /* fallthrough */
        case 1:
            func_02046de0();
            break;
    }
    if ((M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) && (M2C_FIELD(data_027e000c, u8 *, 0x96) == 0) &&
        ((s32) M2C_FIELD(data_027e000c, s16 *, 0x94) < 0)) {
        M2C_FIELD(data_027e000c, s8 *, 0x90) = 3;
        M2C_FIELD(data_027e000c, u8 *, 0x91) = 0U;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        M2C_FIELD(data_027e000c, u8 *, 0x96) = 1U;
    }
}
