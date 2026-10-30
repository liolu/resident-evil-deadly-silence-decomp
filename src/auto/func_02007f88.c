/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_0200d1f4(void *, M2C_UNK, s32);          /* extern */
M2C_UNK func_02116dac(M2C_UNK, s32);                /* extern */
s32 func_02117970(s32, s32);                        /* extern */
s8 func_02117de0();                                 /* extern */
s32 func_02117e20(u8);                              /* extern */
s32 func_02117e68(M2C_UNK);                         /* extern */
s32 func_02117eb0(s32, s32);                        /* extern */
extern void *data_02137298;

s32 func_02007f88(M2C_UNK arg0, M2C_UNK arg1) {
    s32 temp_r4;
    s32 temp_r6;
    void *temp_r0;
    void *temp_r0_2;

    temp_r0   = M2C_FIELD(data_02137298, void **, 0x1414);
    temp_r0_2 = func_0200d1f4(temp_r0, arg0, M2C_FIELD(M2C_FIELD(temp_r0, void **, 0x88), s32 *, 0x24));
    if (temp_r0_2 == NULL) {
        return -5;
    }
    temp_r4 = (M2C_FIELD(temp_r0_2, u8 *, 6) * 0x10C) + (s32) (data_02137298 + 0x3984);
    if (!(M2C_FIELD(temp_r4, s32 *, 0xDC) & 1)) {
        return -6;
    }
    temp_r6 = func_02117e20(M2C_FIELD(temp_r0_2, u8 *, 4));
    func_02116dac(0x3F000000, func_02117970(func_02117eb0(temp_r6, func_02117e68(arg1)), 0x42FE0000));
    M2C_FIELD(temp_r4, s8 *, 0x5C) = func_02117de0();
    M2C_FIELD(temp_r4, u8 *, 0xE5) = (u8) (M2C_FIELD(temp_r4, u8 *, 0xE5) | 1);
    return 0;
}
