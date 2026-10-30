/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020b39e4(M2C_UNK *, M2C_UNK);              /* extern */
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213bde0;
extern M2C_UNK data_02143cc0;

void func_020569d8(void) {
    if (func_020b39e4(&data_0213bde0, 0xC0) != 0) {
        if (func_020b39e4(&data_0213bde0, 0x4B) != 0) {
            *M2C_FIELD(&data_0213b2b4, s8 **, 0xB8) = 2;
            return;
        }
        if (!(M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) & 3)) {
            *M2C_FIELD(&data_0213b2b4, s8 **, 0xB8) = 0;
        } else {
            *M2C_FIELD(&data_0213b2b4, s8 **, 0xB8) = 1;
        }
        return;
    }
    if (func_020b39e4(&data_0213bde0, 0x4B) == 0) {
        if (!(M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) & 3)) {
            *M2C_FIELD(&data_0213b2b4, s8 **, 0xB8) = 3;
        } else {
            *M2C_FIELD(&data_0213b2b4, s8 **, 0xB8) = 4;
        }
        return;
    }
    if (!(M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) & 3)) {
        *M2C_FIELD(&data_0213b2b4, s8 **, 0xB8) = 5;
        return;
    }
    *M2C_FIELD(&data_0213b2b4, s8 **, 0xB8) = 6;
}
