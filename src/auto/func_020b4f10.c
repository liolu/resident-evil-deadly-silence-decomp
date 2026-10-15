/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void *func_02053e90(u8);                            /* extern */
extern void *data_0213daa8;

s32 func_020b4f10(void) {
    void *temp_r0;
    void *temp_r4;

    temp_r4                         = data_0213daa8;
    data_0213daa8                   = temp_r4 + 0xE;
    temp_r0                         = func_02053e90(M2C_FIELD(temp_r4, u8 *, 1));
    M2C_FIELD(temp_r0, u16 *, 0xEC) = (u16) (M2C_FIELD(temp_r0, u16 *, 0xEC) & 0xFFF3);
    M2C_FIELD(temp_r0, s16 *, 0x42) = (s16) M2C_FIELD(temp_r4, s16 *, 2);
    M2C_FIELD(temp_r0, s16 *, 0x44) = (s16) M2C_FIELD(temp_r4, s16 *, 4);
    M2C_FIELD(temp_r0, s16 *, 0x46) = (s16) M2C_FIELD(temp_r4, s16 *, 6);
    M2C_FIELD(temp_r0, s32 *, 0x30) = (s32) M2C_FIELD(temp_r4, s16 *, 8);
    M2C_FIELD(temp_r0, s32 *, 0x34) = (s32) M2C_FIELD(temp_r4, s16 *, 0xA);
    M2C_FIELD(temp_r0, s32 *, 0x38) = (s32) M2C_FIELD(temp_r4, s16 *, 0xC);
    M2C_FIELD(temp_r0, s16 *, 0x3C) = (s16) M2C_FIELD(temp_r0, s32 *, 0x30);
    M2C_FIELD(temp_r0, s16 *, 0x3E) = (s16) M2C_FIELD(temp_r0, s32 *, 0x34);
    M2C_FIELD(temp_r0, s16 *, 0x40) = (s16) M2C_FIELD(temp_r0, s32 *, 0x38);
    return 1;
}
