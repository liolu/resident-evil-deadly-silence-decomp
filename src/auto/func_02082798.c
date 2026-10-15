/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020915fc();                             /* extern */
M2C_UNK func_02091604();                     /* extern */

void func_02082798(void *arg0) {
    s8 var_r1;
    void *temp_r1;

    var_r1 = func_020915fc(M2C_FIELD(arg0, void **, 0) + 0x54) - 1;
    if ((s32) var_r1 < 0) {
        var_r1 = 0;
    }
    func_02091604(M2C_FIELD(arg0, void **, 0) + 0x54, (u8) var_r1);
    M2C_FIELD(arg0, u8 *, 0x17) = (u8) (M2C_FIELD(arg0, u8 *, 0x17) - 1);
    if ((u32) M2C_FIELD(arg0, u8 *, 0x17) <= 1U) {
        temp_r1                        = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
    }
}
