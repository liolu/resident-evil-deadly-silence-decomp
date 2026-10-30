/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern void *data_0213ad2c;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213be00;

void func_0207164c(void) {
    s32 temp_r0;

    M2C_FIELD(&data_0213ad98, u8 *, 3) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 1);
    M2C_FIELD(&data_0213ad98, u8 *, 1) = (u8) (M2C_FIELD(data_0213ad2c, u8 *, 0xD) & 0x1F);
    temp_r0                            = (s32) (M2C_FIELD(data_0213ad2c, u8 *, 0xD) & 0xE0) >> 5;
    if ((u8) temp_r0 != 0) {
        M2C_FIELD(&data_0213ad98, u8 *, 0) = (u8) ((u8) temp_r0 - 1);
    }
    if ((func_020b39e4(&data_0213be00, 0) != 0) && ((u32) M2C_FIELD(&data_0213ad98, u8 *, 0) < 2U)) {
        M2C_FIELD(&data_0213ad98, u8 *, 0) = (u8) (M2C_FIELD(&data_0213ad98, u8 *, 0) + 5);
    }
}
