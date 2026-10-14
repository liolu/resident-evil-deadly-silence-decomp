/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_01ffc2b4(M2C_UNK);                     /* extern */
M2C_UNK func_0200d6d0(M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
extern M2C_UNK data_0213af7c;

void func_020b8210(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, s32 arg3) {
    func_01ffc2b4(arg2);
    func_0200d6d0(arg0, arg1, 0, 0x11004, 0, 0, (s32) M2C_FIELD(&data_0213af7c, s16 *, 0x40), 0, (s32) (s8) M2C_FIELD(&data_0213af7c, s16 *, 0x3E), arg3, 0);
}
