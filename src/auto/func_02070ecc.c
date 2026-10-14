#include "m2c.h"
#include "engine.h"

void func_02070ecc(s32 arg0, s32 arg1) {
    M2C_FIELD(arg1, u8 *, 0) = (u8) M2C_FIELD(arg0, u8 *, 0);
    M2C_FIELD(arg1, u8 *, 1) = (u8) M2C_FIELD(arg0, u8 *, 1);
    M2C_FIELD(arg1, u8 *, 2) = (u8) M2C_FIELD(arg0, u8 *, 2);
    M2C_FIELD(arg1, u8 *, 3) = (u8) M2C_FIELD(arg0, u8 *, 3);
}
