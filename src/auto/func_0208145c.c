/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02082488(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_0208145c(void *arg0) {
    M2C_UNK var_r1;
    void *temp_r1;

    if (M2C_FIELD(arg0, s32 *, 0x1CC) != 0) {
        M2C_FIELD(arg0, s32 *, 0x1CC) = 0;
        var_r1                        = 0x1F;
    } else {
        var_r1 = 0x1E;
    }
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0xA1) != 2) {
        func_02082488(arg0, var_r1, 0, 0);
    }
    M2C_FIELD(arg0, s32 *, 0x1C8)  = 0xE;
    M2C_FIELD(arg0, s32 *, 0x1D0)  = 0;
    temp_r1                        = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
}
