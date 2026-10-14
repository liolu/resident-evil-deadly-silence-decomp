#include "m2c.h"

s32 func_02059208(void *arg0) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 4);
    M2C_FIELD(temp_r2, u8 *, 0xBC) = (u8) (M2C_FIELD(temp_r2, u8 *, 0xBC) & 0xEF);
    return 1;
}
