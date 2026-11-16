/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_02147cc0;
extern u8 data_0211dcfc;

s32 func_02074ef0(u8 arg0);

void func_020a9c90(void) {
    u8 r4;
    s32 lr;
    u8 ip;
    s32 r0;
    s32 r2;
    u8 *ent;

    r4 = (*(u8 **) ((u8 *) &data_02147cc0 + 0x53c))[0];
    if (r4 == 4) {
        r4 = 2;
    }
    r0 = func_02074ef0((u8) (r4 + 9));
    if (r0 < 0) {
        return;
    }
    ip = (*(u8 **) ((u8 *) &data_02147cc0 + 0x53c))[1];
    r2 = (&data_0211dcfc)[r4 * 4] - ip;
    if (r2 < 0) {
        return;
    }
    ent = *(u8 **) ((u8 *) &data_02147cc0 + 0x538) + r0 * 2;
    lr  = ent[1];
    if (r2 > lr) {
        r2 = lr;
    }
    lr                                            = lr - r2;
    (*(u8 **) ((u8 *) &data_02147cc0 + 0x53c))[1] = ip + r2;
    if (lr <= 0) {
        ent[0] = 0;
    }
    ent[1] = lr;
}
