/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b82fc();                     /* extern */
s32 func_020c4d64();                  /* extern */
extern M2C_UNK data_02125818;
extern M2C_UNK data_02125824;
extern M2C_UNK data_0213b890;

void func_020c7890(void) {
    if ((func_020c4d64(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0xCA, &data_02125824) != 0) ||
        (func_020c4d64(M2C_FIELD(&data_0213b890, void **, 0x4C) + 0xDC, &data_02125818) != 0)) {
        M2C_FIELD(&data_0213b890, s8 *, 0x23)                            = 3;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x4A)  = 4;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) = 0x5A;
        func_020b82fc(0x81);
        return;
    }
    M2C_FIELD(&data_0213b890, s8 *, 0x23)                            = 4;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) = 0x5A;
}
