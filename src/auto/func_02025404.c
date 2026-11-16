/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_0211c3d8;
extern M2C_UNK data_02143cc0;
extern void *data_027e000c;
extern s32 data_027e0018;

void func_02025404(void) {
    s32 var_r1;
    s32 var_r3;

    var_r3 = M2C_FIELD(&data_02143cc0, s32 *, 0xF7C) - M2C_FIELD(data_027e000c, s32 *, 0x38);
    if (var_r3 < 0) {
        var_r3 = 0 - var_r3;
    }
    var_r1 = M2C_FIELD(&data_02143cc0, s32 *, 0xF74) - M2C_FIELD(data_027e000c, s32 *, 0x30);
    if (var_r1 < 0) {
        var_r1 = 0 - var_r1;
    }
    data_027e0018 = var_r1 + var_r3;
    (*(void (**)(void))((u8 *) &data_0211c3d8 + (M2C_FIELD(data_027e000c, u8 *, 0xA) * 4)))();
}
