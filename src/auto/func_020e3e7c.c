/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e40e4(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_0211035c(void *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK data_021305f0;
extern M2C_UNK data_021305fc;
extern M2C_UNK data_02130618;
extern M2C_UNK data_02130624;

void func_020e3e7c(void *arg0) {
    if (arg0 == NULL) {
        func_020e40e4(&data_021305f0, &data_021305fc);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 4) == 0) {
        func_020e40e4(&data_02130618, &data_02130624);
        return;
    }
    func_0211035c(arg0, 0, 0x40);
    M2C_FIELD(arg0, s32 *, 4) = 0;
}
