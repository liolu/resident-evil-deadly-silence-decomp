/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_0200e514();                                /* extern */
M2C_UNK func_02092bac();                            /* extern */
M2C_UNK func_02092c04(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_020af62c(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_020af6f4(M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
s32 func_020b0754();                                /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213b890;

void func_020b0780(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x21) == 0) {
        if (func_020af62c(0x30, 4) != 0) {
            func_02092c04(0xE723, 0, 0xA, 0x8200);
            M2C_FIELD(&data_0213b890, u16 *, 0x26) = (u16) (func_0200e514() * 2);
            M2C_FIELD(&data_0213b890, u8 *, 0x21)  = 1U;
        }
    } else if (M2C_FIELD(&data_0213b890, u16 *, 0x26) == 0) {
        if (func_020b0754() != 0) {
            func_02092bac();
            func_020af6f4(2, 4, 0x60);
            func_020c4798(5);
        }
    } else {
        M2C_FIELD(&data_0213b890, u16 *, 0x26) = (u16) (M2C_FIELD(&data_0213b890, u16 *, 0x26) - 1);
    }
}
