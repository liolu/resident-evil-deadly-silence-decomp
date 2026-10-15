/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_021054ac(void);
void func_021054c0(M2C_UNK);
M2C_UNK func_0210d918(void);
M2C_UNK func_0210d934(void);

s32 func_0210e120(s32 arg0) {
    s32 temp_r0;
    s32 temp_r5;

    temp_r5 = func_021054ac();
    temp_r0 = func_0210d918();
    if (temp_r0 != 0) {
        func_021054c0(temp_r5);
        return temp_r0;
    }
    M2C_FIELD((void *) func_0210d934(), s32 *, 0xBC) = arg0;
    func_021054c0(temp_r5);
    return 0;
}
