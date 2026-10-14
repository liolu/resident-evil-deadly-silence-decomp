/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e40e4(M2C_UNK *, M2C_UNK *);        /* extern */
extern M2C_UNK data_02130548;
extern M2C_UNK data_02130554;
extern M2C_UNK data_02130570;
extern M2C_UNK data_0213057c;

void func_020e3d48(void *arg0, s32 arg1, s32 arg2) {
    if (arg0 == NULL) {
        func_020e40e4(&data_02130548, &data_02130554);
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 4) != 0) {
        M2C_FIELD(arg0, s32 *, 0x38) = arg1;
        M2C_FIELD(arg0, s32 *, 0x3C) = arg2;
        return;
    }
    func_020e40e4(&data_02130570, &data_0213057c);
}
