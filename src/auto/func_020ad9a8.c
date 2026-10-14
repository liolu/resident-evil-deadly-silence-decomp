/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02143cc0;

s32 func_020ad9a8(void) {
    if ((M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) == 1) || (M2C_FIELD(&data_02143cc0, u8 *, 0xF4D) == 3)) {
        return 1;
    }
    return 0;
}
