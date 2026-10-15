/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02050480(s32 arg0) {
    if ((s32) M2C_FIELD(arg0, s32 *, 0x17C) <= 0xA8C) {
        M2C_FIELD(arg0, s8 *, 0x91) = 0;
        M2C_FIELD(arg0, s8 *, 0xA)  = 3;
    }
}
