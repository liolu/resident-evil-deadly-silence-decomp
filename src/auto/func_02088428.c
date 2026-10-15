#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021375ac;

s32 func_02088428(void) {
    return (s32) M2C_FIELD(&data_021375ac, s8 *, 0xF);
}
