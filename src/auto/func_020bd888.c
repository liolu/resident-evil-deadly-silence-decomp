/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_020c3708(s32, s8);
void func_020c4798(s32);
extern M2C_UNK data_0213b890;
extern M2C_UNK data_02147cc0;

void func_020bd888(void) {
    if (M2C_FIELD(&data_0213b890, s32 *, 0x28) != 1) {
        M2C_FIELD(&data_0213b890, u8 *, 9)    = (u8) (M2C_FIELD(&data_0213b890, u8 *, 9) - 0x1B);
        M2C_FIELD(&data_0213b890, s8 *, 0x25) = 0;
        *(M2C_FIELD(&data_02147cc0, u8 **, 0x538) + (M2C_FIELD(&data_0213b890, u8 *, 8) * 2)) =
            M2C_FIELD(&data_0213b890, u8 *, 9);
        M2C_FIELD(M2C_FIELD(&data_02147cc0, u8 **, 0x538) + (M2C_FIELD(&data_0213b890, u8 *, 8) * 2), s8 *, 1) = 1;
        func_020c3708(M2C_FIELD(&data_0213b890, u8 *, 9), 0);
        func_020c4798(1);
    }
}
