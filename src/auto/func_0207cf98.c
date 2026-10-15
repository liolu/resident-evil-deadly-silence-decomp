/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020823b4(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_02082e2c(M2C_UNK);
void func_02083d28(M2C_UNK);

void func_0207cf98(s32 arg0) {
    u8 temp_r1;
    void *temp_lr;

    temp_lr = M2C_FIELD(arg0, void **, 0);
    temp_r1 = M2C_FIELD(temp_lr, u8 *, 0x93);
    if ((u32) temp_r1 >= 0x13U) {
        M2C_FIELD(temp_lr, s8 *, 0x92) = 3;
        func_020823b4(arg0, 0xB, 0, 1);
        func_02083d28(arg0);
    } else {
        if (temp_r1 == 4) {
            M2C_FIELD(temp_lr, u8 *, 0x93) = 9U;
        }
        func_02082e2c(arg0);
    }
    M2C_FIELD(arg0, u8 *, 7) = (u8) (M2C_FIELD(arg0, u8 *, 7) | 2);
}
