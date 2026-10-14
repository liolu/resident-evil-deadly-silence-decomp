/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0208302c(s32 arg0) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0);
    if ((u32) M2C_FIELD(temp_r2, u8 *, 0x93) >= (u32) M2C_FIELD(arg0, u8 *, 0x23)) {
        M2C_FIELD(temp_r2, u8 *, 0x92) = 0xFFU;
        return;
    }
    M2C_FIELD(temp_r2, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r2, u8 *, 0x92) + 1);
}
