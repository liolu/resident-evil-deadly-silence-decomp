/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020dbd34(M2C_UNK);

void func_020e008c(s32 arg0) {
    func_020dbd34(M2C_FIELD(arg0, s32 *, 4));
    M2C_FIELD(arg0, s8 *, 1) = 0;
}
