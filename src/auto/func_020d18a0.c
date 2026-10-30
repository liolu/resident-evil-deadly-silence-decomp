/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02092dd4(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020b5540(M2C_UNK);                     /* extern */
M2C_UNK func_020b64fc(M2C_UNK);                     /* extern */
M2C_UNK func_020b6820(s32);                         /* extern */
extern M2C_UNK data_0213b890;

void func_020d18a0(void) {
    M2C_FIELD(&data_0213b890, s16 *, 0x26) = 0x78;
    M2C_FIELD(&data_0213b890, s8 *, 0x1F)  = 8;
    if (M2C_FIELD(&data_0213b890, u8 *, 0x24) == 2) {
        func_02092dd4(0x1C, 0);
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xFA) = 7;
        M2C_FIELD(&data_0213b890, s8 *, 0x21)                           = 1;
        return;
    }
    func_02092dd4(0x1B, 0);
    func_020b6820(0x299);
    func_020b64fc(2);
    func_020b5540(1);
    M2C_FIELD(&data_0213b890, s8 *, 0x21) = 1;
}
