/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

s32 func_02082398(s32 arg0, s32 arg1) {
    if ((u32) arg1 < (u32) M2C_FIELD(arg0, u8 *, 0x38)) {
        return *M2C_FIELD(arg0, s32 **, 0x34) + (arg1 * 8);
    }
    return 0;
}
