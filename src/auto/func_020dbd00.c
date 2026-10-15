/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e302c(M2C_UNK);

void func_020dbd00(s32 arg0) {
    if (M2C_FIELD(arg0, s32 *, 4) != 3) {
        return;
    }
    func_020e302c(M2C_FIELD(arg0, s32 *, 8));
    M2C_FIELD(arg0, s32 *, 0x8C) = 0;
    M2C_FIELD(arg0, s32 *, 4)    = 0;
}
