/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02005484();                            /* extern */
M2C_UNK func_020054e4();                            /* extern */
extern void *data_02137264;

void func_0200582c(s8 arg0) {
    if (data_02137264 != NULL) {
        M2C_FIELD(data_02137264, s32 *, 0xC)  = 0;
        M2C_FIELD(data_02137264, s8 *, 0x15)  = arg0;
        M2C_FIELD(data_02137264, s16 *, 0x16) = 0x100;
        M2C_FIELD(data_02137264, s16 *, 0x18) = 0xC0;
        M2C_FIELD(data_02137264, s8 *, 0x14)  = 0xF;
        M2C_FIELD(data_02137264, s32 *, 0x10) = 0;
        func_020054e4();
        func_02005484();
    }
}
