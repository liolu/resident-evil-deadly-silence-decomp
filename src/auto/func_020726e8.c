/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

u8 *func_0209563c(u8);
extern u8 data_0213caa0[];
extern u8 data_0213d1a0[];

s32 func_020726e8(void) {
    u32 i;
    u8 *t;

    i = 0;
    while (i < 4) {
        if (i != data_0213caa0[0x706] && (*(u16 *) (data_0213d1a0 + 0x18) & (1 << i))) {
            t = func_0209563c((u8) i);
            if (t != NULL && (((u32) (t[0x14] << 0x1B)) >> 0x1F) == 0) {
                return 0;
            }
        }
        i += 1;
    }
    return 1;
}
