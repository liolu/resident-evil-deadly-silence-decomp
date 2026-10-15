#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_021375ac;

s32 func_02088550(void) {
    M2C_FIELD(&data_021375ac, volatile u8 *, 0x28) = (u8) (M2C_FIELD(&data_021375ac, volatile u8 *, 0x28) + 1);
    M2C_FIELD(&data_021375ac, volatile u8 *, 0x28) = (u8) (M2C_FIELD(&data_021375ac, volatile u8 *, 0x28) & 0x7F);
    return (s32) (u8) (M2C_FIELD(&data_021375ac, volatile u8 *, 0x28) + 1);
}
