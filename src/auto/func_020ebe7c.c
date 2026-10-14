/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020ebdf8(void);

extern s32 data_0215432c;

void func_020ebe7c(void) {
    if (data_0215432c == 0) {
        func_020ebdf8();
    }
    data_0215432c += 1;
}
