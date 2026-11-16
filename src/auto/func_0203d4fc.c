/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void);
extern u8 *data_027e000c;
extern s32 data_027e0018;
extern Fn data_0211c9e4[];
extern u8 data_02143cc0[];

void func_0203d4fc(void) {
    s32 var_r1;
    s32 var_r3;

    var_r3 = *(s32 *) (data_02143cc0 + 0xF7C) - *(s32 *) (data_027e000c + 0x38);
    if (var_r3 < 0) {
        var_r3 = 0 - var_r3;
    }
    var_r1 = *(s32 *) (data_02143cc0 + 0xF74) - *(s32 *) (data_027e000c + 0x30);
    if (var_r1 < 0) {
        var_r1 = 0 - var_r1;
    }
    data_027e0018 = var_r1 + var_r3;
    data_0211c9e4[data_027e000c[10]]();
}
