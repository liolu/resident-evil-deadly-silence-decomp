/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020c0148(s32);                             /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
M2C_UNK func_020d2e60();                            /* extern */
extern u8 data_0213ad84;
extern M2C_UNK data_0213b890;

void func_020d3594(void) {
    if (data_0213ad84 == 0) {
        if (func_020c0148(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0x110) == 1) {
            func_020c4798(2);
            return;
        }
        func_020d2e60();
    }
}
