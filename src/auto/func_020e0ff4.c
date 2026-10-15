/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020e038c(void);
void func_020e0398(void);
M2C_UNK func_020e0fa8(M2C_UNK, M2C_UNK);

s32 func_020e0ff4(s32 arg0, s32 arg1) {
    s32 temp_r4;

    func_020e0398();
    temp_r4 = func_020e0fa8(arg0, arg1);
    func_020e038c();
    return temp_r4;
}
