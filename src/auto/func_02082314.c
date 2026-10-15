/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02082348(M2C_UNK);
M2C_UNK func_02082360(M2C_UNK);

s32 func_02082314(s32 arg0) {
    s32 temp_r4;

    temp_r4 = func_02082348(arg0);
    if ((u32) temp_r4 >= (u32) func_02082360(arg0)) {
        return 1;
    }
    return 0;
}
