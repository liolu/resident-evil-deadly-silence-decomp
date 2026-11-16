/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 *data_0213daa8;
extern u8 data_0213ad98[];

s32 func_020b407c(void) {
    u8 *p;
    u8 t;
    u16 flags;

    p             = data_0213daa8;
    t             = p[1];
    flags         = *(u16 *) (p + 2);
    data_0213daa8 = p + 4;
    if (t != 0) {
        return !(*(u16 *) (data_0213ad98 + 0x20) & flags);
    }
    return *(u16 *) (data_0213ad98 + 0x20) & flags;
}
