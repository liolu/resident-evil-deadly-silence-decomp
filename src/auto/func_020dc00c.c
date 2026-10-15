/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020deb88(M2C_UNK);

extern M2C_UNK data_0212fcd8;

s32 func_020dc00c(s32 arg0) {
    if (arg0 != 0) {
        return (s32) M2C_FIELD(arg0, s8 *, 0xE);
    }
    func_020deb88((s32) &data_0212fcd8);
    return -1;
}
