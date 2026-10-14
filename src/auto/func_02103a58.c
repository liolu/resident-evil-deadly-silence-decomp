/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02103940(void);
M2C_UNK func_021054ac(void);
void func_021054c0(M2C_UNK);

void func_02103a58(s32 arg0) {
    s32 temp_r4;

    temp_r4 = func_021054ac();
    M2C_FIELD(arg0, s32 *, 0x64) = 1;
    func_02103940();
    func_021054c0(temp_r4);
}
