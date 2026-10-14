/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_020f356c(void **arg0, void **arg1, s32 arg2, s32 arg3) {
    void *temp_lr;
    void *temp_r1;

    temp_lr = *arg1;
    if (temp_lr != NULL) {
        *arg1 = M2C_FIELD(temp_lr, void **, 0xC);
    }
    if (temp_lr != NULL) {
        M2C_FIELD(temp_lr, s32 *, 0) = arg2;
        M2C_FIELD(temp_lr, s32 *, 4) = arg3;
        M2C_FIELD(temp_lr, s32 *, 8) = 0;
        M2C_FIELD(temp_lr, void **, 0xC) = NULL;
        temp_r1 = *arg0;
        if (temp_r1 != NULL) {
            M2C_FIELD(temp_r1, void **, 8) = temp_lr;
        }
        M2C_FIELD(temp_lr, void **, 0xC) = (void *) *arg0;
        M2C_FIELD(temp_lr, s32 *, 8) = 0;
        *arg0 = temp_lr;
        return 1;
    }
    return 0;
}
