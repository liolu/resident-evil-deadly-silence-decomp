/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020703b8(M2C_UNK *);                       /* extern */
extern M2C_UNK data_0211d940;
extern M2C_UNK data_0211d95c;
extern M2C_UNK data_0214dcc0;

void func_0207226c(s32 arg0) {
    if (arg0 == 0) {
        M2C_FIELD(&data_0214dcc0, s32 *, 0x928) = func_020703b8(&data_0211d940);
        return;
    }
    M2C_FIELD(&data_0214dcc0, s32 *, 0x928) = func_020703b8(&data_0211d95c);
}
