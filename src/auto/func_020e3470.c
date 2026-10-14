/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_020e3400(M2C_UNK);
void func_020e4254(void);
void func_020e4260(void);

s32 func_020e3470(s32 arg0) {
    s32 temp_r4;

    func_020e4260();
    temp_r4 = func_020e3400(arg0);
    func_020e4254();
    return temp_r4;
}
