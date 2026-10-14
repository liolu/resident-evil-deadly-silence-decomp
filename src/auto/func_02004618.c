/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02136eb0;

s32 func_02004618(void) {
    if ((M2C_FIELD(&data_02136eb0, s32 *, 0x1A8) == 1) || (M2C_FIELD(&data_02136eb0, s32 *, 0x1A8) == 4) || (M2C_FIELD(&data_02136eb0, s32 *, 0x1A8) == 7)) {
        return 1;
    }
    return 0;
}
