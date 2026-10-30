/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_020c8da8();                              /* extern */
M2C_UNK func_020c96e0();                            /* extern */
extern M2C_UNK data_0213b890;

void func_020c9800(void) {
    void *temp_r0;
    void *temp_r2;
    void *temp_r3;

    temp_r2 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
    if (M2C_FIELD(temp_r2, u16 *, 0x2C) == 0) {
        M2C_FIELD(temp_r2, s16 *, 0x14) = (s16) (M2C_FIELD(temp_r2, s16 *, 0x14) - 1);
        temp_r3                         = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
        if (M2C_FIELD(temp_r3, s16 *, 0x14) == 0) {
            M2C_FIELD(temp_r3, u8 *, 2) = (u8) (M2C_FIELD(temp_r3, u8 *, 2) + 1);
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s16 *, 0x14) = 4;
            func_020c96e0();
            temp_r0                           = func_020c8da8();
            M2C_FIELD(temp_r0, s8 *, 1)       = 3;
            M2C_FIELD(temp_r0, void **, 0x18) = (void *) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
        }
    }
}
