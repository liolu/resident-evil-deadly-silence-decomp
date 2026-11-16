/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK *func_020c4798(M2C_UNK);
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;

void func_020bd900(void) {
    s32 var_r0;
    s32 temp_r0;

    var_r0 = M2C_FIELD(&data_0213ad98, u8 *, 5) & 0x80;
    if (var_r0 == 0) {
        temp_r0 = M2C_FIELD(&data_0213b890, u8 *, 9);
        if (temp_r0 == 0x3F) {
            goto set;
        }
        if (temp_r0 != 0x40) {
            goto call;
        }
    set:
        M2C_FIELD(&data_0213b890, s32 *, 0x28) = 1;
        M2C_FIELD(&data_0213b890, s8 *, 0x21)  = 3;
        return;
    call:
        func_020c4798(2);
    }
}
