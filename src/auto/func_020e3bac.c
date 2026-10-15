/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e40e4(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK data_021304a0;
extern M2C_UNK data_021304ac;
extern M2C_UNK data_021304c8;
extern M2C_UNK data_021304d4;

s32 func_020e3bac(void *arg0, s32 arg1) {
    M2C_UNK (*temp_r2)(s32, M2C_UNK);

    if (arg0 == NULL) {
        func_020e40e4(&data_021304a0, &data_021304ac);
        return 0;
    }
    if (M2C_FIELD(arg0, s32 *, 4) == 0) {
        func_020e40e4(&data_021304c8, &data_021304d4);
        return 0;
    }
    if (arg1 == 1) {
        return M2C_FIELD(arg0, s32 *, 0xC);
    }
    if (arg1 == 0) {
        return M2C_FIELD(arg0, s32 *, 0x10);
    }
    temp_r2 = M2C_FIELD(arg0, M2C_UNK(**)(s32, M2C_UNK), 0x38);
    if (temp_r2 != NULL) {
        temp_r2(M2C_FIELD(arg0, s32 *, 0x3C), -3);
    }
    return 0;
}
