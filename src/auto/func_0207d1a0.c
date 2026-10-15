/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02082488(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */

void func_0207d1a0(void *arg0) {
    void *temp_r1;

    func_02082488(arg0, 0x11, 0, 0);
    M2C_FIELD(arg0, u8 *, 0xD)     = (u8) (M2C_FIELD(arg0, u8 *, 0xD) & ~0x10);
    M2C_FIELD(arg0, s8 *, 5)       = 0;
    temp_r1                        = M2C_FIELD(arg0, void **, 0);
    M2C_FIELD(temp_r1, u8 *, 0x92) = (u8) (M2C_FIELD(temp_r1, u8 *, 0x92) + 1);
}
