/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020017cc(M2C_UNK);                     /* extern */
M2C_UNK func_02028a3c();                            /* extern */
M2C_UNK func_02028c40();                            /* extern */
M2C_UNK func_020b3864(void *);                      /* extern */
extern M2C_UNK data_0213ad48;
extern void *data_027e000c;

void func_02028f2c(void) {
    s16 temp_r1;
    u8 temp_r0;

    temp_r0 = M2C_FIELD(data_027e000c, u8 *, 0x91);
    switch (temp_r0) {                              /* irregular */
        case 0:
            func_02028a3c();
        /* fallthrough */
        case 1:
            func_02028c40();
            break;
    }
    M2C_FIELD(data_027e000c, u8 *, 8) = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) & 0x1F);
    M2C_FIELD(data_027e000c, u8 *, 8) = (u8) (M2C_FIELD(data_027e000c, u8 *, 8) | 0x40);
    func_020017cc(0xFA0);
    temp_r1 = M2C_FIELD(data_027e000c, s16 *, 0x182);
    if (temp_r1 != 0) {
        M2C_FIELD(data_027e000c, s16 *, 0x182) = (s16) (temp_r1 - 1);
    }
    if (M2C_FIELD(data_027e000c, s16 *, 0x186) != 0) {
        M2C_FIELD(data_027e000c, s16 *, 0x188) = (s16) (M2C_FIELD(data_027e000c, s16 *, 0x188) + 1);
    } else {
        M2C_FIELD(data_027e000c, s16 *, 0x188) = 0;
    }
    if ((M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) && ((s32) M2C_FIELD(data_027e000c, s16 *, 0x94) < 0)) {
        M2C_FIELD(data_027e000c, s8 *, 0x90) = 3;
        M2C_FIELD(data_027e000c, u8 *, 0x91) = 1U;
        M2C_FIELD(data_027e000c, s8 *, 0x92) = 6;
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        func_020b3864(data_027e000c);
    }
}
