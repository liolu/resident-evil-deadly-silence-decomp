/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_021102f0(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0212fcc4;
extern M2C_UNK data_0212fccc;

s32 func_020db374(s32 arg0) {
    if ((func_021102f0(arg0, (s32) &data_0212fcc4, 4) == 0) || (func_021102f0(arg0, (s32) &data_0212fccc, 4) == 0)) {
        return 1;
    }
    return 0;
}
