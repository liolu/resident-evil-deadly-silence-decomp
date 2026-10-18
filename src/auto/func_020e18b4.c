/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020deb88(M2C_UNK *);                   /* extern */
M2C_UNK func_020e0e98();                            /* extern */
M2C_UNK func_020e1940(void *);                      /* extern */
M2C_UNK func_020e6950(s32);                         /* extern */
extern M2C_UNK data_021300a0;

void func_020e18b4(void *arg0) {
    void **temp_r0;

    if (arg0 == NULL) {
        func_020deb88(&data_021300a0);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 8) != 0) {
        func_020e0e98();
    }
    if (M2C_FIELD(arg0, s8 *, 2) == 4) {
        func_020e6950(M2C_FIELD(arg0, s32 *, 0x94));
        temp_r0 = M2C_FIELD(arg0, void ***, 0x14);
        if (temp_r0 != NULL) {
            M2C_FIELD(*temp_r0, M2C_UNK(**)(), 0x14)(temp_r0);
        }
    }
    func_020e1940(arg0);
}
