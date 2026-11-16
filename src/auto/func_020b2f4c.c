/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 *data_0213daa8;
extern u8 data_0214838c[];

s32 func_020b2f4c(void) {
    u8 *r4 = data_0213daa8;
    s32 idx;
    u8 *p;

    data_0213daa8      = r4 + 0xA;
    idx                = r4[1] * 12;
    data_0214838c[idx] = r4[2];
    p                  = data_0214838c + idx;
    p[1]               = r4[3];
    *(u16 *) (p + 2)   = *(u16 *) (r4 + 4);
    *(u16 *) (p + 4)   = *(u16 *) (r4 + 6);
    *(u16 *) (p + 6)   = *(u16 *) (r4 + 8);
    return 1;
}
