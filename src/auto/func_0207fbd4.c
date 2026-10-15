/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02084a1c(M2C_UNK, M2C_UNK, M2C_UNK);
void func_02091bd0(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213ad48;

void func_0207fbd4(s32 arg0) {
    u8 temp_r1_3;
    void *temp_r1;
    void *temp_r1_2;
    void *temp_r1_4;
    void *temp_r2;

    temp_r1                        = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(temp_r1, u8 *, 0x93) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x93) - 1);
    temp_r1_2                      = M2C_FIELD(arg0, void **, 0);
    if (M2C_FIELD(temp_r1_2, u8 *, 0x93) == 0) {
        M2C_FIELD(temp_r1_2, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1_2, u8 *, 0x92) + 1);
    }
    if (M2C_FIELD(&data_0213ad48, u8 *, 6) != 0) {
        temp_r2   = M2C_FIELD(arg0, void **, 0);
        temp_r1_3 = M2C_FIELD(temp_r2, u8 *, 0x93);
        if ((temp_r1_3 & 0x80) && ((s32) (temp_r1_3 & ~0x80) < 0xA)) {
            func_02091bd0(0x34, (s32) (temp_r2 + 0x30));
            temp_r1_4                        = M2C_FIELD(arg0, void **, 0);
            M2C_FIELD(temp_r1_4, u8 *, 0x93) = (u8) (M2C_FIELD(temp_r1_4, u8 *, 0x93) & ~0x80);
        }
    }
    func_02084a1c(arg0, (s32) M2C_FIELD(M2C_FIELD(arg0, void **, 0), u16 *, 0x44), M2C_FIELD(arg0, s32 *, 0x1D0));
}
