/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern void *data_0213daa8;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_02144cc0;

s32 func_020b4f98(void) {
    s16 temp_ip;
    s16 temp_lr;
    s16 temp_r1_2;
    void *temp_r1;

    temp_r1                                 = data_0213daa8;
    data_0213daa8                           = temp_r1 + 0xE;
    M2C_FIELD(&data_02144cc0, u16 *, 0x30)  = (u16) (M2C_FIELD(&data_02144cc0, u16 *, 0x30) & 0xFFF3);
    M2C_FIELD(&data_02144bc0, s16 *, 0x86)  = (s16) M2C_FIELD(temp_r1, s16 *, 2);
    M2C_FIELD(&data_02144bc0, s16 *, 0x88)  = (s16) M2C_FIELD(temp_r1, s16 *, 4);
    M2C_FIELD(&data_02144bc0, s16 *, 0x8A)  = (s16) M2C_FIELD(temp_r1, s16 *, 6);
    temp_lr                                 = M2C_FIELD(temp_r1, s16 *, 8);
    M2C_FIELD(&data_02143cc0, s32 *, 0xF74) = (s32) temp_lr;
    temp_ip                                 = M2C_FIELD(temp_r1, s16 *, 0xA);
    M2C_FIELD(&data_02143cc0, s32 *, 0xF78) = (s32) temp_ip;
    temp_r1_2                               = M2C_FIELD(temp_r1, s16 *, 0xC);
    M2C_FIELD(&data_02143cc0, s32 *, 0xF7C) = (s32) temp_r1_2;
    M2C_FIELD(&data_02144bc0, s16 *, 0x80)  = temp_lr;
    M2C_FIELD(&data_02144bc0, s16 *, 0x82)  = temp_ip;
    M2C_FIELD(&data_02144bc0, s16 *, 0x84)  = temp_r1_2;
    return 1;
}
