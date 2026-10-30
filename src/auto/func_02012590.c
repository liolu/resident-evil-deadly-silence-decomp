/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020b8310(u8);                          /* extern */
extern M2C_UNK data_0211bc31;
extern void *data_0213ad2c;

void func_02012590(void *arg0, void *arg1) {
    u8 temp_r1;
    u8 temp_r1_2;

    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0x7E) {
        func_020b8310(*((u8 *) ((s8 *) &data_0211bc31 + (M2C_FIELD(data_0213ad2c, u8 *, 9) * 3))));
    }
    if ((M2C_FIELD(arg1, u8 *, 0xE4) == 0x42) && (M2C_FIELD(arg1, u8 *, 0xE5) != 0)) {
        func_020b8310(*((u8 *) ((s8 *) &data_0211bc31 + (M2C_FIELD(data_0213ad2c, u8 *, 9) * 3))));
    }
    if (M2C_FIELD(arg1, u8 *, 0xE5) != 0) {
        temp_r1                     = M2C_FIELD(arg1, u8 *, 0xE4);
        M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r1 - 1);
        if (temp_r1 == 0) {
            M2C_FIELD(arg0, s8 *, 4)    = 2;
            M2C_FIELD(arg1, s8 *, 0xEB) = 2;
        }
        return;
    }
    if ((u32) M2C_FIELD(arg1, u8 *, 0xE4) < 0x7EU) {
        M2C_FIELD(arg1, s32 *, 0) = (s32) (M2C_FIELD(arg1, s32 *, 0) - M2C_FIELD(arg1, s16 *, 0x12));
    }
    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0xF) {
        func_0206fcf8(0, 1, 1, 0x100);
    }
    temp_r1_2                   = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r1_2 - 1);
    if (temp_r1_2 == 0) {
        M2C_FIELD(arg0, s8 *, 4)    = 2;
        M2C_FIELD(arg1, s8 *, 0xEB) = 2;
    }
}
