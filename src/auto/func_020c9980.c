/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213b890[];
extern void (*data_02125b4c[])(void);

void func_020c9980(void) {
    u8 *a;
    u8 *b;

    a = *(u8 **) (data_0213b890 + 0x4c);
    b = *(u8 **) (a + 0x2f8);
    data_02125b4c[b[2]]();
    a                   = *(u8 **) (data_0213b890 + 0x4c);
    b                   = *(u8 **) (a + 0x2f8);
    *(u16 *) (b + 0x2c) = (u16) (*(u16 *) (b + 0x2c) - 0x800);
}
