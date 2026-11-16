/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_020d1634(void);
typedef void (*Handler)(void);
extern u8 data_0213b890;
extern Handler data_021263d4[];

void func_020d1e00(void) {
    u8 *st;

    st = &data_0213b890;
    data_021263d4[st[0x20]]();
    if (st[0x1e] != 0) {
        func_020d1634();
    }
}
