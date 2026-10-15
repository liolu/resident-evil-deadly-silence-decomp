#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021375ac;

s32 func_02088530(void) {
    return (s32) M2C_FIELD(&data_021375ac, u8 *, 0x23);
}
