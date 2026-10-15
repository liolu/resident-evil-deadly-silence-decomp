/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bc0;

s32 func_020a25a8(void *arg0) {
    if (M2C_FIELD(arg0, u16 *, 2) != 0) {
        M2C_FIELD(&data_02143cc0, u8 *, 0xF4F) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xF4F) | 0x30);
    } else {
        M2C_FIELD(&data_02143cc0, u8 *, 0xF4F) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xF4F) | 0x20);
    }
    M2C_FIELD(&data_02144bc0, u16 *, 0xEE) = (u16) M2C_FIELD(arg0, u16 *, 4);
    M2C_FIELD(&data_02144bc0, u16 *, 0xF0) = (u16) M2C_FIELD(arg0, u16 *, 6);
    M2C_FIELD(arg0, u16 *, 2)              = (u16) (M2C_FIELD(arg0, u16 *, 2) ^ 1);
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) | 0x10);
    return 0;
}
