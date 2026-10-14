#include "m2c.h"
#include "engine.h"

void func_020827f8(s32 arg0) {
    void *temp_r1;

    temp_r1 = *(M2C_UNK *)arg0;
    M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
}
