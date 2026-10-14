/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_021543a4;

void func_020f47bc(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != 0) {
        *(M2C_UNK *)arg0 = (s32) (u8) M2C_FIELD(&data_021543a4, u32 *, 0xA0);
    }
    if (arg1 != 0) {
        *(M2C_UNK *)arg1 = (s32) (u8) ((u32) M2C_FIELD(&data_021543a4, u32 *, 0xA0) >> 8);
    }
    if (arg2 != 0) {
        *(M2C_UNK *)arg2 = (s32) (u8) ((u32) M2C_FIELD(&data_021543a4, u32 *, 0xA0) >> 0x10);
    }
    if (arg3 != 0) {
        *(M2C_UNK *)arg3 = (s32) (u8) ((u32) M2C_FIELD(&data_021543a4, u32 *, 0xA0) >> 0x18);
    }
}
