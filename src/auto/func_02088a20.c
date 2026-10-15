/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020f3224(M2C_UNK *, s32);              /* extern */
extern M2C_UNK data_021375ac;
extern M2C_UNK data_0213b3ac;

void func_02088a20(void) {
    func_020f3224(&data_0213b3ac, M2C_FIELD(&data_021375ac, s32 *, 0x64));
    M2C_FIELD(&data_021375ac, s32 *, 0x64) = 0;
    M2C_FIELD(&data_021375ac, s8 *, 0)     = 0;
}
