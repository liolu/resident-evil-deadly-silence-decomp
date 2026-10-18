/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020db670();                            /* extern */
M2C_UNK func_020dd470();                            /* extern */
M2C_UNK func_020dd47c();                            /* extern */
M2C_UNK func_020e008c(s32);                         /* extern */
M2C_UNK func_020e7320(s32, M2C_UNK);                /* extern */
M2C_UNK func_020e732c(s32, M2C_UNK);                /* extern */

void func_020e1940(void *arg0) {
    void **temp_r0;

    func_020dd47c();
    func_020e732c(M2C_FIELD(arg0, s32 *, 0xC), 0);
    func_020e7320(M2C_FIELD(arg0, s32 *, 0xC), 0);
    func_020e008c(M2C_FIELD(arg0, s32 *, 4));
    if (M2C_FIELD(arg0, s8 *, 2) == 2) {
        temp_r0 = M2C_FIELD(arg0, void ***, 0x14);
        if (temp_r0 != NULL) {
            M2C_FIELD(arg0, void ***, 0x14) = NULL;
            M2C_FIELD(*temp_r0, M2C_UNK(**)(), 0xC)(temp_r0);
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x74) != 0) {
        func_020db670();
    }
    M2C_FIELD(arg0, void ***, 0x14) = NULL;
    M2C_FIELD(arg0, s8 *, 1)        = 0;
    M2C_FIELD(arg0, s8 *, 0xA8)     = 0;
    func_020dd470();
}
