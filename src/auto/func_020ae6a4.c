/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_0207979c(u32 id);
extern u8 data_0213ad98[];

void func_020ae6a4(void) {
    u32 sel = data_0213ad98[1] - 0xC;

    switch (sel) {
        case 0:
            func_0207979c(0x14);
            break;
        case 2:
            func_0207979c(0x25);
        /* fall through */
        case 1:
        case 3:
            func_0207979c(0x17);
            break;
        case 5:
            func_0207979c(0xA);
            func_0207979c(0x17);
            break;
        default:
            break;
    }
}
