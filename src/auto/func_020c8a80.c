/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020b82fc(M2C_UNK);
M2C_UNK func_020c5ec8(void);

extern M2C_UNK data_0213b890;

void func_020c8a80(void) {
    s16 temp_r0_2;
    s32 temp_r0;
    u32 temp_r1;

    temp_r0 = func_020c5ec8();
    if (temp_r0 != 0) {
        func_020b82fc(0x80);
        temp_r1 = temp_r0 + 5;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x16) = 4;
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x21) = (s8) temp_r0;
        switch (temp_r1) {
        default:
            break;
        case 4:
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x21) = 0x1E;
            break;
        case 3:
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x21) = 0;
            break;
        case 2:
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x21) = 0x1D;
            break;
        case 1:
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x21) = 0x1B;
            break;
        case 0:
            M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x21) = 0x1C;
            break;
        }
    }
    temp_r0_2 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x16);
    if (temp_r0_2 != 0) {
        M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s16 *, 0x16) = (s16) (temp_r0_2 - 1);
        return;
    }
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x21) = -1;
}
