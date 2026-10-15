#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021375ac;

void func_02088804(s32 arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(&data_021375ac, s8 *, 0x29) = (s8) arg0;
    M2C_FIELD(&data_021375ac, s8 *, 0x2A) = (s8) arg1;
    M2C_FIELD(&data_021375ac, s8 *, 0x2B) = (s8) arg2;
}
