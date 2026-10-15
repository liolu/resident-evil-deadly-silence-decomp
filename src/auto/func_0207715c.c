/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02070438(M2C_UNK);

void func_0207715c(s32 arg0) {
    s32 temp_r0;

    temp_r0 = M2C_FIELD(arg0, s32 *, 4);
    if (temp_r0 != 0) {
        func_02070438(temp_r0);
    }
    M2C_FIELD(arg0, s16 *, 0) = 0;
    M2C_FIELD(arg0, s8 *, 3)  = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
}
