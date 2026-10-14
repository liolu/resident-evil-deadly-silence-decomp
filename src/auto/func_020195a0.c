/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_01ffd504(M2C_UNK);                     /* extern */
s32 func_02018870(void *, M2C_UNK);                 /* extern */
s32 func_0201893c(void *, M2C_UNK, M2C_UNK);        /* extern */
M2C_UNK func_0205597c(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02143cc0;

void func_020195a0(void *arg0) {
    s16 temp_r1;
    u8 temp_r0;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x93);
    switch (temp_r0) {                              /* irregular */
    case 0:
        M2C_FIELD(arg0, u8 *, 0x93) = 1U;
        M2C_FIELD(arg0, s8 *, 0xA2) = 0xC;
        M2C_FIELD(arg0, s8 *, 0xA3) = 1;
        M2C_FIELD(arg0, s8 *, 0x96) = 1;
        M2C_FIELD(arg0, s16 *, 0xA6) = 0x1E;
        M2C_FIELD(arg0, s8 *, 0xA1) = 7;
        func_0205597c(6);
        M2C_FIELD(arg0, s8 *, 0x98) = 3;
        /* fallthrough */
    case 1:
        if (func_0201893c(arg0, 0, 0x400) != 0) {
            M2C_FIELD(arg0, u8 *, 0x93) = 2U;
            M2C_FIELD(arg0, s16 *, 0xA8) = (s16) ((M2C_FIELD(&data_0213ad98, u16 *, 0x1A) & 7) + 0x10);
            M2C_FIELD(arg0, s16 *, 0xA6) = 0xF;
        } else if (func_02018870(arg0, 0x14) != 0) {
            M2C_FIELD(arg0, s8 *, 0x96) = 0;
        }
        break;
    case 2:
        temp_r1 = M2C_FIELD(arg0, s16 *, 0xA8);
        M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (temp_r1 - 1);
        if (temp_r1 == 0) {
            M2C_FIELD(arg0, s8 *, 0x90) = 1;
            M2C_FIELD(arg0, s8 *, 0x91) = 0;
            M2C_FIELD(arg0, s8 *, 0x92) = 2;
            M2C_FIELD(arg0, u8 *, 0x93) = 2U;
            M2C_FIELD(arg0, s16 *, 0x176) = (s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF74);
            M2C_FIELD(arg0, s16 *, 0x178) = (s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF7C);
            M2C_FIELD(arg0, s8 *, 0x96) = 0;
        }
        break;
    }
    func_01ffd504(0x800);
}
