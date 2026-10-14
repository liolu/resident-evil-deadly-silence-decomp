/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020559cc(M2C_UNK, M2C_UNK);

void func_02021970(s32 arg0) {
    M2C_FIELD(arg0, s8 *, 0x91) = 7;
    func_020559cc(arg0, 4);
    M2C_FIELD(arg0, s8 *, 0x98) = 0;
    M2C_FIELD(arg0, s8 *, 0x96) = 1;
}
