/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020d135c();
extern M2C_UNK data_0213b890;

void func_020d0f74(void) {
    u8 *temp_r1;
    u8 temp_r0;

    temp_r1 = (u8 *) &data_0213b890;
    temp_r0 = temp_r1[0x1E];
    switch (temp_r0) {
        case 0:
            temp_r1[0x1E] = 1U;
            func_020d135c();
            break;
        case 1:
            if (*M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x20), s32 **, 0x10) == 0xD000) {
                temp_r1[0x1E] = 2U;
            }
            break;
    }
}
