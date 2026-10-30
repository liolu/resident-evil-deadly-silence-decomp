/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020af7e8(M2C_UNK);                     /* extern */
s32 func_020b0754();                                /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020afc20(void) {
    if (M2C_FIELD(&data_0213b890, u16 *, 0x26) == 0) {
        if (func_020b0754() != 0) {
            func_020af7e8(0);
            func_020c4798(5);
        }
    } else {
        M2C_FIELD(&data_0213b890, u16 *, 0x26) = (u16) (M2C_FIELD(&data_0213b890, u16 *, 0x26) - 1);
    }
}
