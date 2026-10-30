/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020e1920();                            /* extern */
M2C_UNK func_020e1d50(s32);                         /* extern */
M2C_UNK func_020e663c();                            /* extern */
M2C_UNK func_020ea244(s32);                         /* extern */
s32 func_020ed8c0(s32);                             /* extern */
M2C_UNK func_020ed8cc();                            /* extern */
M2C_UNK func_020ed8f0(s32);                         /* extern */
extern void *data_02137264;

void func_02005648(void) {
    if (data_02137264 != NULL) {
        if (M2C_FIELD(data_02137264, s32 *, 0x540) != 0) {
            func_020e1920();
            func_020e663c();
            if (M2C_FIELD(data_02137264, u8 *, 1) != 0) {
                M2C_FIELD(data_02137264, u8 *, 1) = 0U;
                func_020ea244(M2C_FIELD(data_02137264, s32 *, 0x540));
                func_020e663c();
            }
            func_020e1d50(M2C_FIELD(data_02137264, s32 *, 0x540));
            func_020e663c();
            M2C_FIELD(data_02137264, s32 *, 0x540) = 0;
        }
        if (M2C_FIELD(data_02137264, s32 *, 0x53C) != 0) {
            func_020ed8cc();
            func_020e663c();
            func_020ed8f0(M2C_FIELD(data_02137264, s32 *, 0x53C));
            func_020e663c();
            do {
                func_020e663c();
            } while (func_020ed8c0(M2C_FIELD(data_02137264, s32 *, 0x53C)) != 4);
            M2C_FIELD(data_02137264, s32 *, 0x53C) = 0;
        }
        M2C_FIELD(data_02137264, s32 *, 0xC) = 0;
    }
}
