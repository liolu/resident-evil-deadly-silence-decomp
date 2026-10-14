/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_01ffd214(M2C_UNK, M2C_UNK);
void func_0203fec8(M2C_UNK);
void func_020559cc(M2C_UNK, M2C_UNK);
void func_020b8110(M2C_UNK, M2C_UNK);

extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_02144c34;

void func_02041ea0(s32 arg0) {
    func_01ffd214((s32) &data_02144c34, 0x100);
    func_020559cc(arg0, 6);
    M2C_FIELD(arg0, s8 *, 0xA2) = 0;
    M2C_FIELD(arg0, s8 *, 0xA3) = 0;
    M2C_FIELD(arg0, s8 *, 0x98) = 3;
    M2C_FIELD(arg0, u8 *, 0x93) = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
    M2C_FIELD(arg0, u8 *, 8) = (u8) (M2C_FIELD(arg0, u8 *, 8) | 2);
    M2C_FIELD(arg0, s16 *, 0xA6) = 0x96;
    func_020b8110(0x71, 0);
    M2C_FIELD(arg0, u8 *, 8) = (u8) (M2C_FIELD(arg0, u8 *, 8) | 2);
    M2C_FIELD(&data_02143cc0, s32 *, 0xFD4) = 0xB07;
    M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) = (u8) (M2C_FIELD(&data_02143cc0, u8 *, 0xF4C) | 6);
    M2C_FIELD(&data_02144bc0, s16 *, 0x88) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + 0x800);
    func_0203fec8(arg0);
}
