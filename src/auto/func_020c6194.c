/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_0213b890[];
extern void (*data_02125868[])(void);

void func_020c6194(void) {
    u8 *p;
    u8 *q;

    p                   = *(u8 **) (data_0213b890 + 0x4c);
    *(u8 **) (p + 0xfc) = p + 0x24;
    q                   = *(u8 **) (*(u8 **) (data_0213b890 + 0x4c) + 0xfc);
    if (q[0] != 0) {
        data_02125868[q[1]]();
    }
}
