/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef void (*Handler)(void);
extern u8 data_0213ad84;
extern u8 data_0213b890;
extern Handler data_02124f14[];

void func_020c1558(void) {
    u8 *st;
    u8 k;

    if (data_0213ad84 == 0) {
        st = &data_0213b890;
        k  = st[0x1d];
        data_02124f14[k]();
    }
}
