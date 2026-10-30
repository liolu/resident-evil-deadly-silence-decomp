/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02075738(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144cc0;

void func_02041be0(void *arg0) {
    func_02075738(0, 0x400);
    if (M2C_FIELD(arg0, u8 *, 0xA2) == 0x13) {
        M2C_FIELD(arg0, u8 *, 0x93)            = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
        M2C_FIELD(&data_02143cc0, u8 *, 0xFD7) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xFD7) + 1);
        M2C_FIELD(&data_02144cc0, u16 *, 0x30) = (u16) (M2C_FIELD(&data_02144cc0, u16 *, 0x30) | 0x40);
    }
}
