/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
s32 func_02018870(void *, M2C_UNK);                 /* extern */
M2C_UNK func_020188dc(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020189a4(M2C_UNK, void *);             /* extern */
M2C_UNK func_0205597c(M2C_UNK);                     /* extern */
M2C_UNK func_020b818c(M2C_UNK, void *, M2C_UNK);    /* extern */
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c34;
extern s32 data_027e0024;

void func_0201b000(void *arg0) {
    s16 temp_r1;

    if (M2C_FIELD(arg0, u8 *, 0x93) == 0) {
        M2C_FIELD(arg0, s8 *, 0xA2) = 0;
        M2C_FIELD(arg0, s8 *, 0xA3) = 0;
        M2C_FIELD(arg0, s8 *, 0x98) = 3;
        M2C_FIELD(arg0, s8 *, 0x96) = 0;
        if (M2C_FIELD(arg0, s8 *, 0x188) & 0x80) {
            M2C_FIELD(arg0, s8 *, 0x96) = 1;
        }
        func_01ffd2c4(&data_02144c34, 0x400);
        M2C_FIELD(arg0, u8 *, 0x93)  = 1U;
        M2C_FIELD(arg0, s16 *, 0xA8) = (s16) ((M2C_FIELD(&data_0213ad98, u16 *, 0x1A) & 0x3F) + 0x1E);
        M2C_FIELD(arg0, s8 *, 0xA1)  = 3;
        func_0205597c(2);
    }
    if (((M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) && (M2C_FIELD(arg0, u8 *, 0x169) & 1)) ||
        (M2C_FIELD(arg0, u8 *, 0x16B) == 2)) {
        data_027e0024 = func_01ffd2c4(&data_02144c34, 0xA8);
    } else {
        data_027e0024 = func_01ffd2c4(&data_02144c34, 0x54);
    }
    temp_r1                      = M2C_FIELD(arg0, s16 *, 0xA8);
    M2C_FIELD(arg0, s16 *, 0xA8) = (s16) (temp_r1 - 1);
    if ((temp_r1 == 0) || (data_027e0024 == 0)) {
        M2C_FIELD(arg0, s8 *, 0x90)   = 1;
        M2C_FIELD(arg0, s8 *, 0x91)   = 0;
        M2C_FIELD(arg0, s8 *, 0x92)   = 2;
        M2C_FIELD(arg0, u8 *, 0x93)   = 2U;
        M2C_FIELD(arg0, s16 *, 0x176) = (s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF74);
        M2C_FIELD(arg0, s16 *, 0x178) = (s16) M2C_FIELD(&data_02143cc0, s32 *, 0xF7C);
        return;
    }
    func_020188dc(arg0, 1, 0x400, 5);
    M2C_FIELD(arg0, s16 *, 0x44) = (s16) (M2C_FIELD(arg0, s16 *, 0x44) + data_027e0024);
    if (func_02018870(arg0, 0xB) != 0) {
        if ((M2C_FIELD(&data_0213ad98, u16 *, 0) == 0x203) && (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 0x20000)) {
            func_020b818c(0xCE, arg0 + 0x30, 0);
        } else {
            func_020189a4(1, arg0);
        }
    }
    if (func_02018870(arg0, 0x23) != 0) {
        if ((M2C_FIELD(&data_0213ad98, u16 *, 0) == 0x203) && (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 0x20000)) {
            func_020b818c(0xCE, arg0 + 0x30, 0);
            return;
        }
        func_020189a4(1, arg0);
    }
}
