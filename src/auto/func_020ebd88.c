/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0211035c(void *, M2C_UNK, M2C_UNK);    /* extern */
extern s32 data_02154324;
extern s32 data_02154330;

void *func_020ebd88(void *arg0, M2C_UNK arg1) {
    func_0211035c(arg0, 0, arg1);
    M2C_FIELD(arg0, s32 *, 8) = 0x40;
    M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 8);
    M2C_FIELD(arg0, s32 *, 0x10) = (s32) data_02154324;
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) data_02154330;
    M2C_FIELD(arg0, s8 *, 0) = 1;
    return arg0;
}
