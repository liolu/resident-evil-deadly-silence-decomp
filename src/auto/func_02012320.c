/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020b8310(u8);                          /* extern */
extern M2C_UNK data_0211bc32;
extern void *data_0213ad2c;

void func_02012320(void *arg0, void *arg1) {
    u8 temp_r1;

    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0xF) {
        func_0206fcf8(0, 1, 1, 0x100);
    }
    temp_r1                     = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r1 - 1);
    if (temp_r1 == 0) {
        M2C_FIELD(arg0, s8 *, 4) = 2;
        func_020b8310(*((u8 *) ((s8 *) &data_0211bc32 + (M2C_FIELD(data_0213ad2c, u8 *, 9) * 3))));
    }
    M2C_FIELD(arg1, s32 *, 0)    = (s32) (M2C_FIELD(arg1, s32 *, 0) + M2C_FIELD(arg1, s16 *, 0x12));
    M2C_FIELD(arg1, s16 *, 0x12) = (s16) (M2C_FIELD(arg1, s16 *, 0x12) - 0x100);
}
