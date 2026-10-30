/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020c44dc();                            /* extern */
extern u8 data_0213ad84;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213daa8;

void func_020c3d6c(void) {
    if (data_0213ad84 == 0) {
        M2C_FIELD(&data_0213b890, s8 *, 3) = 4;
        M2C_FIELD(&data_0213b890, s8 *, 1) = 0;
        if (M2C_FIELD(&data_0213daa8, u16 *, 0x78) != 0) {
            M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) M2C_FIELD(&data_0213daa8, u16 *, 0x78);
            M2C_FIELD(&data_0213daa8, u16 *, 0x78) = 0U;
        }
        func_020c44dc();
    }
}
