/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_0208aca8(void *);                          /* extern */
s32 func_0211851c(s32, M2C_UNK);                    /* extern */
extern M2C_UNK data_0213ad30;

void func_0208c540(void *arg0) {
    s32 var_r0;
    s32 var_r0_2;

    var_r0 = 0;
    if (M2C_FIELD(&data_0213ad30, u16 *, 2) & 1) {
        var_r0 += 4;
    }
    if (M2C_FIELD(&data_0213ad30, u16 *, 2) & 2) {
        var_r0 += 4;
    }
    if (M2C_FIELD(&data_0213ad30, u16 *, 2) & 0x400) {
        var_r0 += 4;
    }
    if (M2C_FIELD(&data_0213ad30, u16 *, 2) & 0x800) {
        var_r0 += 4;
    }
    if (M2C_FIELD(&data_0213ad30, u16 *, 2) & 0x40) {
        var_r0 += 8;
    }
    if (M2C_FIELD(&data_0213ad30, u16 *, 2) & 0x80) {
        var_r0 += 8;
    }
    if (M2C_FIELD(&data_0213ad30, u16 *, 2) & 0x20) {
        var_r0 += 0xC;
    }
    if (M2C_FIELD(&data_0213ad30, u16 *, 2) & 0x10) {
        var_r0 += 0xC;
    }
    M2C_FIELD(arg0, s16 *, 0x4C2) = (s16) (M2C_FIELD(arg0, s16 *, 0x4C2) + var_r0);
    if ((s32) M2C_FIELD(arg0, s16 *, 0x4C2) > 0x3E7) {
        M2C_FIELD(arg0, s16 *, 0x4C2) = 0x3E7;
    }
    var_r0_2 = func_0208aca8(arg0);
    if (var_r0_2 < 0x10) {
        var_r0_2 = 0;
    }
    M2C_FIELD(arg0, s16 *, 0x4C0) = (s16) (M2C_FIELD(arg0, s16 *, 0x4C0) + func_0211851c(var_r0_2, 4));
    if ((s32) M2C_FIELD(arg0, s16 *, 0x4C0) > 0x3E7) {
        M2C_FIELD(arg0, s16 *, 0x4C0) = 0x3E7;
    }
}
