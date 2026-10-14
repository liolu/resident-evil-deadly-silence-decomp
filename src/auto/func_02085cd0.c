#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_021374cc;

s32 func_02085cd0(void) {
    return M2C_FIELD(&data_021374cc, s32 *, 0x24);
}
