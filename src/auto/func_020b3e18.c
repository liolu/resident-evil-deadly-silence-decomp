/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern void *data_0213daa8;
extern M2C_UNK data_0214bcc0;

s32 func_020b3e18(void) {
    s32 temp_r0;
    s32 temp_r3;
    void *temp_r1;
    s32 *temp_r3_2;

    temp_r1                      = data_0213daa8;
    data_0213daa8                = temp_r1 + 0x10;
    temp_r0                      = M2C_FIELD(temp_r1, u8 *, 1) * 0x2C;
    temp_r3                      = M2C_FIELD(&data_0214bcc0, s32 *, 0x7AC) + 0x70;
    *(s32 *) (temp_r3 + temp_r0) = (s32) M2C_FIELD(temp_r1, s16 *, 2);
    temp_r3_2                    = (s32 *) (temp_r3 + temp_r0);
    temp_r3_2[1]                 = (s32) M2C_FIELD(temp_r1, s16 *, 4);
    temp_r3_2[2]                 = (s32) M2C_FIELD(temp_r1, s16 *, 6);
    temp_r3_2[3]                 = (s32) M2C_FIELD(temp_r1, s16 *, 8);
    temp_r3_2[4]                 = (s32) M2C_FIELD(temp_r1, s16 *, 0xA);
    temp_r3_2[5]                 = (s32) M2C_FIELD(temp_r1, s16 *, 0xC);
    temp_r3_2[8]                 = (s32) M2C_FIELD(temp_r1, s16 *, 0xE);
    return 1;
}
