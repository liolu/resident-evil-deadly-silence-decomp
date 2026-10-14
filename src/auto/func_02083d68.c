#include "m2c.h"
#include "engine.h"

void func_02083d68(s32 arg0) {
    M2C_FIELD(arg0, volatile u8 *, 0xD) = (u8) (M2C_FIELD(arg0, volatile u8 *, 0xD) | 4);
    M2C_FIELD(arg0, volatile u8 *, 0xD) = (u8) (M2C_FIELD(arg0, volatile u8 *, 0xD) | 2);
    M2C_FIELD(arg0, volatile u8 *, 0xD) = (u8) (M2C_FIELD(arg0, volatile u8 *, 0xD) | 0x10);
    M2C_FIELD(arg0, volatile u8 *, 0xD) = (u8) (M2C_FIELD(arg0, volatile u8 *, 0xD) | 8);
    M2C_FIELD(arg0, volatile u8 *, 0xD) = (u8) (M2C_FIELD(arg0, volatile u8 *, 0xD) & ~1);
}
