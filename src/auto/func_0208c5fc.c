/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

s32 func_0208c5fc(s32 arg0, s32 arg1) {
    if (((s32) M2C_FIELD(arg0, s16 *, 0x4C0) < arg1) && ((s32) M2C_FIELD(arg0, s16 *, 0x4C2) < arg1)) {
        return 0;
    }
    M2C_FIELD(arg0, s16 *, 0x4C0) = 0;
    M2C_FIELD(arg0, s16 *, 0x4C2) = 0;
    M2C_FIELD(arg0, s8 *, 0x4BE) = (s8) (M2C_FIELD(arg0, s8 *, 0x4BE) + 1);
    return 1;
}
