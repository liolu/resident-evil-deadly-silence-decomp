/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s16 func_02056ff0();                                /* extern */
M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern s16 data_0212d000;
extern s8 data_0213746c;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213daa8;

void func_020587c8(void) {
    data_0212d000 = func_02056ff0();
    if ((s32) data_0212d000 >= 0) {
        func_0206fcf8(0, 1, 1, 0x80);
        M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) & ~0x80);
        data_0213746c                          = 1;
        M2C_FIELD(&data_0213b890, s8 *, 0x94)  = 1;
        M2C_FIELD(&data_0213b890, u8 *, 0x90)  = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x90) | 0x10);
    }
}
