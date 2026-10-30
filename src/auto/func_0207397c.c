/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_02072768();                            /* extern */
M2C_UNK func_02073020();                            /* extern */
s32 func_02088648();                                /* extern */
M2C_UNK func_02092bac(u32);                         /* extern */
M2C_UNK func_020b64d0();                            /* extern */
extern M2C_UNK data_0213bb18;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_02144cc0;

s32 func_0207397c(s32 *arg0) {
    u32 temp_r0;
    u32 temp_r0_2;

    if (func_02088648() != 0) {
        return 0;
    }
    if ((s32) M2C_FIELD(&data_02144bc0, s16 *, 0xD8) < 0) {
        M2C_FIELD(&data_0213bdcc, s32 *, 0x44) = (s32) (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) | 0x01000000);
    }
    temp_r0 = (u32) (M2C_FIELD(&data_0213bb18, u8 *, 0x1C8) << 0x1F) >> 0x1F;
    if (temp_r0 != 0) {
        func_02092bac(temp_r0);
        *arg0 = 4;
        func_02072768();
        func_020b64d0();
        return 1;
    }
    temp_r0_2 = M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & 0x01000000;
    if (temp_r0_2 != 0) {
        func_02092bac(temp_r0_2);
        *arg0                                 = 1;
        M2C_FIELD(&data_02144cc0, s8 *, 0xE2) = 1;
        func_02073020();
        func_020b64d0();
    }
    return 0;
}
