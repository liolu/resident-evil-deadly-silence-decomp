/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_021054ac(void);
void func_021054c0(M2C_UNK);

extern s32 data_02158c00;
extern s32 data_02158c04;

void func_0210702c(s32 arg0) {
    s32 temp_r0;

    temp_r0 = func_021054ac();
    if (data_02158c04 == 0) {
        data_02158c04 = arg0;
        data_02158c00 = arg0;
    } else {
        *(M2C_UNK *) data_02158c04 = arg0;
        data_02158c04              = arg0;
    }
    *(M2C_UNK *) arg0 = 0;
    func_021054c0(temp_r0);
}
