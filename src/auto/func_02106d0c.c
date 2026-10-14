/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_021054ac(void);
void func_021054c0(M2C_UNK);

extern s32 data_02158bfc;
extern s32 data_02158c00;
extern s32 data_02158c18;

s32 func_02106d0c(void) {
    s32 temp_r0;
    s32 var_r4;

    temp_r0 = func_021054ac();
    if (data_02158c00 == 0) {
        var_r4 = data_02158bfc;
    } else {
        var_r4 = data_02158c18;
    }
    func_021054c0(temp_r0);
    return var_r4;
}
