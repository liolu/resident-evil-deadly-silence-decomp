#include "engine.h"
#include "m2c.h"

void func_020fd1ec(M2C_UNK);

void func_020e8b24(s32 arg0) {
    if (arg0 == 0) {
    loop_1:
        goto loop_1;
    }
    func_020fd1ec(arg0 + 0x24);
}
