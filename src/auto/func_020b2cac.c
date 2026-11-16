/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 *data_0213daa8;
extern u8 *data_0214d068[];

s32 func_020b2cac(void) {
    u8 *q;
    u8 *p;
    u8 b1;
    u8 b2;

    p             = data_0213daa8;
    b1            = p[1];
    b2            = p[2];
    data_0213daa8 = p + 4;
    q             = data_0214d068[b1];
    q[8]          = b2;
    return 1;
}
