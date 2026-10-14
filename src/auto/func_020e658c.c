/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02102810(M2C_UNK);

extern s32 data_02153014;

void func_020e658c(void) {
    s32 temp_r1;

    temp_r1 = data_02153014 - 1;
    data_02153014 = temp_r1;
    if (temp_r1 != 0) {
        return;
    }
    func_02102810(1);
}
