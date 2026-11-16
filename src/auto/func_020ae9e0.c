/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_0213ad98;
extern void (*data_02122394[])(void);

void func_020ae9e0(void) {
    u8 idx;

    idx = data_0213ad98;
    if (idx <= 6) {
        data_02122394[idx]();
    }
}
