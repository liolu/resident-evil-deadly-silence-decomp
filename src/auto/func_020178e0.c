/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_02144bc0;

void func_020178e0(s32 arg0) {
    M2C_FIELD(arg0, u16 *, 0xE) = 0x4003U;
    if ((s32) (M2C_FIELD(arg0, s16 *, 0x22) + M2C_FIELD(arg0, s16 *, 0x12)) <= (s32) M2C_FIELD(&data_02144bc0, s16 *, 0xDE)) {
        return;
    }
    M2C_FIELD(arg0, u16 *, 0xE) = (u16) (M2C_FIELD(arg0, u16 *, 0xE) | 0x400B);
    M2C_FIELD(arg0, s8 *, 0) = 0x2F;
    M2C_FIELD(arg0, s8 *, 1) = 0;
    M2C_FIELD(arg0, s16 *, 0x1A) = (s16) (M2C_FIELD(&data_02144bc0, s16 *, 0xDE) - (M2C_FIELD(arg0, s16 *, 0x2A) + M2C_FIELD(arg0, s32 *, 0x48)));
}
