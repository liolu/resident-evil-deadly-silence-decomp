/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b8310(u8);                          /* extern */
extern M2C_UNK data_0211bc31;
extern void *data_0213ad2c;

void func_02011410(void *arg0, void *arg1) {
    u8 temp_r1;
    u8 temp_r1_2;

    temp_r1 = M2C_FIELD(arg1, u8 *, 0xE4);
    if (((u32) temp_r1 > 7U) && ((u32) temp_r1 < 0x2DU)) {
        if ((u32) temp_r1 < 0xFU) {
            M2C_FIELD(arg1, s16 *, 0x18) = (s16) (M2C_FIELD(arg1, s16 *, 0x18) - 0xD);
            if ((s32) M2C_FIELD(arg1, s16 *, 0x18) < 0) {
                M2C_FIELD(arg1, s16 *, 0x18) = 0;
            }
        }
        M2C_FIELD(arg1, s16 *, 0xE) = (s16) (M2C_FIELD(arg1, s16 *, 0xE) + M2C_FIELD(arg1, s16 *, 0x18));
    }
    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0x2D) {
        func_020b8310(*((u8 *) ((s8 *) &data_0211bc31 + (M2C_FIELD(data_0213ad2c, u8 *, 9) * 3))));
    }
    temp_r1_2                   = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r1_2 - 1);
    if (temp_r1_2 == 0) {
        M2C_FIELD(arg0, s8 *, 5) = 2;
        if (M2C_FIELD(data_0213ad2c, u8 *, 8) == 0) {
            M2C_FIELD(arg1, u8 *, 0xE4) = 0x41U;
        } else {
            M2C_FIELD(arg1, u8 *, 0xE4) = 0x2DU;
        }
        M2C_FIELD(arg1, s8 *, 0xEB) = 2;
    }
}
