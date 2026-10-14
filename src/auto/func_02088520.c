#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_021375ac;

s32 func_02088520(void) {
    return M2C_FIELD(&data_021375ac, s32 *, 0x1C);
}
