/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_0213af7c[];
extern u8 data_0213afde[];

void func_020b6e8c(s8 arg0) {
    u32 i;
    u8 v;

    i = 0;
    goto cond;
body:
    v = *(u8 *) (data_0213af7c + i + 0x62);
    if (arg0 == v) {
        return;
    }
    if (v == 0) {
        data_0213afde[i] = arg0;
        return;
    }
    i++;
cond:
    if (i < 12) {
        goto body;
    }
}
