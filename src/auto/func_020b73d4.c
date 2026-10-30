/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0200d374(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213abc4;

void func_020b73d4(void) {
    if ((u32) M2C_FIELD(&data_0213abc4, u8 *, 0x114) >= 3U) {
        func_0200d374(0);
        M2C_FIELD(&data_0213abc4, u8 *, 0x114) = 1U;
    }
}
