/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02100adc(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 var_r3;

    var_r3 = arg0 | (arg1 << 0x10) | (arg3 << 0x18);
    if (arg4 != 0) {
        var_r3 |= 0x8000;
    }
    *(s32 *) 0x04000350 = var_r3;
    *(s16 *) 0x04000354 = (s16) arg2;
}
