/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02091604(M2C_UNK, M2C_UNK);
void func_0209160c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_02091624(M2C_UNK, M2C_UNK, M2C_UNK);

void func_0207c6c0(s32 arg0) {
    M2C_FIELD(*(M2C_UNK *)arg0, s8 *, 8) = 1;
    M2C_FIELD(*(M2C_UNK *)arg0, s8 *, 0xB) = 1;
    func_02091624((s32) (*(M2C_UNK *)arg0 + 0x54), 0x3DCCCCCD, 0x3DCCCCCD);
    func_02091604((s32) (*(M2C_UNK *)arg0 + 0x54), 0x1C);
    func_0209160c((s32) (*(M2C_UNK *)arg0 + 0x54), 5, 0, 9);
    M2C_FIELD(*(M2C_UNK *)arg0, s8 *, 0x84) = 1;
    M2C_FIELD(*(M2C_UNK *)arg0, s8 *, 0x90) = 1;
}
