/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213d1c0[];
extern u8 data_0213d634[];

u16 func_02006514(s32 arg0) {
    s32 t;
    u8 *base;

    t = (arg0 >> 7) & 1;
    if (t == 0) {
        base = data_0213d1c0;
    } else {
        base = data_0213d634;
    }
    return *(u16 *) (base + ((arg0 & 0xF) * 8) + 8);
}
