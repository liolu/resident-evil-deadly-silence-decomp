/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_021054ac(void);
void func_021054c0(M2C_UNK);

extern u32 data_02158bfc;

s32 func_02106cb8(s32 arg0) {
    s32 temp_r0;
    s32 var_r4;

    temp_r0 = func_021054ac();
    if ((u32) arg0 > (u32) data_02158bfc) {
        if ((u32) (arg0 - data_02158bfc) < 0x80000000U) {
            var_r4 = 0;
        } else {
            var_r4 = 1;
        }
    } else if ((u32) (data_02158bfc - arg0) < 0x80000000U) {
        var_r4 = 1;
    } else {
        var_r4 = 0;
    }
    func_021054c0(temp_r0);
    return var_r4;
}
