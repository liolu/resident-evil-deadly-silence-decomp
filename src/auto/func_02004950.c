#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_02136eb0;

s32 func_02004950(void) {
    if ((s32) M2C_FIELD(&data_02136eb0, s32 *, 0x1A8) < 0) {
        return 1;
    }
    return 0;
}
