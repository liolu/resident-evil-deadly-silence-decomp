/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020adcf8(M2C_UNK, M2C_UNK);                /* extern */

void func_020aa388(void *arg0) {
    if (func_020adcf8(1, 0x400) == 0) {
        M2C_FIELD(arg0, u8 *, 0x93) = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
    }
}
