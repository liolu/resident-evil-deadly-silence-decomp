/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020559cc(M2C_UNK, M2C_UNK);

void func_02042548(s32 arg0) {
    func_020559cc(arg0, 0);
    M2C_FIELD(arg0, s8 *, 0xA2) = 0;
    M2C_FIELD(arg0, s8 *, 0xA3) = 0;
    M2C_FIELD(arg0, s8 *, 0x98) = 3;
    M2C_FIELD(arg0, u8 *, 0x93) = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
    M2C_FIELD(arg0, s16 *, 0xA6) = 0x64;
    M2C_FIELD(arg0, s8 *, 0x182) = 3;
}
