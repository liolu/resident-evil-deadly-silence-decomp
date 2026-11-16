/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020c8f98(void) {
    void *temp_ip;

    temp_ip = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
    if (M2C_FIELD(M2C_FIELD(temp_ip, void **, 0x18), s16 *, 0x16) == 2) {
        M2C_FIELD(temp_ip, u8 *, 2) = (u8) (M2C_FIELD(temp_ip, u8 *, 2) + 1);
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s32 *, 8)    = -0x360000;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s16 *, 0x1E) = 0x70;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), u8 *, 0x1C)  = 0x80;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s8 *, 0x1D)  = 0x68;
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s16 *, 0x14) = 0x5A;
    }
}
