/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020b8310(u8);                          /* extern */
extern M2C_UNK data_0211bc32;
extern void *data_0213ad2c;

void func_02012404(void *arg0, void *arg1) {
    u8 temp_r2;

    temp_r2                     = M2C_FIELD(arg1, u8 *, 0xE4);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (temp_r2 - 1);
    if (temp_r2 == 0) {
        M2C_FIELD(arg0, s8 *, 5)    = 1;
        M2C_FIELD(arg1, u8 *, 0xE4) = 0x3CU;
        func_020b8310(*((u8 *) ((s8 *) &data_0211bc32 + (M2C_FIELD(data_0213ad2c, u8 *, 9) * 3))));
        M2C_FIELD(arg1, s8 *, 0xEB) = 1;
    }
    M2C_FIELD(arg1, s32 *, 0)    = (s32) (M2C_FIELD(arg1, s32 *, 0) + M2C_FIELD(arg1, s16 *, 0x12));
    M2C_FIELD(arg1, s16 *, 0x12) = (s16) (M2C_FIELD(arg1, s16 *, 0x12) - 0xC0);
}
