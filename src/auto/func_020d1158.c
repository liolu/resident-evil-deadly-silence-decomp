/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_0213b890;

M2C_UNK func_020d0cbc();

void func_020d1158(void) {
    u8 *p;

    p = *(u8 **) (&data_0213b890 + 0x4c);
    switch (p[0x42]) {
        case 0:
            p[0x40] = 3;
            func_020d0cbc();
            p       = *(u8 **) (&data_0213b890 + 0x4c);
            p[0x42] = 1;
            break;
        case 1:
            break;
    }
}
