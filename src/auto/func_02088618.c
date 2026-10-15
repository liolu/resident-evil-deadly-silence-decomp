#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021375ac;

s32 func_02088618(void) {
    return M2C_FIELD(&data_021375ac, s32 *, 0x48);
}
