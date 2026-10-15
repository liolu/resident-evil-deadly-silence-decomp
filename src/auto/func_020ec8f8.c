/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

s32 func_020ec8f8(s32 arg0) {
    void **temp_r0;

    temp_r0 = M2C_FIELD(arg0, void ***, 4);
    if ((M2C_FIELD(*temp_r0, s32(**)(void **, M2C_UNK), 0x24)(temp_r0, 1) == 0) && (M2C_FIELD(arg0, s32 *, 0xC) == 0) &&
        (M2C_FIELD(arg0, s32 *, 0x24) == 0)) {
        return 1;
    }
    return 0;
}
