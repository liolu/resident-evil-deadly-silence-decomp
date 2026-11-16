/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_0213b890;

M2C_UNK func_020cffb0(void *, s32);

void func_020d0050(u8 *arg0) {
    switch (arg0[3]) {
        case 0:
            arg0[0]                = 1;
            (&data_0213b890)[0x1f] = (&data_0213b890)[0x1f] + 1;
            arg0[3]                = 1;
            func_020cffb0(arg0, 5);
            break;
        case 1:
            break;
    }
}
