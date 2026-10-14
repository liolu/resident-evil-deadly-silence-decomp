/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e451c(void);

extern s32 data_0215257c;

void func_020e44e0(void) {
    if (data_0215257c == 0) {
        func_020e451c();
    }
    data_0215257c += 1;
}
