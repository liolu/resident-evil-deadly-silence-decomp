/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_02070088(M2C_UNK *, u8, M2C_UNK, M2C_UNK);
M2C_UNK func_02070438(s32);
M2C_UNK func_02105528();
M2C_UNK func_0210626c(s32, M2C_UNK, M2C_UNK);
extern M2C_UNK data_0213b06c;

void func_0207758c(M2C_UNK arg0, s32 arg1) {
    s32 temp_r0;

    temp_r0 = func_02070088(&data_0213b06c, arg1, 0, 1);
    if (temp_r0 == 0) {
        func_02105528();
        return;
    }
    func_0210626c(temp_r0, arg0, 0x20);
    func_02070438(temp_r0);
}
