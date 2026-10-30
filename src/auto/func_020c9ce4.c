/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020133a8(M2C_UNK);                         /* extern */
extern M2C_UNK data_0213ad3c;

s32 func_020c9ce4(void) {
    if ((M2C_FIELD(&data_0213ad3c, u16 *, 2) & 2) || (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x100)) {
        return 0;
    }
    if ((M2C_FIELD(&data_0213ad3c, u16 *, 2) & 1) || (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x200) ||
        (M2C_FIELD(&data_0213ad3c, u16 *, 2) & 0x10)) {
        return 1;
    }
    return func_020133a8(0);
}
