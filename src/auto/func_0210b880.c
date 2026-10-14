/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_021054ac(void);
void func_021054c0(M2C_UNK);

extern s32 data_0215a898;

s32 func_0210b880(void) {
    s32 temp_r0;

    temp_r0 = func_021054ac();
    if (data_0215a898 != 0) {
        func_021054c0(temp_r0);
        return 0;
    }
    data_0215a898 = 1;
    func_021054c0(temp_r0);
    return 1;
}
