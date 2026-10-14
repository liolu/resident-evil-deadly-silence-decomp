/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020eca0c(M2C_UNK);

s32 func_020ec9d0(s32 arg0, s32 arg1) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0xC) < arg1) {
        func_020eca0c(arg0);
    }
    if (arg1 > (s32) M2C_FIELD(arg0, s32 *, 0xC)) {
        return 0;
    }
    return 1;
}
