/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020dea60(M2C_UNK, s32, s32);           /* extern */
M2C_UNK func_02112654(s32, M2C_UNK *, s32);         /* extern */
s32 func_0211282c(s32);                             /* extern */
extern M2C_UNK data_0212fd74;

void func_020de9f4(M2C_UNK arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
    s32 temp_r4;

    func_020dea60(arg0, arg2, arg3);
    func_02112654(arg2, &data_0212fd74, (arg3 - func_0211282c(arg2)) - 1);
    temp_r4 = func_0211282c(arg2);
    func_020dea60(arg1, arg2 + temp_r4, 4 - func_0211282c(arg2));
}
