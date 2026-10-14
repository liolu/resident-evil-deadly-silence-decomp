/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020559cc(M2C_UNK, M2C_UNK);

void func_020509a0(s32 arg0) {
    M2C_FIELD(arg0, s8 *, 0x91) = 2;
    func_020559cc(arg0, 1);
    M2C_FIELD(arg0, s8 *, 0xA2) = 0;
    M2C_FIELD(arg0, s8 *, 0xA3) = 0;
    M2C_FIELD(arg0, s8 *, 0x98) = 0x1F;
}
