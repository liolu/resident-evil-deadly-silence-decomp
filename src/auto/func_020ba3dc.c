/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020ba40c();                                /* extern */
extern M2C_UNK data_0213b890;

s32 func_020ba3dc(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 9) != 0x3E) {
        return 0;
    }
    return func_020ba40c();
}
