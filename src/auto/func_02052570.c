#include "engine.h"
#include "m2c.h"

void func_020559cc(M2C_UNK, M2C_UNK);

extern void *data_027e000c;

void func_02052570(void) {
    s8 var_r2;

    M2C_FIELD(data_027e000c, u8 *, 0x91)  = (u8) (M2C_FIELD(data_027e000c, u8 *, 0x91) + 1);
    M2C_FIELD(data_027e000c, s16 *, 0xA8) = 0xA0;
    if (M2C_FIELD(data_027e000c, u8 *, 0xA1) == 0) {
        var_r2 = 0;
    } else {
        var_r2 = 7;
    }
    M2C_FIELD(data_027e000c, s8 *, 0x98) = var_r2;
    M2C_FIELD(data_027e000c, s8 *, 0xA2) = 0;
    M2C_FIELD(data_027e000c, s8 *, 0xA3) = 0;
    func_020559cc((s32) data_027e000c, 0);
}
