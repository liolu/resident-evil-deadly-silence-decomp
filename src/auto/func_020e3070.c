/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e3070(s32 arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xC) == 0) {
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
        M2C_FIELD(arg0, s32 *, 0xC)  = 1;
    }
}
