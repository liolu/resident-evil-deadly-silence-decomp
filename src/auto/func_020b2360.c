/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 *data_0213daa8;
extern u8 data_0213bdcc[];

s32 func_020b2360(void) {
    u8 t;
    s32 i;
    u8 *p;

    i             = 0;
    p             = data_0213daa8;
    t             = p[1];
    data_0213daa8 = p + 2;
    goto check;
loop:
    if (t == data_0213bdcc[i * 2 + 0x100]) {
        return 1;
    }
    i += 1;
check:
    if (i < 0x30) {
        goto loop;
    }
    return 0;
}
