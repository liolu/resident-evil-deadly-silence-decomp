/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0201e72c(M2C_UNK, M2C_UNK);
void func_020559cc(M2C_UNK, M2C_UNK);

extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bc0;

void func_0202085c(s32 arg0) {
    M2C_FIELD(arg0, u8 *, 0x92) = (u8) (M2C_FIELD(arg0, u8 *, 0x92) + 1);
    func_020559cc(arg0, 8);
    M2C_FIELD(arg0, s8 *, 0xA2)            = 0;
    M2C_FIELD(arg0, s8 *, 0xA3)            = 0;
    M2C_FIELD(arg0, s8 *, 0x98)            = 0;
    M2C_FIELD(arg0, s32 *, 0x34)           = 0;
    M2C_FIELD(arg0, s16 *, 0x18C)          = 0xB8;
    M2C_FIELD(arg0, s16 *, 0x192)          = 0;
    M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) | 2);
    M2C_FIELD(&data_02144bc0, s16 *, 0x88) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + 0x800);
    func_0201e72c(arg0, 0x384);
    M2C_FIELD(arg0, s16 *, 0x190)          = 0;
    M2C_FIELD(&data_02143cc0, s8 *, 0xFDA) = 1;
    M2C_FIELD(&data_02143cc0, s8 *, 0xFD4) = 7;
    M2C_FIELD(&data_02143cc0, s8 *, 0xFD5) = 2;
    M2C_FIELD(&data_02143cc0, s8 *, 0xFD6) = 0;
    M2C_FIELD(&data_02143cc0, s8 *, 0xFD7) = 0;
    M2C_FIELD(arg0, s16 *, 0xA6)           = 0;
}
