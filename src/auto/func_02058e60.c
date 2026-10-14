/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_02144c04;

s32 func_02058e60(void *arg0) {
    u16 temp_r3;
    u8 temp_r1;
    void *temp_r1_2;
    void *temp_r1_3;
    void *temp_r2;
    void *temp_r2_2;
    void *temp_r2_3;
    void *temp_r2_4;

    temp_r2 = M2C_FIELD(arg0, void **, 8);
    temp_r1 = M2C_FIELD(temp_r2, u8 *, 1);
    temp_r3 = M2C_FIELD(temp_r2, u16 *, 2);
    switch (temp_r1) {                              /* irregular */
    case 2:
        temp_r2_2 = M2C_FIELD(arg0, void **, 4);
        M2C_FIELD(temp_r2_2, u16 *, 0xEC) = (u16) (M2C_FIELD(temp_r2_2, u16 *, 0xEC) ^ temp_r3);
        break;
    case 0:
        temp_r2_3 = M2C_FIELD(arg0, void **, 4);
        M2C_FIELD(temp_r2_3, u16 *, 0xEC) = (u16) (M2C_FIELD(temp_r2_3, u16 *, 0xEC) | temp_r3);
        break;
    case 1:
        M2C_FIELD(M2C_FIELD(arg0, void **, 4), u16 *, 0xEC) = temp_r3;
        break;
    }
    temp_r2_4 = M2C_FIELD(arg0, void **, 4);
    if (M2C_FIELD(temp_r2_4, u16 *, 0xEC) & 0x40) {
        M2C_FIELD(temp_r2_4, s8 *, 0x82) = 0;
    } else {
        M2C_FIELD(temp_r2_4, s8 *, 0x82) = 1;
    }
    temp_r1_2 = M2C_FIELD(arg0, void **, 4);
    if ((M2C_FIELD(temp_r1_2, u16 *, 0xEC) & 1) && (&data_02144c04 != temp_r1_2)) {
        temp_r1_3 = M2C_FIELD(M2C_FIELD(temp_r1_2, void **, 0), void **, 0x10);
        M2C_FIELD(temp_r1_3, s32 *, 0) = (s32) (M2C_FIELD(M2C_FIELD(temp_r1_3, void **, 8), u16 *, 4) << 0xC);
    }
    return 4;
}
