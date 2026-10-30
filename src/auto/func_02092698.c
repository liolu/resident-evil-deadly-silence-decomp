/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0209215c(M2C_UNK);                     /* extern */
M2C_UNK func_020925f8(u8);                          /* extern */
extern M2C_UNK data_0213ad3c;
extern M2C_UNK data_0213ae4c;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213e394;

void func_02092698(void) {
    s32 var_r2;

    if ((M2C_FIELD(&data_0213ae4c, u8 *, 2) != 0) || (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x50)) {
        M2C_FIELD(&data_0213e394, s8 *, 1) = 1;
        func_020925f8(2U);
        func_0209215c(0);
        return;
    }
    if (!(M2C_FIELD(&data_0213e394, s16 *, 0xE) & 0x1F)) {
        M2C_FIELD(&data_0213e394, u8 *, 6) = (u8) (M2C_FIELD(&data_0213e394, u8 *, 6) ^ 1);
        func_020925f8(M2C_FIELD(&data_0213e394, u8 *, 6));
    }
    if (M2C_FIELD(&data_0213b2b4, u8 *, 1) == 0) {
        var_r2 = 1;
    } else {
        var_r2 = 2;
    }
    M2C_FIELD(&data_0213e394, s16 *, 0xE) = (s16) (M2C_FIELD(&data_0213e394, s16 *, 0xE) + var_r2);
}
