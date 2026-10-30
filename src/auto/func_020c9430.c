/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_020c8da8();                              /* extern */
extern M2C_UNK data_0213b890;

void func_020c9430(void) {
    void *temp_r0;
    void *temp_r3;

    temp_r3 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
    if (M2C_FIELD(M2C_FIELD(temp_r3, void **, 0x18), u16 *, 0x2C) == 0x4000) {
        M2C_FIELD(temp_r3, u8 *, 2) = (u8) (M2C_FIELD(temp_r3, u8 *, 2) + 1);
        M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s16 *, 0x16) = 0;
        temp_r0                                                                                     = func_020c8da8();
        M2C_FIELD(temp_r0, s8 *, 1)                                                                 = 2;
        M2C_FIELD(temp_r0, s32 *, 8) =
            (s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s32 *, 8);
        M2C_FIELD(temp_r0, s32 *, 0xC) =
            (s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s32 *, 0xC);
        M2C_FIELD(temp_r0, u16 *, 0x2C) =
            (u16) M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), u16 *, 0x2C);
        M2C_FIELD(temp_r0, void **, 0x18) = (void *) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
    }
}
