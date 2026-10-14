/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e6dc0(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02130ed4;

void func_020e69e0(void *arg0) {
    if (arg0 == NULL) {
        func_020e6dc0(&data_02130ed4);
        return;
    }
    if (M2C_FIELD(arg0, s8 *, 1) == 0) {
        M2C_FIELD(arg0, s32 *, 0x1C) = 0;
        M2C_FIELD(arg0, s32 *, 0x20) = 0;
        M2C_FIELD(arg0, s32 *, 0x24) = 0;
    }
}
