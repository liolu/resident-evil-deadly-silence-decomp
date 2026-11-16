/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u16 func_0200d514(u16, M2C_UNK, u16);               /* extern */
void *func_0200da8c(s32);                           /* extern */
extern M2C_UNK data_0213aca8;

void func_020b766c(s32 arg0, s32 arg1) {
    void *temp_r5;
    s32 temp_r4;

    temp_r4 = (arg0 * 0xC) + (s32) &data_0213aca8;
    temp_r5 = func_0200da8c(M2C_FIELD(temp_r4, s32 *, 4));
    if (M2C_FIELD(temp_r4, u8 *, 1) != 0) {
        func_0200d514((u16) M2C_FIELD(temp_r4, s32 *, 4), 0, arg1);
        M2C_FIELD(temp_r4, u8 *, 2) = (u8) M2C_FIELD(temp_r5, u8 *, 4);
        M2C_FIELD(temp_r4, s8 *, 0) = 0x10;
        M2C_FIELD(temp_r4, u8 *, 1) = 0x10U;
    }
}
