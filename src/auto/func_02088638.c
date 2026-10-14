#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_021375ac;

s32 func_02088638(void) {
    return (s32) M2C_FIELD(&data_021375ac, u8 *, 2);
}
