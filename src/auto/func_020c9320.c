/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213b890[];
extern void (*data_02125b24[])(void);

void func_020c9320(void) {
    u8 *p;

    p = *(u8 **) (data_0213b890 + 0x4C);
    p = *(u8 **) (p + 0x2F8);
    data_02125b24[p[2]]();
}
