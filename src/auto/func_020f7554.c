/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020f7554(s32 arg0) {
    M2C_UNK (*temp_r1)(arg0);

    temp_r1 = M2C_FIELD(arg0, M2C_UNK(**)(), 0x10);
    if (temp_r1 != NULL) {
        temp_r1(arg0);
    }
    M2C_FIELD(arg0, s32 *, 8) = (s32) (M2C_FIELD(arg0, s32 *, 8) | 0x20);
}
