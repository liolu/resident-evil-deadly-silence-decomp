/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020ac214(M2C_UNK);
void func_020ac2a4(M2C_UNK);

extern M2C_UNK data_0213bdcc;

void func_020aafec(s32 arg0) {
    s16 temp_r1;

    if (M2C_FIELD(arg0, u8 *, 0x93) == 0) {
        M2C_FIELD(arg0, u8 *, 0x93) = 1U;
        M2C_FIELD(arg0, s16 *, 0xA8) = 0xF;
        func_020ac2a4(0);
        if (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 1) {
            func_020ac214(0);
        }
    }
    temp_r1 = M2C_FIELD(arg0, s16 *, 0xA8);
    M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (temp_r1 - 1);
    if (temp_r1 == 0) {
        M2C_FIELD(arg0, s8 *, 0x92) = 0x13;
        M2C_FIELD(arg0, u8 *, 0x93) = 0U;
    }
}
