#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021374cc;

s32 func_02085fb4(void) {
    if (M2C_FIELD(&data_021374cc, u8 *, 8) == 1) {
        return 1;
    }
    return 0;
}
