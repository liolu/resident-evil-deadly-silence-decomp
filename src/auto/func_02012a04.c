/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern void *data_0213ad2c;

void func_02012a04(s32 arg0, s32 arg1) {
    M2C_FIELD(arg1, s16 *, 0xE) = (s16) (M2C_FIELD(arg1, s16 *, 0xE) - 0x1E);
    M2C_FIELD(arg1, u8 *, 0xE4) = (u8) (M2C_FIELD(arg1, u8 *, 0xE4) - 1);
    if (M2C_FIELD(arg1, u8 *, 0xE4) != 0) {
        return;
    }
    M2C_FIELD(arg1, s16 *, 0x12) = 0x12C;
    M2C_FIELD(arg1, s16 *, 0x14) = 0x104;
    if (M2C_FIELD(data_0213ad2c, u8 *, 8) == 5) {
        M2C_FIELD(arg1, u8 *, 0xE4) = 0x78U;
        M2C_FIELD(arg0, s8 *, 5)    = 7;
        return;
    }
    M2C_FIELD(arg1, u8 *, 0xE4) = 0x32U;
    M2C_FIELD(arg0, s8 *, 5)    = 3;
}
