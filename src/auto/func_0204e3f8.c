/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0204b58c(void *);                      /* extern */

void func_0204e3f8(void *arg0) {
    void *temp_r2;

    temp_r2 = M2C_FIELD(arg0, void **, 0x9C);
    if (M2C_FIELD(temp_r2, s8 *, 0x18C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x90) = (s32) M2C_FIELD(temp_r2, s32 *, 0x188);
        return;
    }
    if (M2C_FIELD(temp_r2, u8 *, 0x18D) != 0) {
        M2C_FIELD(arg0, s32 *, 0x90) = (s32) M2C_FIELD(temp_r2, s32 *, 0x188);
        return;
    }
    if (M2C_FIELD(arg0, u8 *, 0x91) == 0) {
        M2C_FIELD(arg0, u8 *, 0x90) = 2;
        M2C_FIELD(arg0, u8 *, 0x91) = 1U;
        M2C_FIELD(arg0, s8 *, 0x92) = 0;
        M2C_FIELD(arg0, s8 *, 0x93) = 0;
    }
    func_0204b58c(arg0);
}
