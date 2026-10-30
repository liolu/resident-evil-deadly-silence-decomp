/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020b5540(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

s32 func_020cb94c(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x24) != 0) {
        M2C_FIELD(&data_0213b890, u8 *, 0x24) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x24) - 1);
        return 0;
    }
    if (M2C_FIELD(&data_0213b890, u16 *, 0x26) != M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s32 *, 0x28)) {
        return 0;
    }
    func_020b5540(1);
    return 1;
}
