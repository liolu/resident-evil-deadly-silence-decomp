/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020ded0c(void);
void func_020e0c98(M2C_UNK);

void func_020e0bf4(s32 arg0) {
    func_020e0c98(arg0);
    do {
    loop_1:
        func_020ded0c();
        if (M2C_FIELD(arg0, s8 *, 1) != 1) {
            goto loop_1;
        }
    } while (M2C_FIELD(arg0, s32 *, 0x24) != 0);
}
