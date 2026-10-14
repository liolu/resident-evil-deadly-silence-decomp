/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020f2834(M2C_UNK *, M2C_UNK);          /* extern */
s32 func_021054ac();                                /* extern */
M2C_UNK func_021054c0(s32);                         /* extern */
extern M2C_UNK data_02157d60;

void func_020fd82c(M2C_UNK arg0) {
    s32 temp_r4;

    temp_r4 = func_021054ac();
    func_020f2834(&data_02157d60, arg0);
    func_021054c0(temp_r4);
}
