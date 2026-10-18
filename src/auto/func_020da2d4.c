/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020d9f84(s32, s32);                    /* extern */
extern s32 data_0214e640;

void func_020da2d4(void *arg0) {
    void **temp_r0;

    if (M2C_FIELD(arg0, void ***, 8) == NULL) {
        return;
    }
    if (M2C_FIELD(arg0, s8 *, 2) != 0) {
        return;
    }
    if (data_0214e640 == 1) {
        func_020d9f84(M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, s32 *, 0x28));
    }
    temp_r0                      = M2C_FIELD(arg0, void ***, 8);
    M2C_FIELD(arg0, void ***, 8) = NULL;
    M2C_FIELD(*temp_r0, M2C_UNK(**)(), 0xC)(temp_r0);
}
