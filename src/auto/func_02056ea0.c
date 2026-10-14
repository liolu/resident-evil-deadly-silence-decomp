/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_020b54b0(void);

void func_02056ea0(s32 arg0, s32 arg1) {
    void *temp_r0;

    temp_r0 = (void *) func_020b54b0();
    M2C_FIELD(temp_r0, s8 *, 0) = (s8) arg1;
    M2C_FIELD(temp_r0, s32 *, 8) = (s32) M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(temp_r0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 4);
}
