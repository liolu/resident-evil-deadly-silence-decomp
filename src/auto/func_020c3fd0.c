/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020046ac();                                /* extern */
M2C_UNK func_02071d10();                            /* extern */
M2C_UNK func_02074f38();                            /* extern */
M2C_UNK func_020798a4();                            /* extern */
M2C_UNK func_02079a00();                            /* extern */
M2C_UNK func_020aecfc();                            /* extern */
M2C_UNK func_020c32b4(M2C_UNK);                     /* extern */
extern u8 data_0213ad84;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213bdcc;

void func_020c3fd0(void) {
    if (data_0213ad84 == 0) {
        M2C_FIELD(&data_0213ad98, u8 *, 5) = (u8) (M2C_FIELD(&data_0213ad98, u8 *, 5) & 1);
        if (func_020046ac() == 0) {
            M2C_FIELD(&data_0213b2b4, s8 *, 0xA) = 2;
            return;
        }
        if (M2C_FIELD(&data_0213b890, u8 *, 0) == 2) {
            func_020798a4();
            func_02074f38();
            func_02071d10();
            func_02079a00();
            func_020aecfc();
            func_020c32b4(1);
        }
        M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & ~0xFF00);
        M2C_FIELD(&data_0213b890, s8 *, 1)     = 4;
    }
}
