/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020709dc(M2C_UNK);                         /* extern */
extern M2C_UNK data_0213daa8;

s32 func_020b53a4(void) {
    if (func_020709dc(0) == 0) {
        return 0;
    }
    if (M2C_FIELD(&data_0213daa8, u8 *, 0x247) == 0) {
        return 1;
    }
    return 0;
}
