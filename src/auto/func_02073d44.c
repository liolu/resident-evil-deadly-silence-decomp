/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02073d44(s32 arg0) {
    if (M2C_FIELD(arg0, u16 *, 0) == M2C_FIELD(arg0, u16 *, 4)) {
        M2C_FIELD(arg0, u8 *, 8) = (u8) (M2C_FIELD(arg0, u8 *, 8) - 1);
        if (M2C_FIELD(arg0, u8 *, 8) == 0) {
            M2C_FIELD(arg0, u8 *, 8)  = 4U;
            M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg0, u16 *, 0);
        } else {
            M2C_FIELD(arg0, u16 *, 6) = 0U;
        }
        return;
    }
    M2C_FIELD(arg0, u8 *, 8)  = 0x14U;
    M2C_FIELD(arg0, u16 *, 6) = (u16) M2C_FIELD(arg0, u16 *, 2);
}
