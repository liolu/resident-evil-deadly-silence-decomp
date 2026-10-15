/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020fad28(s32 arg0, s32 arg1, s32 arg2) {
    u32 temp_r2;
    void *temp_lr;

    temp_lr           = M2C_FIELD(arg1, void **, 8);
    temp_r2           = (((s32) M2C_FIELD(arg1, s32 *, 0) >> 0xC) * M2C_FIELD(temp_lr, u16 *, 6)) + arg2;
    *(M2C_UNK *) arg0 = (s32) (M2C_FIELD((temp_lr + ((temp_r2 >> 5) * 4)), s32 *, 0xC) & (1 << (temp_r2 & 0x1F)));
}
