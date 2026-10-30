/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020be0a0(M2C_UNK);                         /* extern */
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b890;

s32 func_020be0fc(void) {
    if (((u32) *M2C_FIELD(&data_0213b2b4, u8 **, 0xB8) >= 5U) && (func_020be0a0(0x38) == 0)) {
        M2C_FIELD(&data_0213b890, u8 *, 0x1E) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x1E) | 2);
        return 1;
    }
    return 0;
}
