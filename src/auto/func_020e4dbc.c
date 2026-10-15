/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e4a9c();                            /* extern */
M2C_UNK func_020e4aac();                            /* extern */
M2C_UNK func_020e543c(void *, M2C_UNK *);           /* extern */
extern M2C_UNK data_021308c8;
extern M2C_UNK data_021308e0;
extern M2C_UNK data_02130904;

s32 func_020e4dbc(void *arg0, s32 arg1, s32 arg2) {
    if (arg0 == NULL) {
        func_020e543c(NULL, &data_021308c8);
        return 0;
    }
    if (arg1 < 0) {
        func_020e543c(arg0, &data_021308e0);
        return 0;
    }
    if (arg2 == 0) {
        func_020e543c(arg0, &data_02130904);
        return 0;
    }
    if ((M2C_FIELD(arg0, s32 *, 0x6C) == 1) || (M2C_FIELD(arg0, s32 *, 0x70) == 1)) {
        return 0;
    }
    if (arg1 == 0) {
        M2C_FIELD(arg0, s8 *, 1) = 1;
        return 0;
    }
    func_020e4aac();
    M2C_FIELD(arg0, s32 *, 0x60) = arg1;
    M2C_FIELD(arg0, s32 *, 0x68) = (s32) (M2C_FIELD(arg0, s32 *, 0x60) * M2C_FIELD(arg0, s32 *, 0x4C));
    M2C_FIELD(arg0, s32 *, 0x6C) = 1;
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    M2C_FIELD(arg0, s32 *, 0x48) = arg2;
    M2C_FIELD(arg0, s8 *, 1)     = 2;
    func_020e4a9c();
    return M2C_FIELD(arg0, s32 *, 0x60);
}
