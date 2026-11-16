/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern M2C_UNK data_0213daa8;

u32 func_02058680(s32 arg0) {
    u8 *p;
    u8 i;

    i = 0;
    goto check;
body:
    p = (u8 *) &data_0213daa8 + i * 0x38;
    if (arg0 == p[0xB0] && p[0x7E] != 0) {
        return i;
    }
    i = i + 1;
check:
    if (i < 8) {
        goto body;
    }
    return 8;
}
