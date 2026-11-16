/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02079148(u8, u8);                          /* extern */
M2C_UNK func_020b3a24(M2C_UNK *, s32);              /* extern */
extern M2C_UNK data_0211e784;
extern M2C_UNK data_0213be70;
extern M2C_UNK data_0213be84;

void func_02079734(s32 arg0, s32 arg1) {
    s8 temp_r2;

    temp_r2 = ((s8 *) &data_0211e784)[arg0];
    if (temp_r2 >= 0) {
        func_020b3a24((M2C_UNK *) ((s32 *) &data_0213be70 + temp_r2), arg1 & 0x1F);
        func_020b3a24(&data_0213be84, (u8) (func_02079148(arg0, arg1) & 0xF) + 0x10);
    }
}
