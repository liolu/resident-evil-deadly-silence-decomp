/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020ebe7c(void);

extern s32 data_0215411c;

void func_020e9eb8(void) {
    if (data_0215411c == 0) {
        func_020ebe7c();
    }
    data_0215411c += 1;
}
