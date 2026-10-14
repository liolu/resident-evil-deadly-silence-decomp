/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_01ffc2b4(M2C_UNK);                     /* extern */
M2C_UNK func_020b7718(M2C_UNK, u8);                 /* extern */
M2C_UNK func_020b7764(M2C_UNK, u8);                 /* extern */
extern M2C_UNK data_0213af7c;

void func_020b76d4(M2C_UNK arg0, M2C_UNK arg1) {
    func_01ffc2b4(arg1);
    func_020b7764(arg0, (u8) M2C_FIELD(&data_0213af7c, s16 *, 0x40));
    func_020b7718(arg0, (u8) M2C_FIELD(&data_0213af7c, s16 *, 0x3E));
}
