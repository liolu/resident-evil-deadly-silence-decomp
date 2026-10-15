/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

s32 func_020a3120(s32 arg0) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0);
    if (temp_r2 == NULL) {
        return 0;
    }
    if ((M2C_FIELD(arg0, u8 *, 8) & 1) && (M2C_FIELD(temp_r2, s32 *, 0xC) != 0) && (M2C_FIELD(arg0, u8 *, 0xB) != 0) &&
        (M2C_FIELD(arg0, u8 *, 0x52) != 0)) {
        return 1;
    }
    return 0;
}
