/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02087f48(void);

void func_02084694(s32 arg0) {
    u8 var_r0;

    if ((u32) (func_02087f48() & 0x1F) < (u32) M2C_FIELD(arg0, u8 *, 0x16)) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    M2C_FIELD(arg0, u8 *, 7) = (u8) ((M2C_FIELD(arg0, u8 *, 7) & ~4) | ((var_r0 & 1) * 4));
}
