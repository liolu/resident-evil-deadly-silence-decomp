/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02103a8c(M2C_UNK);
M2C_UNK func_02104460(M2C_UNK);

void func_021044d0(s32 arg0) {
    void *temp_r0;

    if (M2C_FIELD(arg0, s32 *, 0x7C) == 0) {
        return;
    }
    do {
        temp_r0                      = (void *) func_02104460(arg0);
        M2C_FIELD(temp_r0, s32 *, 8) = 0;
        M2C_FIELD(temp_r0, s32 *, 4) = 0;
        func_02103a8c((s32) temp_r0);
    } while (M2C_FIELD(arg0, s32 *, 0x7C) != 0);
}
