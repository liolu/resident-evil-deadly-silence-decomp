/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020b39e4(M2C_UNK *, s32);                  /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213db0c;

s32 func_020ba40c(void) {
    if (func_020b39e4(&data_0213db0c, M2C_FIELD(&data_0213b890, u8 *, 9) - 0x1B) == 0) {
        return 0;
    }
    M2C_FIELD(&data_0213ad98, u8 *, 0x12)  = (u8) M2C_FIELD(&data_0213b890, u8 *, 9);
    M2C_FIELD(&data_0213b890, u8 *, 0x279) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x279) | 0x80);
    return 1;
}
