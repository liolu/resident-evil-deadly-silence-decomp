/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_020876c8(M2C_UNK, M2C_UNK);

extern M2C_UNK data_021375ac;
extern M2C_UNK data_021375e0;
extern M2C_UNK data_021375e4;

s32 func_02087d68(void) {
    M2C_FIELD(&data_021375ac, s8 *, 0x32) = 1;
    M2C_FIELD(&data_021375ac, s8 *, 0x33) = (s8) func_020876c8((s32) &data_021375e0, (s32) &data_021375e4);
    return (s32) M2C_FIELD(&data_021375ac, s8 *, 0x33);
}
