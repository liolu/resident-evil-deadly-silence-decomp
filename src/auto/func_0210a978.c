/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_021054ac(void);
void func_021054c0(M2C_UNK);
M2C_UNK func_0210a684(void);

extern M2C_UNK data_0215a864;

s32 func_0210a978(s32 arg0, s32 arg1) {
    s32 temp_r0;

    temp_r0 = func_021054ac();
    if (M2C_FIELD(&data_0215a864, s32 *, 0) != 0) {
        func_021054c0(temp_r0);
        return 1;
    }
    M2C_FIELD(&data_0215a864, s32 *, 0) = 1;
    func_021054c0(temp_r0);
    M2C_FIELD(&data_0215a864, s32 *, 4) = arg0;
    M2C_FIELD(&data_0215a864, s32 *, 8) = arg1;
    if (func_0210a684() != 0) {
        return 0;
    }
    return 3;
}
