/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b5540(u8);                          /* extern */
M2C_UNK func_020c46b4(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020c6470(void) {
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) =
        (s16) (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) - 1);
    if (M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x10) == 0) {
        func_020b5540((u8) M2C_FIELD(&data_0213b890, s32 *, 0x2C));
        func_020c46b4(0);
    }
}
