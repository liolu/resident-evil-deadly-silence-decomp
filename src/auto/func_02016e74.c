#include "engine.h"
#include "m2c.h"

void func_02016df4(M2C_UNK);

void func_02016e74(s32 arg0) {
    u8 temp_r2;

    temp_r2                  = M2C_FIELD(arg0, u8 *, 4);
    M2C_FIELD(arg0, u8 *, 4) = (u8) (temp_r2 - 1);
    if (temp_r2 == 0) {
        M2C_FIELD(arg0, s8 *, 0)     = 0x16;
        M2C_FIELD(arg0, s16 *, 0x12) = 0;
        M2C_FIELD(arg0, s16 *, 0xA)  = (s16) M2C_FIELD(arg0, u8 *, 6);
    }
    func_02016df4(arg0);
}
