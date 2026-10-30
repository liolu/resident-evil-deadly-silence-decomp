/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_02072ea4();                            /* extern */
M2C_UNK func_020b64d0();                            /* extern */
M2C_UNK func_020b80e4();                            /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02143cc0;

void func_02073020(void) {
    s32 temp_lr;

    temp_lr                                = M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & 0xD1FD003F;
    M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = temp_lr;
    M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) & ~0x100);
    M2C_FIELD(&data_0213ad98, s8 *, 5)     = 0;
    if (temp_lr & 0x40000) {
        func_020b64d0();
        func_020b80e4();
        M2C_FIELD(&data_0213ad98, s16 *, 0x16) = -1;
        M2C_FIELD(&data_0213ad98, s8 *, 8)     = 0;
        func_0206fcf8(0, 0, 1, 0x1000);
        M2C_FIELD(&data_02143cc0, s8 *, 0xF4A) = 0;
        return;
    }
    func_02072ea4();
    if (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 0x10000000) {
        func_0206fcf8(0, 0, 1, 0x80);
        return;
    }
    if (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 0x80000000) {
        func_0206fcf8(0, 0, 1, 0x20);
        return;
    }
    func_0206fcf8(0, 0, 1, 0x10);
}
