/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020b6b5c();                                /* extern */
extern M2C_UNK data_021236d4;

u8 func_020b6bf8(u32 arg0) {
    if (arg0 < 0x20U) {
        if ((arg0 == 6) && (func_020b6b5c() != 0)) {
            return 0xC0U;
        }
        return ((s8 *) &data_021236d4)[arg0];
    }
    return 0U;
}
