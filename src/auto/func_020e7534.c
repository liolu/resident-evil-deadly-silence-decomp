/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e7568(M2C_UNK);
void func_020e75b4(M2C_UNK);
M2C_UNK func_020e78cc(M2C_UNK);

void func_020e7534(s32 arg0) {
    if (func_020e78cc(arg0) == 1) {
        func_020e75b4(arg0);
        return;
    }
    func_020e7568(arg0);
}
