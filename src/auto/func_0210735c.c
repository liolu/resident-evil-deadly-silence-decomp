/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0215a6c0;

void func_0210735c(s32 arg0) {
    M2C_UNK (*temp_r1)(s32);
    s32 temp_r3;

    temp_r3 = ((u8) arg0 * 0xC) + (s32) &data_0215a6c0;
    if ((u8) (arg0 >> 8) != M2C_FIELD(temp_r3, u8 *, 8)) {
        return;
    }
    temp_r1 = M2C_FIELD(temp_r3, M2C_UNK (**)(s32), 0);
    if (temp_r1 == NULL) {
        return;
    }
    temp_r1(M2C_FIELD(temp_r3, s32 *, 4));
}
