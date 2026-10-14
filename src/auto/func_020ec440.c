/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e9e80(void);

extern s32 data_02154334;

void func_020ec440(void) {
    if (data_02154334 == 1) {
        func_020e9e80();
    }
    data_02154334 -= 1;
}
