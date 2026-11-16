/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213b890[];

void *func_020c8da8(void) {
    u8 i;
    u8 *p;

    i = 0;
    p = *(u8 **) (data_0213b890 + 0x4C) + 0x148;
    goto check;
loop:
    if (p[0] == 0) {
        p[0] = 1;
        p[2] = 0;
        return p;
    }
    p += 0x30;
    i = (u8) (i + 1);
check:
    if (i < 9) {
        goto loop;
    }
    return NULL;
}
