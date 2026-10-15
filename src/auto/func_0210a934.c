/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0210a65c(void);
void func_0210a674(M2C_UNK);
M2C_UNK func_0210a978(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0215a864;

s32 func_0210a934(void) {
    s32 temp_r0;

    temp_r0                               = func_0210a978((s32) func_0210a674, 0);
    M2C_FIELD(&data_0215a864, s32 *, 0xC) = temp_r0;
    if (temp_r0 == 0) {
        func_0210a65c();
    }
    return M2C_FIELD(&data_0215a864, s32 *, 0xC);
}
