/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020dd468(void);
void func_020dd46c(void);
M2C_UNK func_020e1da4(M2C_UNK, M2C_UNK, M2C_UNK);

s32 func_020e2120(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r4;

    func_020dd46c();
    temp_r4 = func_020e1da4(arg0, arg1, arg2);
    func_020dd468();
    return temp_r4;
}
