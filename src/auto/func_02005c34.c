/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02005ae8();                            /* extern */
s32 func_020e188c();                                /* extern */
extern void *data_02137264;

void func_02005c34(void) {
    if (data_02137264 != NULL) {
        if (M2C_FIELD(data_02137264, s32 *, 0xC) == 1) {
            if (M2C_FIELD(data_02137264, s32 *, 0x540) != 0) {
                if (func_020e188c() == 5) {
                    M2C_FIELD(data_02137264, s32 *, 0xC) = 3;
                }
                func_02005ae8();
            }
        } else {
            M2C_FIELD(data_02137264, s16 *, 6) = 0;
        }
    }
}
