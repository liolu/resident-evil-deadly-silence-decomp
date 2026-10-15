/* compiler: 1.2/sp2p3  */
#include "m2c.h"

extern M2C_UNK data_0213ad48;

s32 func_02018870(void *arg0, u32 arg1) {
    s32 var_r3;
    u8 temp_r2;

    var_r3 = 0;
    if ((M2C_FIELD(arg0, u8 *, 0x90) == 1) &&
        (((M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) && (M2C_FIELD(arg0, u8 *, 0x169) & 1)) ||
         (M2C_FIELD(arg0, u8 *, 0x16B) == 2))) {
        temp_r2 = M2C_FIELD(arg0, u8 *, 0xA2);
        if ((u32) temp_r2 >= arg1) {
            if ((s32) temp_r2 <= (s32) (arg1 + 2)) {
                var_r3 = 1;
            }
        }
    } else if (M2C_FIELD(arg0, u8 *, 0xA2) == arg1) {
        var_r3 = 1;
    }
    return var_r3;
}
