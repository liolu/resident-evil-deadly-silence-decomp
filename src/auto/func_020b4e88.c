/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern void *data_0213daa8;
extern void *data_0214d068[];
extern void *data_0214dbec[];

s32 func_020b4e88(void) {
    u8 temp_r1;
    void *temp_r2;
    void *var_r3;

    temp_r2       = data_0213daa8;
    data_0213daa8 = (u8 *) temp_r2 + 0xE;
    temp_r1       = M2C_FIELD(temp_r2, u8 *, 1);
    if (temp_r1 < 0x80U) {
        var_r3 = data_0214dbec[temp_r1];
    } else {
        var_r3 = data_0214d068[temp_r1 - 0x80];
    }
    M2C_FIELD(var_r3, s16 *, 0x42) = (s16) M2C_FIELD(temp_r2, s16 *, 2);
    M2C_FIELD(var_r3, s16 *, 0x44) = (s16) M2C_FIELD(temp_r2, s16 *, 4);
    M2C_FIELD(var_r3, s16 *, 0x46) = (s16) M2C_FIELD(temp_r2, s16 *, 6);
    M2C_FIELD(var_r3, s32 *, 0x30) = (s32) M2C_FIELD(temp_r2, s16 *, 8);
    M2C_FIELD(var_r3, s32 *, 0x34) = (s32) M2C_FIELD(temp_r2, s16 *, 0xA);
    M2C_FIELD(var_r3, s32 *, 0x38) = (s32) M2C_FIELD(temp_r2, s16 *, 0xC);
    M2C_FIELD(var_r3, s16 *, 0x3C) = (s16) M2C_FIELD(var_r3, s32 *, 0x30);
    M2C_FIELD(var_r3, s16 *, 0x3E) = (s16) M2C_FIELD(var_r3, s32 *, 0x34);
    M2C_FIELD(var_r3, s16 *, 0x40) = (s16) M2C_FIELD(var_r3, s32 *, 0x38);
    return 1;
}
