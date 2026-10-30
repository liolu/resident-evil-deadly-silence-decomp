/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s8 func_020133c0(M2C_UNK);                          /* extern */
extern u16 data_0213ad3c;
extern M2C_UNK data_0213ae4c;
extern M2C_UNK data_0213b890;

s8 func_020ca83c(void) {
    s8 temp_r2;
    s8 var_r0;

    if (data_0213ad3c & 2) {
        var_r0 = 9;
    } else if (data_0213ad3c & 1) {
        var_r0 = 0xA;
    } else {
        var_r0 = func_020133c0(0);
        if ((M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x2B) != var_r0) &&
            (M2C_FIELD(&data_0213ae4c, u8 *, 2) == 0)) {
            var_r0 = -1;
        }
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x2B) = var_r0;
    }
    temp_r2 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x29);
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x29) = var_r0;
    if (var_r0 != temp_r2) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x2A) = 8;
        return var_r0;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x2A) =
        (s8) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x2A) - 1);
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x2A) == 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x2A) = 4;
        return var_r0;
    }
    return -1;
}
