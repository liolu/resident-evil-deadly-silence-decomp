/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020559cc(M2C_UNK, M2C_UNK);

void func_02021cdc(s32 arg0) {
    M2C_FIELD(arg0, s8 *, 0x91) = 8;
    func_020559cc(arg0, 0);
    M2C_FIELD(arg0, s8 *, 0x98) = 0xF;
}
