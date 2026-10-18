/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_01ffd504(s16);                         /* extern */
s32 func_02018870(void *, M2C_UNK);                 /* extern */
M2C_UNK func_020188dc(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020189a4(M2C_UNK, void *);             /* extern */
M2C_UNK func_0205597c(M2C_UNK);                     /* extern */
M2C_UNK func_020b818c(M2C_UNK, void *, M2C_UNK);    /* extern */
extern M2C_UNK data_0211c078;
extern M2C_UNK data_0211c07a;
extern M2C_UNK data_0211c07c;
extern u16 data_0213ad98;
extern M2C_UNK data_0213bdcc;

void func_0201aaf4(void *arg0) {
    s16 temp_r1;

    if (M2C_FIELD(arg0, u8 *, 0x93) == 0) {
        M2C_FIELD(arg0, u8 *, 0x93)  = 1U;
        M2C_FIELD(arg0, s8 *, 0xA2)  = 0;
        M2C_FIELD(arg0, s8 *, 0xA3)  = 0;
        M2C_FIELD(arg0, s8 *, 0x98)  = 3;
        M2C_FIELD(arg0, s16 *, 0xA6) = 0xF;
        M2C_FIELD(arg0, s8 *, 0xA1)  = 3;
        func_0205597c(2);
        func_01ffd504(*((s16 *) ((s8 *) &data_0211c078 + (M2C_FIELD(arg0, u8 *, 0x17C) * 6))));
        M2C_FIELD(arg0, s16 *, 0xA8) = (s16) * ((s16 *) ((s8 *) &data_0211c07a + (M2C_FIELD(arg0, u8 *, 0x17C) * 6)));
    }
    if (func_02018870(arg0, 0xB) != 0) {
        if ((data_0213ad98 == 0x203) && (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 0x20000)) {
            func_020b818c(0xCE, arg0 + 0x30, 0);
        } else {
            func_020189a4(1, arg0);
        }
    }
    if (func_02018870(arg0, 0x23) != 0) {
        if ((data_0213ad98 == 0x203) && (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 0x20000)) {
            func_020b818c(0xCE, arg0 + 0x30, 0);
        } else {
            func_020189a4(1, arg0);
        }
    }
    M2C_FIELD(arg0, s16 *, 0x44) =
        (s16) (M2C_FIELD(arg0, s16 *, 0x44) - *((s16 *) ((s8 *) &data_0211c07c + (M2C_FIELD(arg0, u8 *, 0x17C) * 6))));
    func_020188dc(arg0, 1, 0x400, 5);
    temp_r1                      = M2C_FIELD(arg0, s16 *, 0xA8);
    M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (temp_r1 - 1);
    if (temp_r1 == 0) {
        M2C_FIELD(arg0, s8 *, 0x91) = 1;
        M2C_FIELD(arg0, s8 *, 0x92) = 4;
        M2C_FIELD(arg0, u8 *, 0x93) = 0U;
    }
    M2C_FIELD(arg0, s32 *, 0x30) = (s32) (M2C_FIELD(arg0, s32 *, 0x30) + M2C_FIELD(arg0, s16 *, 0x48));
    M2C_FIELD(arg0, s32 *, 0x34) = (s32) (M2C_FIELD(arg0, s32 *, 0x34) + M2C_FIELD(arg0, s16 *, 0x4A));
    M2C_FIELD(arg0, s32 *, 0x38) = (s32) (M2C_FIELD(arg0, s32 *, 0x38) + M2C_FIELD(arg0, s16 *, 0x4C));
}
