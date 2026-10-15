/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_021027c8(M2C_UNK);

extern s32 data_02153014;
extern s32 data_02153018;

void func_020e65c8(void) {
    s32 temp_r4;

    if (data_02153014 == 0) {
        temp_r4 = *(s32 *) 0x04000210;
        func_021027c8(1);
        data_02153018 = temp_r4;
    }
    data_02153014 += 1;
}
