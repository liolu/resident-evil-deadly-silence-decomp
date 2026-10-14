/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern void **data_02137338;
extern void *data_027e000c;
extern s32 data_027e0020;

void func_0202f10c(void) {
    s32 var_ip;
    s32 var_r1;
    void *temp_r3;

    temp_r3 = *data_02137338;
    var_ip = M2C_FIELD(temp_r3, s32 *, 0x38) - M2C_FIELD(data_027e000c, s32 *, 0x38);
    if (var_ip < 0) {
        var_ip = 0 - var_ip;
    }
    var_r1 = M2C_FIELD(temp_r3, s32 *, 0x30) - M2C_FIELD(data_027e000c, s32 *, 0x30);
    if (var_r1 < 0) {
        var_r1 = 0 - var_r1;
    }
    data_027e0020 = var_r1 + var_ip;
    if (M2C_FIELD(data_027e000c, u8 *, 0x92) != 8) {
        M2C_FIELD(data_027e000c, s8 *, 0x93) = 0;
        M2C_FIELD(data_027e000c, s8 *, 0x98) = 7;
    }
    M2C_FIELD(data_027e000c, u8 *, 0x92) = 8U;
    M2C_FIELD(data_027e000c, s8 *, 0x91) = 0;
}
