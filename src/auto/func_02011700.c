/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b8310(u8);                          /* extern */
extern M2C_UNK data_0211bc31;
extern void *data_0213ad2c;

void func_02011700(void *arg0, void *arg1) {
    u8 temp_r1;

    if ((u32) M2C_FIELD(arg1, u8 *, 0xE4) <= 0xAU) {
        M2C_FIELD(arg1, s16 *, 0x10) = (s16) (M2C_FIELD(arg1, s16 *, 0x10) + 0x160);
    }
    M2C_FIELD(arg1, s32 *, 0)   = (s32) (M2C_FIELD(arg1, s32 *, 0) + 0x7CCD);
    temp_r1                     = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r1 - 1);
    if (temp_r1 == 0) {
        func_020b8310(*((u8 *) ((s8 *) &data_0211bc31 + (M2C_FIELD(data_0213ad2c, u8 *, 9) * 3))));
        M2C_FIELD(arg1, u8 *, 0xE4)  = 0x78U;
        M2C_FIELD(arg1, s16 *, 0x14) = 0xA;
        M2C_FIELD(arg0, s8 *, 5)     = 3;
    }
}
