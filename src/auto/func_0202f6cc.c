/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef void (*Handler)(void);

void func_0202eba8(s32);
extern Handler data_0211c654[];
extern M2C_UNK data_02143cc0;
extern void *data_027e000c;
extern s32 data_027e0018;

void func_0202f6cc(void) {
    s32 temp_r0;
    s32 var_r1;
    s32 var_r3;
    u8 temp_r1;

    var_r3 = M2C_FIELD(&data_02143cc0, s32 *, 0xF7C) - M2C_FIELD(data_027e000c, s32 *, 0x38);
    if (var_r3 < 0) {
        var_r3 = 0 - var_r3;
    }
    var_r1 = M2C_FIELD(&data_02143cc0, s32 *, 0xF74) - M2C_FIELD(data_027e000c, s32 *, 0x30);
    if (var_r1 < 0) {
        var_r1 = 0 - var_r1;
    }
    data_027e0018 = var_r1 + var_r3;
    temp_r1       = M2C_FIELD(data_027e000c, u8 *, 0xA);
    temp_r0       = temp_r1 & 0x10;
    if (temp_r0 != 0) {
        func_0202eba8(temp_r0);
        return;
    }
    data_0211c654[temp_r1 & 0xF]();
}
