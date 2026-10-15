/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02017a04(s32 arg0) {
    if ((s32) (M2C_FIELD(arg0, s16 *, 0x22) + M2C_FIELD(arg0, s16 *, 0x12)) < 0) {
        return;
    }
    M2C_FIELD(arg0, s8 *, 0)     = 1;
    M2C_FIELD(arg0, s8 *, 1)     = 1;
    M2C_FIELD(arg0, u16 *, 0xE)  = (u16) (M2C_FIELD(arg0, u16 *, 0xE) | 0x4007);
    M2C_FIELD(arg0, s16 *, 8)    = 0;
    M2C_FIELD(arg0, s16 *, 0xA)  = 0;
    M2C_FIELD(arg0, s16 *, 0xC)  = 0;
    M2C_FIELD(arg0, s16 *, 0x10) = 0;
    M2C_FIELD(arg0, s16 *, 0x12) = 0;
    M2C_FIELD(arg0, s16 *, 0x14) = 0;
    M2C_FIELD(arg0, s16 *, 0x1A) = (s16) (0 - (M2C_FIELD(arg0, s16 *, 0x2A) + M2C_FIELD(arg0, s32 *, 0x48)));
}
