/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0214d068;
extern M2C_UNK data_0214dbec;

s32 func_020b1ed8(void *arg0, void *arg1) {
    if (M2C_FIELD(arg0, u8 *, 1) == 0) {
        M2C_FIELD(arg1, s32 *, 4) = (s32) * ((M2C_UNK *) ((s8 *) &data_0214dbec + (M2C_FIELD(arg0, u8 *, 2) * 4)));
    } else {
        M2C_FIELD(arg1, s32 *, 4) = (s32) * ((M2C_UNK *) ((s8 *) &data_0214d068 + (M2C_FIELD(arg0, u8 *, 2) * 4)));
    }
    return 4;
}
