/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020559cc(M2C_UNK, M2C_UNK);

void func_02021890(s32 arg0) {
    M2C_FIELD(arg0, s8 *, 0x91) = 5;
    func_020559cc(arg0, 0);
    M2C_FIELD(arg0, s8 *, 0x98) = 0xF;
    M2C_FIELD(arg0, s8 *, 0xA2) = 0;
    M2C_FIELD(arg0, s16 *, 0xA8) = 0x14;
    M2C_FIELD(arg0, s16 *, 0x182) = 0;
    M2C_FIELD(arg0, s16 *, 0x18C) = 0;
    M2C_FIELD(arg0, s8 *, 0x96) = 1;
}
