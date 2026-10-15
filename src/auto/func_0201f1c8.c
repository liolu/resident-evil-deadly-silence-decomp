/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020abd88(M2C_UNK);                     /* extern */
M2C_UNK func_020adad0(s32);                         /* extern */

void func_0201f1c8(void *arg0) {
    M2C_FIELD(arg0, u8 *, 0x93)  = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + 1);
    M2C_FIELD(arg0, s8 *, 0xA1)  = 2;
    M2C_FIELD(arg0, s8 *, 0xA2)  = 0;
    M2C_FIELD(arg0, s8 *, 0xA3)  = 0;
    M2C_FIELD(arg0, s8 *, 0x98)  = 3;
    M2C_FIELD(arg0, s16 *, 0xA6) = 0;
    func_020adad0(0x8060);
    func_020abd88(0);
}
