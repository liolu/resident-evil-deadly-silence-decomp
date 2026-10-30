/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d7d84();                            /* extern */
extern M2C_UNK data_0213caa0;

void func_020d8e34(u32 arg0) {
    func_020d7d84();
    if ((u32) M2C_FIELD(&data_0213caa0, u8 *, 0x707) <= arg0) {
        M2C_FIELD(&data_0213caa0, s8 *, 0x702) = 1;
        return;
    }
    M2C_FIELD(&data_0213caa0, s8 *, 0x708) = (s8) arg0;
    M2C_FIELD(&data_0213caa0, s8 *, 0x706) = 0;
    M2C_FIELD(&data_0213caa0, s8 *, 0x700) = 2;
    M2C_FIELD(&data_0213caa0, s8 *, 0x701) = 0;
    M2C_FIELD(&data_0213caa0, s8 *, 0x702) = 0;
}
