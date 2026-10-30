/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02082314(void *);                          /* extern */
M2C_UNK func_020823b4(void *, u8, M2C_UNK, M2C_UNK); /* extern */
s32 func_02083e20();                                /* extern */

void func_02082610(void *arg0) {
    void *temp_r1;

    M2C_FIELD(arg0, s16 *, 0xA) = (s16) (M2C_FIELD(arg0, s16 *, 0xA) - 1);
    if (((s32) M2C_FIELD(arg0, s16 *, 0xA) <= 0) || (func_02083e20() >= (s32) M2C_FIELD(arg0, s8 *, 0xC))) {
        temp_r1                        = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
        M2C_FIELD(arg0, u8 *, 7)       = (u8) (M2C_FIELD(arg0, u8 *, 7) | 2);
        return;
    }
    if (func_02082314(arg0) != 0) {
        func_020823b4(arg0, M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0xA1), 0, 0);
    }
}
