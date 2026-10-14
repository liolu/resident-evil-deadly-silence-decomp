#include "m2c.h"

extern M2C_UNK data_0213b890;

void func_020cd200(s8 *arg0) {
    s8 temp_r2;
    u8 temp_r1;

    temp_r2 = *arg0;
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), u8 *, 0x12);
    if ((s32) temp_r2 >= (s32) temp_r1) {
        *arg0 = temp_r2 - temp_r1;
        return;
    }
    if ((s32) temp_r2 < 0) {
        *arg0 = temp_r1 + temp_r2;
    }
}
