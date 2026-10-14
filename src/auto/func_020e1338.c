/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020df3ac(M2C_UNK, M2C_UNK);

void func_020e1338(s32 arg0, s32 arg1) {
    s32 temp_r0;

    M2C_FIELD(arg0, s8 *, 0x98) = (s8) arg1;
    temp_r0 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r0 == 0) {
        return;
    }
    func_020df3ac(temp_r0, arg1);
}
