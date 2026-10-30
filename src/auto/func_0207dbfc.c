/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0207da14();                            /* extern */
M2C_UNK func_020823b4(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_0207dbfc(void *arg0) {
    void *temp_r1;
    void *temp_r1_2;

    func_0207da14();
    temp_r1 = M2C_FIELD(arg0, void **, 0);
    if ((s32) M2C_FIELD(temp_r1, s32 *, 0x34) >= 0) {
        M2C_FIELD(temp_r1, s32 *, 0x34) = 0;
        func_020823b4(arg0, 0x15, 0, 0);
        M2C_FIELD(arg0, u8 *, 5)         = (u8) (M2C_FIELD(arg0, u8 *, 5) & ~8);
        temp_r1_2                        = M2C_FIELD(arg0, void **, 0);
        M2C_FIELD(temp_r1_2, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1_2, u8 *, 0x92) + 1);
    }
}
