/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020e038c(void);
void func_020e0398(void);
M2C_UNK func_020e0d50(M2C_UNK);

s32 func_020e0d64(s32 arg0) {
    s32 temp_r4;

    func_020e0398();
    temp_r4 = func_020e0d50(arg0);
    func_020e038c();
    return temp_r4;
}
