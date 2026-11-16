/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_02143cc0[];
extern u8 data_0214bcc0[];

void func_020a0658(u32 arg0) {
    u32 i;
    u8 *e;

    for (i = 0; i < *(u8 *) M2C_FIELD(data_0214bcc0, u8 **, 0x7AC); i++) {
        e = &data_02143cc0[i * 0x38];
        if (arg0 == e[0xA9]) {
            e[0xA8] = 0;
        }
    }
}
