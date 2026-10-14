/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020e6950();                            /* extern */
M2C_UNK func_020e6dc0(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02130ea8;

void func_020e6970(void *arg0) {
    if (arg0 == NULL) {
        func_020e6dc0(&data_02130ea8);
        return;
    }
    if (M2C_FIELD(arg0, s8 *, 1) != 0) {
        func_020e6950(arg0);
    }
    if ((s32) M2C_FIELD(arg0, s32 *, 0x24) > 0) {
        M2C_FIELD(arg0, s8 *, 1) = 2;
        return;
    }
    M2C_FIELD(arg0, s8 *, 1) = 1;
}
