/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e5edc();                            /* extern */
s32 func_020e600c();                                /* extern */
s32 func_020e604c();                                /* extern */
M2C_UNK func_020ece08();                            /* extern */
M2C_UNK func_02103a58(M2C_UNK *);                   /* extern */
extern M2C_UNK data_0215301c;
extern M2C_UNK data_02153054;
extern M2C_UNK data_0215307c;

s32 func_020e5f4c(void) {
    if (func_020e604c() == 0) {
        return 0;
    }
    if ((u32) M2C_FIELD(&data_02153054, u32 *, 0x24) <= 1U) {
        return 0;
    }
    if (func_020e600c() != 0) {
        return 0;
    }
    if (M2C_FIELD(&data_0215301c, s32 *, 0x10) == 0) {
        M2C_FIELD(&data_0215301c, s32 *, 0x10) = 1;
        func_020e5edc();
    }
    func_020ece08();
    func_02103a58(&data_0215307c);
    return 0;
}
