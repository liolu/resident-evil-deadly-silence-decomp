#include "m2c.h"
#include "engine.h"

void func_0208256c(s32 arg0) {
    void *temp_r1;
    void *temp_r2;

    temp_r2 = *(M2C_UNK *)arg0;
    if ((s32) M2C_FIELD(temp_r2, volatile s32 *, 0x38) > 0) {
        M2C_FIELD(temp_r2, volatile s8 *, 0x93) = 0;
    } else {
        M2C_FIELD(temp_r2, volatile s8 *, 0x93) = 1;
    }
    temp_r1 = *(M2C_UNK *)arg0;
    M2C_FIELD(temp_r1, volatile u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, volatile u8 *, 0x92) + 1);
}
