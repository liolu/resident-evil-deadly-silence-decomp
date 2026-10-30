/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02092dd4(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_020b8310(u8);                          /* extern */
extern M2C_UNK data_0211bc31;
extern void *data_0213ad2c;

void func_02012a70(void *arg0, void *arg1) {
    M2C_FIELD(arg1, s16 *, 0xC) = (s16) (M2C_FIELD(arg1, s16 *, 0xC) - 0xA0);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (M2C_FIELD(arg1, u8 *, 0xE4) - 1);
    if (M2C_FIELD(arg1, u8 *, 0xE4) == 0) {
        M2C_FIELD(arg1, u8 *, 0xE4) = 0x28U;
        M2C_FIELD(arg0, s8 *, 5)    = 2;
        func_020b8310(*((u8 *) ((s8 *) &data_0211bc31 + (M2C_FIELD(data_0213ad2c, u8 *, 9) * 3))));
        if (M2C_FIELD(data_0213ad2c, u8 *, 9) == 0xC) {
            M2C_FIELD(arg0, s8 *, 5)    = 4;
            M2C_FIELD(arg1, u8 *, 0xE4) = 0xFU;
        }
        if (M2C_FIELD(data_0213ad2c, u8 *, 8) == 5) {
            func_02092dd4(0x5A, 0xFF);
        }
        M2C_FIELD(arg1, s8 *, 0xEB) = 2;
    }
}
