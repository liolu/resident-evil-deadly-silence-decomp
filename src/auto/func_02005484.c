/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020e2120(M2C_UNK, void *, s32);            /* extern */
M2C_UNK func_02105528();                            /* extern */
extern void *data_02137264;

void func_02005484(void) {
    if (M2C_FIELD(data_02137264, s32 *, 0x540) == 0) {
        M2C_FIELD(data_02137264, s32 *, 0x540) = func_020e2120(2, data_02137264 + 0x580, 0x209E4);
        if (M2C_FIELD(data_02137264, s32 *, 0x540) == 0) {
            func_02105528();
        }
    }
}
