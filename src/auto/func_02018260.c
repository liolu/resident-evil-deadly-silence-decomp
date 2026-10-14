/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02018204(M2C_UNK, u8, M2C_UNK, s32, s32, s32); /* extern */
s32 func_020555a4();                                /* extern */
extern M2C_UNK data_0211bea4;

void func_02018260(s32 arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3, s32 arg4, s32 arg5, u8 arg6) {
    func_02018204(arg1, (u8) ((arg2 & 7) | *((M2C_UNK *)((s8 *)&data_0211bea4 + (func_020555a4() * 4)))), arg3, arg4, arg5, (s32) arg6);
}
