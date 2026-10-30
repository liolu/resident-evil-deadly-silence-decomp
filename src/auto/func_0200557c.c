/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020fdbf8();                            /* extern */
M2C_UNK func_020fdc10(M2C_UNK, s32, s32);           /* extern */
s32 func_020fec4c(s32, s32);                        /* extern */
extern M2C_UNK data_0211b0c0;
extern void *data_02137264;

void func_0200557c(M2C_UNK arg0, s32 arg1, s32 arg2) {
    s32 temp_r6_2;
    u8 temp_r2;
    void *temp_r6;

    if (data_02137264 != NULL) {
        temp_r2 = M2C_FIELD(data_02137264, u8 *, 0x15);
        if (temp_r2 != 0) {
            temp_r6   = (M2C_UNK *) ((s8 *) &data_0211b0c0 + (temp_r2 * 0x10));
            temp_r6_2 = func_020fec4c(M2C_FIELD(temp_r6, u16 *, 8) << 0xC, arg1 << 0xC);
            func_020fdc10(arg0, temp_r6_2, func_020fec4c(M2C_FIELD(temp_r6, u8 *, 0xA) << 0xC, arg2 << 0xC));
            return;
        }
        func_020fdbf8(arg0);
    }
}
