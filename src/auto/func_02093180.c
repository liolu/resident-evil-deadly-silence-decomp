/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02105528(void);

void func_02093180(s32 arg0, s32 arg1, s32 arg2) {
    if (M2C_FIELD(arg0, s32 *, 0x18) != 0) {
        M2C_FIELD(arg0, u8 *, 4) = (u8) (M2C_FIELD(arg0, u8 *, 4) + 1);
        if ((u32) M2C_FIELD(arg0, u8 *, 4) >= 4U) {
            func_02105528();
        }
    }
    M2C_FIELD((arg0 + M2C_FIELD(arg0, u8 *, 4)), s8 *, 0x14)        = (s8) arg2;
    M2C_FIELD((arg0 + (M2C_FIELD(arg0, u8 *, 4) * 4)), s32 *, 0x18) = arg1;
}
