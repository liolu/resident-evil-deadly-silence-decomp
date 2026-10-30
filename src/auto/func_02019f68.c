/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_01ffd214(M2C_UNK *, M2C_UNK);          /* extern */
M2C_UNK func_02018708(M2C_UNK);                     /* extern */
s32 func_02018870(void *, M2C_UNK);                 /* extern */
s32 func_020188dc(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_020189a4(M2C_UNK, void *);             /* extern */
M2C_UNK func_0205597c(M2C_UNK);                     /* extern */
M2C_UNK func_020b818c(M2C_UNK, void *, M2C_UNK);    /* extern */
extern u16 data_0213ad98;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_02144c34;

void func_02019f68(void *arg0) {
    u8 temp_r0;
    void *temp_lr;
    void *temp_r1;
    void *temp_r3;

    temp_r0 = M2C_FIELD(arg0, u8 *, 0x93);
    switch (temp_r0) {                              /* irregular */
        case 0:
            temp_lr                       = arg0 + 0x17C;
            M2C_FIELD(temp_lr, s16 *, 6)  = (s16) (M2C_FIELD(temp_lr, s16 *, 6) | 1);
            M2C_FIELD(temp_lr, u8 *, 0xE) = (u8) (M2C_FIELD(temp_lr, u8 *, 0xE) | 1);
            M2C_FIELD(arg0, s16 *, 0xA6)  = 0x2D;
            M2C_FIELD(arg0, u8 *, 0x93)   = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
            M2C_FIELD(arg0, s8 *, 0xA2)   = 0;
            M2C_FIELD(arg0, s8 *, 0xA3)   = 0;
            M2C_FIELD(arg0, s8 *, 0x98)   = 3;
            M2C_FIELD(arg0, s8 *, 0xA1)   = 3;
            func_0205597c(2);
            temp_r3                       = arg0 + 0x17C;
            M2C_FIELD(temp_r3, u8 *, 0xE) = (u8) (M2C_FIELD(temp_r3, u8 *, 0xE) | 8);
            func_020189a4(6, arg0);
        /* fallthrough */
        case 1:
            func_02018708(9);
            func_01ffd214(&data_02144c34, 0x20);
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
            if (func_020188dc(arg0, 0, 0x200, 5) != 0) {
                M2C_FIELD(arg0, s8 *, 0x90) = 3;
                M2C_FIELD(arg0, s8 *, 0x91) = 1;
                M2C_FIELD(arg0, s8 *, 0x92) = 0;
                M2C_FIELD(arg0, u8 *, 0x93) = 0U;
                func_0205597c(7);
                temp_r1                       = arg0 + 0x17C;
                M2C_FIELD(temp_r1, u8 *, 0xE) = (u8) (M2C_FIELD(temp_r1, u8 *, 0xE) & ~8);
            }
            return;
    }
}
