/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02076ecc();                            /* extern */
void *func_020771d4(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK func_020f4488(void *, s32);                 /* extern */
M2C_UNK func_020f46c0(s32, s32, s32, M2C_UNK);      /* extern */
s32 func_020f82a8(M2C_UNK *, s32, s32);             /* extern */
s32 func_020f8b40(s32, M2C_UNK);                    /* extern */
extern M2C_UNK data_0213b38c;
extern s32 data_021402e8;

void func_02076f18(void *arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s32 temp_r0_2;
    s32 temp_r0_3;
    void *temp_r0;
    void *temp_r1;

    func_02076ecc();
    temp_r0                      = func_020771d4(arg1, arg2);
    M2C_FIELD(arg0, void **, 8)  = temp_r0;
    temp_r0_2                    = func_020f8b40(M2C_FIELD(temp_r0, s32 *, 4), 0);
    M2C_FIELD(arg0, s32 *, 0x10) = func_020f82a8(&data_0213b38c, temp_r0_2, M2C_FIELD(arg0, s32 *, 0xC));
    func_020f46c0(M2C_FIELD(arg0, s32 *, 0x10), temp_r0_2, M2C_FIELD(arg0, s32 *, 0xC), 0);
    func_020f4488(arg0 + 0x20, M2C_FIELD(arg0, s32 *, 0x10));
    M2C_FIELD(arg0, s32 *, 0x1C) = 0;
    temp_r1                      = M2C_FIELD(arg0, void **, 0x14);
    if (temp_r1 != NULL) {
        temp_r0_3                         = (M2C_FIELD(temp_r1, u8 *, 1) * 0x58) + data_021402e8;
        M2C_FIELD(temp_r0_3, s32 *, 0x4C) = 0;
        M2C_FIELD(temp_r0_3, s32 *, 0x50) = 0;
        M2C_FIELD(temp_r0_3, s32 *, 0x54) = 0;
    }
}
